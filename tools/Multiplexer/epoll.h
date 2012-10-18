#ifndef __EPOLL__
#define __EPOLL__

# include <sys/epoll.h>
# include "Multiplexer/IMultiplexer.hpp"
# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"

typedef struct	t_socketCallback
{
  Network::ISocket	*socket;
  ioCallback		*callback;
}		socketCallback;

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
      int			process(void);
      void			execute(void);

    private:
      void			_close(Network::ISocket*);

      unsigned int				_nbrMax;
      int					_resNbr;
      int					_efd;
      int					_timeOut;
      struct epoll_event*			_eventsRes;
      struct epoll_event			_evTab[3];
      ioCallback*				_cbTab[2];
      std::list<socketCallback*>		_polled;
    };
}


#endif /* __EPOLL__ */
