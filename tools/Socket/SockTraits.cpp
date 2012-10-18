#ifdef _WIN32

#include <winsock2.h>

#else
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#endif

#include <cstdlib>
#include <iostream>
#include <cstdio>


#include "Sockets/SockTraits.hpp"

namespace Network
{
#ifdef _WIN32
  const unsigned int	SockTraits::defaultListenValue = SOMAXCONN;
  unsigned int			SockTraits::_socknumb = 0;
#else
  const unsigned int	SockTraits::defaultListenValue = 10;
  const char		*SockTraits::_protnames[2] = {"tcp", "udp"};
#endif

  //Common

  bool		SockTraits::bind(const SockTraits::SockDescriptor &desc,
				 const struct sockaddr_in &addr)
  {
    return !(::bind(desc, (const struct sockaddr*)&addr, sizeof(addr)));
  }

  bool		SockTraits::listen(const SockTraits::SockDescriptor &sock, unsigned int backlog)
  {
    return !::listen(sock, backlog);
  }


#ifdef _WIN32

  int		SockTraits::recvfrom(const SockTraits::SockDescriptor &desc, void *buff,
				     unsigned int buffsize, int flags, 
				     struct sockaddr_in *from, unsigned int *fromlen)
  {
    WSABUF			dirtyWindowsBuffer;
    DWORD			dataread;
	DWORD			_flagsint;
	int				result;
    int				ret;

	_flagsint = flags;
    dirtyWindowsBuffer.len = buffsize;
    dirtyWindowsBuffer.buf = static_cast<CHAR*>(buff);
    ret = ::WSARecvFrom(desc, &dirtyWindowsBuffer, 1, &dataread, &_flagsint,
			(struct sockaddr*)(from), (LPINT)fromlen, NULL, NULL);
	result = dataread;
    return (!ret) ? result : -1;
  }

  int		SockTraits::sendto(const SockTraits::SockDescriptor &desc, const void *buff,
				   unsigned int buffsize, int flags, 
				   const struct sockaddr_in *to)
  {
    WSABUF			dirtyWindowsBuffer;
	DWORD			dataread;
    int				result;
    int				ret;
    
    dirtyWindowsBuffer.len = buffsize;
    dirtyWindowsBuffer.buf = new char[buffsize];
    memcpy(dirtyWindowsBuffer.buf, buff, buffsize);
    ret = ::WSASendTo(desc, &dirtyWindowsBuffer, 1, &dataread, flags, 
		      (const struct sockaddr*)(to), 
		      (to) ? sizeof(*to) : 0,
		      NULL, NULL);
    delete[] dirtyWindowsBuffer.buf;
	result = dataread;
    return (!ret) ? result : -1;
  }

  bool		SockTraits::accept(const SockTraits::SockDescriptor &desc,
				   struct sockaddr_in *addr, unsigned int *addlen,
				   SockTraits::SockDescriptor &out)
  {
    out = ::WSAAccept(desc, (struct sockaddr*)addr,  (LPINT)addlen,
		      NULL, 0);
    return (out != INVALID_SOCKET) ? true : false;
  }

  bool		SockTraits::connect(const SockTraits::SockDescriptor &desc, const struct sockaddr_in &dest)
  {
    return !::WSAConnect(desc, (const struct sockaddr*)&dest, sizeof(dest), NULL, NULL, NULL, NULL);
  }

  bool		SockTraits::close(const SockTraits::SockDescriptor &sock)
  {
    if (SockTraits::_socknumb != 0 && --SockTraits::_socknumb == 0)
      WSACleanup();
    return !::closesocket(sock);
  }

  SockTraits::SockDescriptor	SockTraits::socket(int domain, int type, 
					   SockTraits::SockProtocol prot)
  {
  
    if (SockTraits::_socknumb == 0)
      {
	WSADATA d;
	if (WSAStartup(MAKEWORD(2,2), &d) != 0)
	  return -1;
      }
    SOCKET s = ::socket(domain, type, prot);

    if (s == INVALID_SOCKET)
      return -1;
    ++SockTraits::_socknumb;
    return s;
  }

  /////////// Error Management

  int		SockTraits::getLastError()
  {
    return ::WSAGetLastError();
  }

  void		SockTraits::printError(const int errcode)
  {
    WCHAR	errbuf[255];

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
		  NULL, errcode, 0, (LPSTR)&errbuf[0], 255, NULL);
    std::cerr << "SockTraits Error Management : " << errbuf << std::endl;
  }


  ///////////////////

#else //if UNIX / Linux

  ///////////////////

  int		SockTraits::recvfrom(const SockTraits::SockDescriptor &desc, void *buff,
				 unsigned int buffsize,  int flags, 
				 struct sockaddr_in *from, unsigned int *fromlen)
  {
    int			result;

    result = ::recvfrom(desc, buff, buffsize, flags, 
			(struct sockaddr*)(from), fromlen);
    return result;
  }

  int		SockTraits::sendto(const SockTraits::SockDescriptor &desc, const void *buff,
				   unsigned int buffsize, int flags,
				   const struct sockaddr_in *dest)
  {
    int			result;

    result = ::sendto(desc, buff, buffsize, flags,
		      (const struct sockaddr*)dest, 
		      (dest) ? sizeof(*dest) : 0);
    return result;
  }


  bool		SockTraits::accept(const SockTraits::SockDescriptor &desc,
				   struct sockaddr_in *addr, unsigned int *addlen,
				   SockTraits::SockDescriptor &out)
  {
    out = ::accept(desc, (struct sockaddr*)addr, addlen);
    return (out != -1) ? true : false;
  }

  bool		SockTraits::connect(const SockTraits::SockDescriptor &desc, const struct sockaddr_in &dest)
  {
    return !::connect(desc, (const struct sockaddr*)&dest, sizeof(dest));
  }

  bool		SockTraits::close(const SockTraits::SockDescriptor &sock)
  {
    return !::close(sock);
  }

  SockTraits::SockDescriptor	SockTraits::socket(int domain, int type, 
					   SockTraits::SockProtocol protocol)
  {
    struct protoent	*s_prot;
    SockTraits::SockDescriptor	sock;

    if ((s_prot = getprotobyname(SockTraits::_protnames[protocol])))
      {
	struct linger lng = {1, 0};
	int errval;

	if ((sock = ::socket(domain, type, s_prot->p_proto)) == -1)
	  return -1;
	errval = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, &lng, sizeof(lng));
	//#ifdef DEBUG
	if (errval == -1)
	  perror("setsockopt :");
	else
	  std::cerr << "setsockopt : ok" << std::endl;
	//#endif
	return sock;
      }
    return -1;
  }

  /////////// Error Management

  int		SockTraits::getLastError()
  {
    return errno;
  }

  void		SockTraits::printError(const int errcode)
  {
    char	*errbuf;

    errbuf = strerror(errcode);
    std::cerr << "SockTraits Error Management : " << errbuf << std::endl;
  }
  
#endif

}
