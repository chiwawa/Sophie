#ifndef				SERVER_HPP
# define			SERVER_HPP

# include "Sockets/TCPPolicy.hpp"
# include "Sockets/Socket.hpp"
# include "Multiplexer/IMultiplexer.hpp"
# include "Acceptor/Acceptor.hpp"
# include <sys/socket.h>


namespace				Sophie
{
  class					Server
  {
  public:
    Server(int port = 4242);
    ~Server();

    bool				run();

  private:
    int					_port;
    Acceptor				_acceptor;
    Network::Socket<Network::TCPPolicy>	*_socketServer;
    Tools::IMultiplexer*		_multiplexer;
    std::list<Network::ISocket*>	_socketList;

    void				addSocketInList(Network::ISocket*);
  };
}
#endif
