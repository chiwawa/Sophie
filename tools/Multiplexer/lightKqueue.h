#ifndef __LIGHTKQUEUE__
#define __LIGHTKQUEUE__

# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"

namespace Tools
{
  class lightMultiplexer
  {
  public:
    lightMultiplexer(IMultiplexer::flag, ioCallback*, Network::ISocket*, int = DEFAULT_TIMEOUT);
    ~lightMultiplexer();
    lightMultiplexer(const lightMultiplexer&);
    lightMultiplexer& operator=(const lightMultiplexer&);

    int			process(void);
    void			execute(void);

  private:
    int			_flag;
    int			_eventNbr;
    int			_queueFd;
    struct kevent*		_evlist;
    struct timespec*	_timeOut;		
    Network::ISocket*	_socket;
    ioCallback*		_callback;
  };
}


#endif /* __KQUEUE__ */
