#ifndef __TRANSFORM_HPP__
# define __TRANSFORM_HPP__

namespace Sophie {

  struct Position {
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


