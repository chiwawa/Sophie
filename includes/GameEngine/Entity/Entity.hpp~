#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

# include <list>
# include "GameEngine/Component/Component.hpp"
# include "GameEngine/Component/Transform.hpp"

namespace Sophie {

  class Entity {
  public:
    virtual void		Init() = 0;
    virtual void		Update() = 0;

  protected:
    Transform			_transform;
    std::list<Component>	_components;
  };
}

#endif
