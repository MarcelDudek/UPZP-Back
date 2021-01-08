#ifndef UPZP_GAMEPROCESS_UPZP_GAMEPROCESS_GAME_LOGIC_INC_POINT_BOX_H_
#define UPZP_GAMEPROCESS_UPZP_GAMEPROCESS_GAME_LOGIC_INC_POINT_BOX_H_

#include "coordinates.h"

namespace upzp::game_logic {

/**
 * Point box that is collectable by the players.
 */
struct PointBox {
  Coordinates position;
  int64_t value;
};

}  // namespace upzp::game_logic

#endif //UPZP_GAMEPROCESS_UPZP_GAMEPROCESS_GAME_LOGIC_INC_POINT_BOX_H_
