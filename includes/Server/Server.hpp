#ifndef				SERVER_HPP
# define			SERVER_HPP

# include "tools/Socket/TCPPolicy.hpp"
# include "tools/Socket/Socket.hpp"
# include "tools/Multiplexer/IMultiplexer.hpp"

namespace			Sophie
{
  class				Server
  {
  private:
    int				_port;
    Network::Socket<TCPPolicy>	_socketServer;
    Tools::IMultiplexer*	_multiplexer;
    std::list<Network::ISocket*> _socketList;

    void			Server::_accept();
    static void			addSocketInList(<Network::ISocket*);

  public:
    Server(int port = 4242);
    ~Server();

    bool		createServer();
    bool		isRunnig();
  };
}
#endif
