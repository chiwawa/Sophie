#ifndef IMULTIPLEXER_H_
#  define IMULTIPLEXER_H_

#include <list>

# include "tools/Sockets/Socket.hpp"
# include "tools/Sockets/TCPPolicy.hpp"
# include "tools/Callback/Callback.hpp"

typedef zia::api::Callback<void ( Network::ISocket*)>  ioCallback;

#define MAX_CLIENT	1000
#define DEFAULT_TIMEOUT	1

namespace zia
{
  namespace Tools
    {
      class IMultiplexer
	{
	public:
	  enum	flag
	    {
	      READ,
	      WRITE,
	    };
	  virtual ~IMultiplexer(){}

	  virtual void			addSocket(Network::ISocket*, const IMultiplexer::flag = IMultiplexer::READ) = 0;
	  virtual void			addSocket(Network::ISocket*, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ) = 0;
	  virtual void			addSockets(const std::list<Network::ISocket*>&, const IMultiplexer::flag = IMultiplexer::READ) = 0;
	  virtual void			addSockets(const std::list<Network::ISocket*>&, ioCallback&, const IMultiplexer::flag = IMultiplexer::READ) = 0;
	  virtual void			clear(const IMultiplexer::flag = IMultiplexer::READ) = 0;
	  virtual int			process(void) = 0;
	  virtual void			execute(void) = 0;
	};
    }
}

#endif /* !IMULTIPLEXER_H_ */
