#ifndef __ISOCKET_HPP__
# define __ISOCKET_HPP__

#include <string>

#include "SockTraits.hpp"

#if defined _WIN32 && !defined( __ssize_t_defined )
typedef long int        ssize_t;
#endif

namespace Network
{
  class ISocket
  {
  public:
    virtual SockTraits::SockDescriptor	getDescriptor() const = 0;
    virtual ISocket*			accept(struct sockaddr_in * = NULL) const = 0;
    virtual bool			bind(const std::string &, const unsigned short) = 0;
    virtual bool 			listen(unsigned int = SockTraits::defaultListenValue) = 0;
    virtual bool			close() = 0;
    virtual int				recvfrom(void*, int, int) = 0;
    virtual int				sendto(const void*, int, int) = 0;
	virtual ssize_t			read(SockTraits::SockDescriptor, void*, size_t) = 0;
	virtual ssize_t			write(SockTraits::SockDescriptor, void*, size_t) = 0;
  };
}

#ifndef _WIN32
typedef Network::SockTraits::SockDescriptor	SOCKET;
#endif

#endif
