#ifndef MULTIPLEXER_H_
#  define MULTIPLEXER_H_

#ifndef _WIN32
# include <sys/select.h>
#endif

# include <list>
# include <map>

# include "Multiplexer/IMultiplexer.hpp"
# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"

#ifndef __BSD_VISIBLE
#define	FD_COPY(f, t)	(void)(*(t) = *(f))
#endif

typedef struct	t_socketCallback
{
  Network::ISocket	*socket;
  ioCallback	*callback;
}		socketCallback;

namespace zia
{
  namespace Tools
    {

      class Multiplexer : public IMultiplexer
      {

      public:
	Multiplexer(
	    ioCallback*, 
	    ioCallback*,
	    int,
	    int = DEFAULT_TIMEOUT
	    );

	~Multiplexer();
	Multiplexer(const Multiplexer&);
	Multiplexer& operator=(const Multiplexer&);

	void		addSocket(Network::ISocket*, const IMultiplexer::flag = IMultiplexer::READ);
	void		addSocket(Network::ISocket*, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ);
	void		addSockets(const std::list<Network::ISocket*>&, const IMultiplexer::flag = IMultiplexer::READ);
	void		addSockets(const std::list<Network::ISocket*>&, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ);
	void		clear(const IMultiplexer::flag = IMultiplexer::READ);
	int		process(void);
	void		execute(void);
	void		addPermanent(Network::ISocket*, const IMultiplexer::flag = IMultiplexer::READ);
	void		addPermanent(Network::ISocket*, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ);

      private:
	struct timeval				_timeout;
	std::list<socketCallback*>		_polled;
	fd_set					_read;
	fd_set					_write;
	fd_set					_permanent;
	SOCKET					_max;
	ioCallback*				_cbTab[2];
      };
    }
}

#endif /* !MULTIPLEXER_H_ */
