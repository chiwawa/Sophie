#ifndef __ACCEPTOR__H__
# define __ACCEPTOR_H__

# include "tools/Socket/TCPPolicy.hpp"
# include "tools/Socket/Socket.hpp"
# include "tools/Multiplexer/IMultiplexer.hpp"

namespace Sophie {

  class Acceptor {

  public:
    Acceptor(int port);

    bool	init();

  private:
    Acceptor();

    void	Acceptor::_accept(Network::Socket<TCPPolicy>* s);


    int					_port;
    Network::Socket<TCPPolicy>		_acceptSocket;
    Tools::IMultiplexer*		_multiplexer;
  };
}

#endif
