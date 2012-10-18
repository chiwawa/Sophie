#include "GameEngine/Component/Transform.hpp"

namespace Sophie {

  Transform::Transform() {
    this->_position.x = 0;
    this->_position.y = 0;
  }

  Transform::Transform(int x, int y) {
    this->_position.x = x;
    this->_position.y = y;
  }


  struct Position& Transform::getPosition() {
    return this->_position;
  }


}
