#ifndef __RIGIDBODY_H__
# define __RIGIDBODY_H__

#include "GameEngine/Component/Component.hpp"

namespace Sophie {
  class RigidBody : public Component {

  public:
    RigidBody(Entity *e);


  private:
    RigidBody();

    Entity*	_entity;
    float	_mass;
    bool	_isAffectedByGravity;
  }
}

#endif
