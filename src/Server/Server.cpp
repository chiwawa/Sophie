#include	"Server/Server.hpp"

namespace	Sophie
{
  Server::Server(int port)
    : _port(port),
      _acceptor(port, *this)
  {
    this->_acceptor.init();
  }

  Server::~Server()
  {
  }

  void		Server::addSocketInList(Network::ISocket* s)
  {
    this->_socketList.push_back(s);
  }

  bool		Server::run()
  {
    bool	isRunning;

    isRunning = true;
    while (isRunning)
      {
	this->_acceptor.run();
      }
    return true;
  }
}
