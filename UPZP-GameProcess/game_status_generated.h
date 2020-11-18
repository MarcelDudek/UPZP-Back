// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GAMESTATUS_UPZP_GAMESTATUS_H_
#define FLATBUFFERS_GENERATED_GAMESTATUS_UPZP_GAMESTATUS_H_

#include "flatbuffers/flatbuffers.h"

namespace Upzp {
namespace GameStatus {

struct Position;

struct Player;
struct PlayerBuilder;

struct Team;
struct TeamBuilder;

struct PointBox;
struct PointBoxBuilder;

struct Game;
struct GameBuilder;

/// Possible vehicles for a player.
enum Vehicle {
  Vehicle_Pedestrian = 0,
  Vehicle_Cyclist = 1,
  Vehicle_Car = 2,
  Vehicle_MIN = Vehicle_Pedestrian,
  Vehicle_MAX = Vehicle_Car
};

inline const Vehicle (&EnumValuesVehicle())[3] {
  static const Vehicle values[] = {
    Vehicle_Pedestrian,
    Vehicle_Cyclist,
    Vehicle_Car
  };
  return values;
}

inline const char * const *EnumNamesVehicle() {
  static const char * const names[4] = {
    "Pedestrian",
    "Cyclist",
    "Car",
    nullptr
  };
  return names;
}

inline const char *EnumNameVehicle(Vehicle e) {
  if (flatbuffers::IsOutRange(e, Vehicle_Pedestrian, Vehicle_Car)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesVehicle()[index];
}

/// Postion on the planet, represented by
/// geographic coordinates.
FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(8) Position FLATBUFFERS_FINAL_CLASS {
 private:
  double long__;
  double lat_;

 public:
  Position()
      : long_(0),
        lat_(0) {
  }
  Position(double _long_, double _lat)
      : long__(flatbuffers::EndianScalar(_long_)),
        lat_(flatbuffers::EndianScalar(_lat)) {
  }
  double long_() const {
    return flatbuffers::EndianScalar(long__);
  }
  double lat() const {
    return flatbuffers::EndianScalar(lat_);
  }
};
FLATBUFFERS_STRUCT_END(Position, 16);

/// Player
struct Player FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PlayerBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_ID = 6,
    VT_POINTS = 8,
    VT_POSITION = 10,
    VT_VEHICLE = 12
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint32_t id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  int32_t points() const {
    return GetField<int32_t>(VT_POINTS, 0);
  }
  const Upzp::GameStatus::Position *position() const {
    return GetStruct<const Upzp::GameStatus::Position *>(VT_POSITION);
  }
  Upzp::GameStatus::Vehicle vehicle() const {
    return static_cast<Upzp::GameStatus::Vehicle>(GetField<int8_t>(VT_VEHICLE, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint32_t>(verifier, VT_ID) &&
           VerifyField<int32_t>(verifier, VT_POINTS) &&
           VerifyFieldRequired<Upzp::GameStatus::Position>(verifier, VT_POSITION) &&
           VerifyField<int8_t>(verifier, VT_VEHICLE) &&
           verifier.EndTable();
  }
};

struct PlayerBuilder {
  typedef Player Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Player::VT_NAME, name);
  }
  void add_id(uint32_t id) {
    fbb_.AddElement<uint32_t>(Player::VT_ID, id, 0);
  }
  void add_points(int32_t points) {
    fbb_.AddElement<int32_t>(Player::VT_POINTS, points, 0);
  }
  void add_position(const Upzp::GameStatus::Position *position) {
    fbb_.AddStruct(Player::VT_POSITION, position);
  }
  void add_vehicle(Upzp::GameStatus::Vehicle vehicle) {
    fbb_.AddElement<int8_t>(Player::VT_VEHICLE, static_cast<int8_t>(vehicle), 0);
  }
  explicit PlayerBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Player> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Player>(end);
    fbb_.Required(o, Player::VT_NAME);
    fbb_.Required(o, Player::VT_POSITION);
    return o;
  }
};

inline flatbuffers::Offset<Player> CreatePlayer(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint32_t id = 0,
    int32_t points = 0,
    const Upzp::GameStatus::Position *position = 0,
    Upzp::GameStatus::Vehicle vehicle = Upzp::GameStatus::Vehicle_Pedestrian) {
  PlayerBuilder builder_(_fbb);
  builder_.add_position(position);
  builder_.add_points(points);
  builder_.add_id(id);
  builder_.add_name(name);
  builder_.add_vehicle(vehicle);
  return builder_.Finish();
}

inline flatbuffers::Offset<Player> CreatePlayerDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    uint32_t id = 0,
    int32_t points = 0,
    const Upzp::GameStatus::Position *position = 0,
    Upzp::GameStatus::Vehicle vehicle = Upzp::GameStatus::Vehicle_Pedestrian) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return Upzp::GameStatus::CreatePlayer(
      _fbb,
      name__,
      id,
      points,
      position,
      vehicle);
}

/// Team
struct Team FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TeamBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POINTS = 4,
    VT_PLAYERS = 6
  };
  int32_t points() const {
    return GetField<int32_t>(VT_POINTS, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Player>> *players() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Player>> *>(VT_PLAYERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_POINTS) &&
           VerifyOffsetRequired(verifier, VT_PLAYERS) &&
           verifier.VerifyVector(players()) &&
           verifier.VerifyVectorOfTables(players()) &&
           verifier.EndTable();
  }
};

struct TeamBuilder {
  typedef Team Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_points(int32_t points) {
    fbb_.AddElement<int32_t>(Team::VT_POINTS, points, 0);
  }
  void add_players(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Player>>> players) {
    fbb_.AddOffset(Team::VT_PLAYERS, players);
  }
  explicit TeamBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Team> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Team>(end);
    fbb_.Required(o, Team::VT_PLAYERS);
    return o;
  }
};

inline flatbuffers::Offset<Team> CreateTeam(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t points = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Player>>> players = 0) {
  TeamBuilder builder_(_fbb);
  builder_.add_players(players);
  builder_.add_points(points);
  return builder_.Finish();
}

inline flatbuffers::Offset<Team> CreateTeamDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t points = 0,
    const std::vector<flatbuffers::Offset<Upzp::GameStatus::Player>> *players = nullptr) {
  auto players__ = players ? _fbb.CreateVector<flatbuffers::Offset<Upzp::GameStatus::Player>>(*players) : 0;
  return Upzp::GameStatus::CreateTeam(
      _fbb,
      points,
      players__);
}

/// Point box that is collected by the players
struct PointBox FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PointBoxBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POSITION = 4,
    VT_VALUE = 6
  };
  const Upzp::GameStatus::Position *position() const {
    return GetStruct<const Upzp::GameStatus::Position *>(VT_POSITION);
  }
  int32_t value() const {
    return GetField<int32_t>(VT_VALUE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<Upzp::GameStatus::Position>(verifier, VT_POSITION) &&
           VerifyField<int32_t>(verifier, VT_VALUE) &&
           verifier.EndTable();
  }
};

struct PointBoxBuilder {
  typedef PointBox Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_position(const Upzp::GameStatus::Position *position) {
    fbb_.AddStruct(PointBox::VT_POSITION, position);
  }
  void add_value(int32_t value) {
    fbb_.AddElement<int32_t>(PointBox::VT_VALUE, value, 0);
  }
  explicit PointBoxBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<PointBox> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PointBox>(end);
    fbb_.Required(o, PointBox::VT_POSITION);
    return o;
  }
};

inline flatbuffers::Offset<PointBox> CreatePointBox(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Upzp::GameStatus::Position *position = 0,
    int32_t value = 0) {
  PointBoxBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_position(position);
  return builder_.Finish();
}

/// Game includes all information about current game status.
struct Game FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GameBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TEAMS = 4,
    VT_BOXES = 6,
    VT_FINISHED = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Team>> *teams() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Team>> *>(VT_TEAMS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::PointBox>> *boxes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::PointBox>> *>(VT_BOXES);
  }
  bool finished() const {
    return GetField<uint8_t>(VT_FINISHED, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TEAMS) &&
           verifier.VerifyVector(teams()) &&
           verifier.VerifyVectorOfTables(teams()) &&
           VerifyOffset(verifier, VT_BOXES) &&
           verifier.VerifyVector(boxes()) &&
           verifier.VerifyVectorOfTables(boxes()) &&
           VerifyField<uint8_t>(verifier, VT_FINISHED) &&
           verifier.EndTable();
  }
};

struct GameBuilder {
  typedef Game Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_teams(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Team>>> teams) {
    fbb_.AddOffset(Game::VT_TEAMS, teams);
  }
  void add_boxes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::PointBox>>> boxes) {
    fbb_.AddOffset(Game::VT_BOXES, boxes);
  }
  void add_finished(bool finished) {
    fbb_.AddElement<uint8_t>(Game::VT_FINISHED, static_cast<uint8_t>(finished), 0);
  }
  explicit GameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Game> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Game>(end);
    fbb_.Required(o, Game::VT_TEAMS);
    return o;
  }
};

inline flatbuffers::Offset<Game> CreateGame(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::Team>>> teams = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Upzp::GameStatus::PointBox>>> boxes = 0,
    bool finished = false) {
  GameBuilder builder_(_fbb);
  builder_.add_boxes(boxes);
  builder_.add_teams(teams);
  builder_.add_finished(finished);
  return builder_.Finish();
}

inline flatbuffers::Offset<Game> CreateGameDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Upzp::GameStatus::Team>> *teams = nullptr,
    const std::vector<flatbuffers::Offset<Upzp::GameStatus::PointBox>> *boxes = nullptr,
    bool finished = false) {
  auto teams__ = teams ? _fbb.CreateVector<flatbuffers::Offset<Upzp::GameStatus::Team>>(*teams) : 0;
  auto boxes__ = boxes ? _fbb.CreateVector<flatbuffers::Offset<Upzp::GameStatus::PointBox>>(*boxes) : 0;
  return Upzp::GameStatus::CreateGame(
      _fbb,
      teams__,
      boxes__,
      finished);
}

inline const Upzp::GameStatus::Game *GetGame(const void *buf) {
  return flatbuffers::GetRoot<Upzp::GameStatus::Game>(buf);
}

inline const Upzp::GameStatus::Game *GetSizePrefixedGame(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Upzp::GameStatus::Game>(buf);
}

inline bool VerifyGameBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Upzp::GameStatus::Game>(nullptr);
}

inline bool VerifySizePrefixedGameBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Upzp::GameStatus::Game>(nullptr);
}

inline void FinishGameBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Upzp::GameStatus::Game> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedGameBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Upzp::GameStatus::Game> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace GameStatus
}  // namespace Upzp

#endif  // FLATBUFFERS_GENERATED_GAMESTATUS_UPZP_GAMESTATUS_H_
