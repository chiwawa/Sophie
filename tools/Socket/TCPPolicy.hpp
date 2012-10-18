#ifndef TCPPOLICY_HPP
#define TCPPOLICY_HPP

#include "SockTraits.hpp"
#include "Socket.hpp"

namespace Network
{

  class TCPPolicy
  {
  public:
    ~TCPPolicy();
    /*
    int				recvfrom(SockTraits::SockDescriptor &,
					 void *, unsigned int,
					 int = 0);
    int				sendto(SockTraits::SockDescriptor &,
				       const void *, unsigned int,
				       int = 0);
    
    Socket<TCPPolicy>		*accept(SockTraits::SockDescriptor&,
					struct sockaddr_in * = NULL);
    bool			listen(SockTraits::SockDescriptor &,
				       unsigned int = SockTraits::defaultListenValue);
    */
    inline int				recvfrom(void *buffer, unsigned int size,
						 int flags = 0)
    {
      return SockTraits::recvfrom(this->_sock.getDescriptor(), buffer, size, flags, NULL, NULL); 
    }
    inline int				sendto(const void *buffer, unsigned int size,
					       int flags = 0)
    {
      return SockTraits::sendto(this->_sock.getDescriptor(), buffer, size, SockTraits::NO_INTERRUPT | flags, NULL);
    }
    
    Socket<TCPPolicy>		*accept(struct sockaddr_in * = NULL) const;
    inline bool			listen(unsigned int lvalue = SockTraits::defaultListenValue)
    {
      return SockTraits::listen(this->_sock.getDescriptor(), lvalue);
    }

	inline ssize_t	read(SockTraits::SockDescriptor fd, void* buffer, size_t s)
    {
      return (SockTraits::recvfrom(fd, buffer, s, 0, NULL, NULL));
    }

	inline ssize_t	write(SockTraits::SockDescriptor fd, void* buffer, size_t s)
    {
      return (SockTraits::sendto(fd, buffer, s, SockTraits::NO_INTERRUPT, NULL));
    }

  protected:
    TCPPolicy();
    inline SockTraits::SockDescriptor	socket()
    {
      return SockTraits::socket(AF_INET, SOCK_STREAM, SockTraits::SOCK_TCP);
    }

    const Socket<TCPPolicy>		&_sock;

  };

}

#endif
