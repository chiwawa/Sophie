#include <iostream>
#include <iomanip>

#include "Sockets/TCPPolicy.hpp"

namespace Network
{

  TCPPolicy::TCPPolicy()
    : _sock(static_cast<const Socket<TCPPolicy> &>(*this))
  {
  }

  TCPPolicy::~TCPPolicy()
  {
  }
  /*
  int		TCPPolicy::sendto(const void *buffer, unsigned int size,
				  int flags)
  {
    return SockTraits::sendto(this->_sock.getDescriptor(), buffer, size, SockTraits::NO_INTERRUPT | flags, NULL);
  }

  int		TCPPolicy::recvfrom(void *buffer, unsigned int size,
				    int flags)
  {
    return SockTraits::recvfrom(this->_sock.getDescriptor(), buffer, size, flags, NULL, NULL);
  }
  

  SockTraits::SockDescriptor	TCPPolicy::socket()
  {
    return SockTraits::socket(AF_INET, SOCK_STREAM, SockTraits::SOCK_TCP);
  }
  */
  Socket<TCPPolicy>		*TCPPolicy::accept(struct sockaddr_in *crd) const
  {
    static unsigned int count = 0;

    SockTraits::SockDescriptor	client;
    unsigned int		len;

    std::cerr << ">>>>>>>>>>> ACCEPT NUMBER " << count++ << "<<<<<<<<<<<<<<<" << std::endl;

    if (!SockTraits::accept(this->_sock.getDescriptor(), crd, (crd) ? &len : NULL, client))
      return NULL;
    return new Socket<TCPPolicy>(client);
  }

  /*
  bool				TCPPolicy::listen(unsigned int lvalue)
  {
    return SockTraits::listen(this->_sock.getDescriptor(), lvalue);
  }
  */

  /*
  int		TCPPolicy::sendto(SockTraits::SockDescriptor &socket,
				  const void *buffer, unsigned int size,
				  int flags)
  {
    return SockTraits::sendto(socket, buffer, size, SockTraits::NO_INTERRUPT | flags, NULL);
  }

  int		TCPPolicy::recvfrom(SockTraits::SockDescriptor &socket,
				    void *buffer, unsigned int size,
				    int flags)
  {
    return SockTraits::recvfrom(socket, buffer, size, flags, NULL, NULL);
  }


  SockTraits::SockDescriptor	TCPPolicy::socket()
  {
    return SockTraits::socket(AF_INET, SOCK_STREAM, SockTraits::SOCK_TCP);
  }

  Socket<TCPPolicy>		*TCPPolicy::accept(SockTraits::SockDescriptor &sock,
						   struct sockaddr_in *crd)
  {
    SockTraits::SockDescriptor	client;
    unsigned int		len;

    if (!SockTraits::accept(sock, crd, (crd) ? &len : NULL, client))
      return NULL;
    return new Socket<TCPPolicy>(client);
  }

  bool				TCPPolicy::listen(SockTraits::SockDescriptor &sock,
						  unsigned int lvalue)
  {
    return SockTraits::listen(sock, lvalue);
  }
*/
}
