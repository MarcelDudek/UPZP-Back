#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE

#include "client_communication/inc/client_communication.h"
#include "game_logic/inc/game_logic.h"
#include "datagram/inc/datagram.h"
#include "sub_process_settings.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Load client from std input.
 * @param comm Reference to client communication, where loaded client will be added.
*/
void LoadClient(upzp::client_com::ClientCommunication& comm, upzp::game_logic::GameLogic& game_logic) {
  // load client's IPv4 address
  std::string client_address;
  std::cout << "Add new client (example input 127.0.0.1:9000): ";
  std::cin >> client_address;

  // get address and port from a string
  std::string ip = client_address.substr(0, client_address.find_first_of(':'));
  std::string port_str = client_address.substr(client_address.find_first_of(':') + 1);
  int port = std::stoi(port_str);

  // load client name
  std::string name;
  std::cout << "Client name: ";
  std::cin >> name;

  // load client id
  uint32_t id;
  std::cout << "Client ID: ";
  std::cin >> id;

  // load to which team
  bool to_red_team;
  std::cout << "Add to red team (1/0): ";
  std::cin >> to_red_team;

  upzp::Client client(name, id++, upzp::VehicleType::CAR, ip, port);
  comm.AddClient(client);
  game_logic.AddPlayer(client, to_red_team);
}

/**
 * @brief Main function.
 * @param argc 
 * @param argv 
 * @return err_code
*/
int main(int argc, char* argv[]) {
  upzp::SubProcessSettings settings(argc, argv);

  // create game logic object
  auto game_logic = std::make_shared<upzp::game_logic::GameLogic>();
  game_logic->NewGame(
      {settings.start_point_longitude, settings.start_point_latitude},
      settings.map_radius, settings.map_name, settings.game_id, settings.points_to_win,
      settings.point_box_spawn_period);

  // create client communication object
  std::unique_ptr<upzp::client_com::ClientCommunication> client_comm;
  try {
    client_comm = std::make_unique<upzp::client_com::ClientCommunication>(settings.udp_port);
    client_comm->AssignGameLogic(game_logic);
    game_logic->StartGame();  // start game logic thread
    client_comm->Start();  // start client communication thread
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  // loop to keep application alive
  while (game_logic->Running()) {
    LoadClient(*client_comm, *game_logic);
    //using namespace std::chrono_literals;
    //std::this_thread::sleep_for(5min);
  }
  // TODO add exit logic
}
