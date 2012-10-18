#ifndef __TRANSFORM_HPP__
# define __TRANSFORM_HPP__

# include "GameEngine/Component/Component.hpp"

namespace Sophie {

  struct Position : public Component {
    int	x;
    int	y;
  }

  class Transform {
  public:
    Transform();

    struct Position&	getPosition();

  private:
    struct Position	_position;
  };

}


#endif


