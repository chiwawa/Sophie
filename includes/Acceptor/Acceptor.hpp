#ifndef __ACCEPTOR__H__
# define __ACCEPTOR_H__

# include "Sockets/TCPPolicy.hpp"
# include "Sockets/Socket.hpp"
# include "Multiplexer/IMultiplexer.hpp"

namespace Sophie {

  class Acceptor {

  public:
    Acceptor(int port);

    bool	init();

  private:
    Acceptor();

    void	Acceptor::_accept(Network::Socket<Network::TCPPolicy>* s);


    int						_port;
    Network::Socket<Network::TCPPolicy>		_acceptSocket;
    Tools::IMultiplexer*			_multiplexer;
  };
}

#endif
