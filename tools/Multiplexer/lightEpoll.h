
#ifndef __LIGHTEPOLL__
#define __LIGHTEPOLL__

# include <sys/epoll.h>
# include "Multiplexer/IMultiplexer.hpp"
# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"

namespace Tools
{
  class lightMultiplexer
  {
  public:
    lightMultiplexer(Tools::IMultiplexer::flag, ioCallback*, Network::ISocket*, int = DEFAULT_TIMEOUT);
    ~lightMultiplexer();
    lightMultiplexer(const lightMultiplexer&);
    lightMultiplexer& operator=(const lightMultiplexer&);

    int			process(void);
    void			execute(void);

  private:
    int			_eventNbr;
    int			_queueFd;
    int			_timeOut;
    struct epoll_event*	_evlist;
    struct epoll_event*	_eventRes;
    Network::ISocket*	_socket;
    ioCallback*		_callback;
  };
}

#endif /* __LIGHTEPOLL__ */
