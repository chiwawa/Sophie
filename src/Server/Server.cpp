#include	"Server/Server.hpp"

Server::Server(int port) : _port(port)
{
  return;
}

Server::~Server()
{
  return;
}

static bool	Server::addSocketInList(Network::ISocket* s)
{
  this->_socketList.push_back(s);
  return true;
}

bool		Server::createServer()
{
  this->_socketServer = new Network::Socket<Network::TCPPolicy>();
  this->addSocketInList(this->_socketServer);
  if (this->_socketServer->bind("any", this->_port) == false)
    {
      std::cerr << "Server: Error: Bind failed" << std::endl;
      return false;
    }
  if (this->_socketServer->listen(MAX_CLIENT) == false)
    {
      std::cerr << "Server: Error: Listen failed" << std::endl;
      return false;
    }
  return true;
}

void		Server::_accept(Network::Socket<Network::TCPPolicy> *s)
{
  Network::Socket<Network::TCPPolicy> *accepted;


  accpeted = s->accept();
  if (accepted == NULL)
    std::cerr << "Server: Error Accept" << std::endl;
  else
    std::cout << "Server: Accept: OK" << std::endl;
  return;
}

bool		Server::isRunning()
{
  bool		_loop;
  ioCallback acceptCb = ioCallback::create<Sophie::Server, &Sophie::Server::_accept>(this);
  this->_multiplexer = new Tools::Multiplexer(&acceptCb, 0, getSocketLimit(), -1);

  _loop = true;
  while (_loop)
    {
      this->_multiplexer.clear(Tools::IMultiplexer::READ);
      this->_multiplexer.clear(Tools::IMultiplexer::WRITE);
      this->_multiplexer.addSockets(this->_socketList);
      this->_multiplexer.process();
    }
  return true;
}
