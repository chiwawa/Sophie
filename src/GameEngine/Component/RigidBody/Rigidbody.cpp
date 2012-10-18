#include "GameEngine/Component/Rigidbody/Rigidbody.hpp"

namespace Sophie {
  Rigidbody::Rigidbody(Entity *entity)
    : _entity(entity),
      _mass(5),
      _isAffectedByGravity(true)
  {
  }

}
