#ifndef UDPPOLICY_HPP
#define UDPPOLICY_HPP

#include "SockTraits.hpp"

namespace Network
{

  class UDPPolicy
  {
  public:
    ~UDPPolicy();

    int 		sendto();
    int 		recvfrom();

  protected:
    UDPPolicy();
    SockTraits::SockDescriptor	socket();

  };

}

#endif
