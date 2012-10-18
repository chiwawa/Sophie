#ifndef __COMPONENT_HPP__
# define __COMPONENT_HPP__


namespace Sophie {


  class Entity;

  class Component {
  public:

    Component(Entity* e);
    virtual void	Update() = 0;


  protected:
    Entity*	_entity;
  };
}

#endif
