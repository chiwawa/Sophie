#include "Acceptor/Acceptor.hpp"

namespace Sophie {
  Acceptor::Acceptor(int port)
    : _port(port) {
  }

  bool	Acceptor::init() {
    this->_acceptSocket = new Network::Socket<Network::TCPPolicy>();
    if (this->_acceptSocket->bind("any", this->_port) == 0) {
      std::cerr << "Bind failed"<< std::endl;
      return false;
    }


    ioCallback acceptCb = ioCallback::create<Sophie::Acceptor, &Sophie::Acceptor::_accept>(this);
    this->_multiplexer = new Tools::Multiplexer(&acceptCb, 0, getSocketLimit(), -1);

    this->_acceptSocket->listen(MAX_CLIENT);
    this->_multiplexer->addSocket(this->_acceptSocket, Tools::IMultiplexer::READ);

    return true;
  }

  void	Acceptor::_accept(Network::Socket<Network::TCPPolicy>* s) {
    Network::Socket<Network::TCPPolicy>* accepted;

    accepted = s->accept();
    if (accept == NULL) std::cerr << "Error while accepting client" << std::endl;
    else {
      std::cout << "Accepted : " << static_cast<int>(accepted->getSocket()->getDescriptor()) << std::endl;
    }
  }

}
