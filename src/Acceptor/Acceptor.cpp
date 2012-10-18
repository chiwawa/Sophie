#include "Acceptor/Acceptor.hpp"
#include "Multiplexer/Multiplexer.hpp"

namespace Sophie {
  Acceptor::Acceptor(int port, Server &server)
    : _port(port),
      _server(server){
  }

#ifdef _WIN32
  static rlim_t   getSocketLimit()
  {
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    return (limit.rlim_max);
  }
#else
  static unsigned int getSocketLimit()
  {
    return 1024;
  }
#endif

  bool	Acceptor::init() {
    this->_acceptSocket = new Network::Socket<Network::TCPPolicy>();
    if (this->_acceptSocket->bind("any", this->_port) == 0) {
      std::cerr << "Bind failed"<< std::endl;
      return false;
    }


    ioCallback acceptCb = ioCallback::create<Sophie::Acceptor, &Sophie::Acceptor::_accept>(this);
    this->_multiplexer = new Tools::Multiplexer(&acceptCb,
						0,
						getSocketLimit(),
						-1);

    this->_acceptSocket->listen(MAX_CLIENT);
    this->_multiplexer->addSocket(this->_acceptSocket, Tools::IMultiplexer::READ);

    return true;
  }

  void	Acceptor::_accept(Network::ISocket* s) {
    Network::ISocket* accepted;

    std::cout << "Debug accept acceptor" << std::endl;
    accepted = s->accept();
    if (accepted == NULL) std::cerr << "Error while accepting client" << std::endl;
    else {
      std::cout << "Accepted : " << static_cast<int>(accepted->getDescriptor()) << std::endl;
    }
  }

  void	Acceptor::run()
  {
    std::cout << "avant process"<< std::endl;
    this->_multiplexer->process();
    std::cout << "apres process"<< std::endl;
    this->_multiplexer->execute();
    std::cout << "apres execute"<< std::endl;
  }
}

