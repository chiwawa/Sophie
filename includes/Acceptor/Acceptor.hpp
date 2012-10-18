#ifndef __ACCEPTOR__H__
# define __ACCEPTOR_H__

# include "Sockets/TCPPolicy.hpp"
# include "Sockets/Socket.hpp"
# include "Multiplexer/IMultiplexer.hpp"
//# include "Server/Server.hpp"

namespace Sophie {

  class Server;

  class Acceptor {

  public:
    Acceptor(int port, Server &server);

    bool	init();
    void	run();

  private:
    Acceptor();

    void	_accept(Network::ISocket* s);

    int						_port;
    Server					&_server;
    Network::Socket<Network::TCPPolicy>		*_acceptSocket;
    Tools::IMultiplexer*			_multiplexer;
  };
}

#endif
