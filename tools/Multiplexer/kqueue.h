#ifndef __KQUEUE__
#define __KQUEUE__

# include <map>
# include "Multiplexer/IMultiplexer.hpp"
# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"


typedef struct		t_socketCallback
{
  Network::ISocket	*socket;
  ioCallback		*callback;
}			socketCallback;

namespace Tools
{
  class Multiplexer : public Tools::IMultiplexer
  {
  public:
    Multiplexer(ioCallback*, ioCallback*, int, int = DEFAULT_TIMEOUT);
    ~Multiplexer();
    Multiplexer(const Multiplexer&);
    Multiplexer& operator=(const Multiplexer&);

    void			addSocket(Network::ISocket*, const IMultiplexer::flag = IMultiplexer::READ);
    void			addSocket(Network::ISocket*, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ);
    void			addSockets(const std::list<Network::ISocket*>&, const IMultiplexer::flag = IMultiplexer::READ);
    void			addSockets(const std::list<Network::ISocket*>&, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ);
    void			clear(const IMultiplexer::flag = IMultiplexer::READ);
    int				process(void);
    void			execute(void);

  private:
    int		_findNextIndex(void);
    void		_close(Network::ISocket*);
    void		_setTable(void);

    struct kevent*	_scklist;
    struct kevent*	_evlist;
    struct timespec*_timeOut;
    int		_queueFd;
    int		_eventNbr;
    int		_socketNbr;
    int		_flag[2];
    ioCallback*	_cbTab[2];
    int		_maxClient;

    std::map<Network::ISocket*, int>	_clientIndexMap;
    std::list<socketCallback*>		_polled;
  };
}


#endif /* __KQUEUE__ */
