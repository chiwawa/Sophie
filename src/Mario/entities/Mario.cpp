#include "Mario/entities/Mario.hpp"
#include "GameEngine/Component/RigidBody/RigidBody.hpp"

namespace Sophie {
  namespace Mario {
    Mario::Mario() {
    }

    void	Mario::Start() {
      this->_speed = 1;
      this->_components.push_back(new RigidBody());
    }

    void	Mario::Update() {
      
    }

  }
}
