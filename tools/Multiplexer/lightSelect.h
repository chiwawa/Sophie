#ifndef MULTIPLEXER_H_
#  define MULTIPLEXER_H_

#ifndef _WIN32
# include <sys/select.h>
#endif

# include "Multiplexer/IMultiplexer.hpp"
# include "Sockets/Socket.hpp"
# include "Sockets/TCPPolicy.hpp"

namespace zia
{
  namespace Tools
    {

      class lightMultiplexer
      {

      public:
	lightMultiplexer(IlightMultiplexer::flag, ioCallback*, Network::ISocket*, int = DEFAULT_TIMEOUT
	    );

	~lightMultiplexer();
	lightMultiplexer(const lightMultiplexer&);
	lightMultiplexer& operator=(const lightMultiplexer&);

	int		process(void);
	void		execute(void);

      private:
	int					_flag;
	int					_eventNbr;
	struct timeval				_timeout;
	fd_set					_evlist;
	Network::ISocket*			_socket;
	ioCallback*				_callback;
      };
    }
}

#endif /* !MULTIPLEXER_H_ */
