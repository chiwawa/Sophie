#ifndef SOCKTRAITS_HPP
#define SOCKTRAITS_HPP

#	ifdef _WIN32

#		ifdef WIN32_LEAN_AND_MEAN
#			include <Winsock2.h>
#			include <Winerror.h>
#		endif

#			include <Windows.h>

#	else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#	endif

#ifndef	 MSG_NOSIGNAL
#define  MSG_NOSIGNAL  0
#endif

#ifndef	 SO_REUSEPORT
#define  SO_REUSEPORT SO_REUSEADDR
#endif



namespace Network
{

  class SockTraits
  {

  public:
#ifdef _WIN32
    typedef SOCKET	SockDescriptor;
    enum SockFlags
      {
	NO_INTERRUPT = 0
      };
    enum SockError
      {
      };
    enum SockProtocol
      {
	SOCK_TCP = IPPROTO_TCP,
	SOCK_UDP = IPPROTO_UDP
      };
private:
	static unsigned int	_socknumb;

#else //if UNIX / Linux
    typedef long	SockDescriptor;
    enum SockFlags
      {
	NO_INTERRUPT = MSG_NOSIGNAL
      };
    enum SockError
      {
      };
    enum SockProtocol
      {
	SOCK_TCP = 0,
	SOCK_UDP = 1
      };

  private:
    static const char		*_protnames[2];

#endif

  public:
    static int			recvfrom(const SockDescriptor&, void*, unsigned int, int,
					 struct sockaddr_in *, unsigned int *);
    static int			sendto(const SockDescriptor&, const void*, unsigned int,
				       int, const struct sockaddr_in *);
    static bool			accept(const SockDescriptor&, 
				       struct sockaddr_in *, unsigned int *,
				       SockDescriptor &);
    static bool			listen(const SockDescriptor&, unsigned int = defaultListenValue);
    static SockDescriptor	socket(int, int, SockProtocol);

    static bool			bind(const SockDescriptor&, const struct sockaddr_in&);
    static bool			connect(const SockDescriptor&, const struct sockaddr_in &);
    static bool			close(const SockDescriptor&);

    static int			getLastError();
    static void			printError(const int);

    static const unsigned int	defaultListenValue;

  };

}

#endif
