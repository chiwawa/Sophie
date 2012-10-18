#ifndef __SIDESCROLLINGMAP_HPP__
# define __SIDESCROLLINGMAP_HPP__

#include <map>
#include "GameEngine/Entity/Entity.hpp"

namespace Sophie {
  class SideScrollingMap {

  public:
    SideScrollingMap();

    void	Update();

  private:
    std::map<size_t, Entity>	_map;
  };
}

#endif
