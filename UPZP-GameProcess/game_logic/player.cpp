#include "inc/player.h"

namespace upzp::game_logic {

/**
 * @brief Constructor.
 * @param name Name of the player.
 * @param id ID of the player.
 */
Player::Player(const std::string name, const uint32_t id, const enum VehicleType vehicle) :
  name_(name), id_(id), vehicle_(vehicle) {
}

/**
 * @brief Set player's position on the map.
 * @param coords Position's coordinates.
 */
void Player::SetPosition(Coordinates coords) {
  position_ = coords;
}

/**
 * @brief Get player's name.
 * @return Player's name.
 */
std::string Player::Name() const {
  return name_;
}

/**
 * @brief Get player's ID.
 * @return Player's ID.
 */
uint32_t Player::Id() const {
  return id_;
}

/**
 * @brief Get player's current points.
 * @return Player's current points count.
 */
int64_t Player::Points() const {
  return points_;
}

/**
 * @brief Get player's current position.
 * @return Coordinates of current position.
 */
Coordinates Player::Position() const {
  return position_;
}

/**
 * @brief Player's vehicle.
 * @return Vehicle type.
 */
VehicleType Player::Vehicle() const {
  return vehicle_;
}

/**
 * @brief Get player's movement input.
 * @return Player's input.
 */
PlayerInput Player::Input() const {
  return input_;
}

/**
 * @brief Add points to player's score.
 * @param points Amount of points to add.
 */
void Player::AddPoints(int64_t points) {
  points_ += points;
}

/**
 * @brief Reset player's points score to 0.
 */
void Player::ResetScore() {
  points_ = 0;
}

/**
 * @brief Set player's input.
 * @param input New input.
 */
void Player::SetInput(PlayerInput input) {
  input_ = input;
}

}  // namespace upzp::game_logic