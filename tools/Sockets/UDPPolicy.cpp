#include "Sockets/UDPPolicy.hpp"

namespace Network
{

  UDPPolicy::UDPPolicy()
  {
  }

  UDPPolicy::~UDPPolicy()
  {
  }


  int		UDPPolicy::sendto()
  {

  }

  int		UDPPolicy::recvfrom()
  {

  }

  SockTraits::SockDescriptor	UDPPolicy::socket()
  {
    return SockTraits::socket(AF_INET, SOCK_DGRAM, SockTraits::SOCK_UDP);
  }

}
