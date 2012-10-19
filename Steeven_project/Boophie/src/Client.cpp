#include "Client.hpp"
#include <iostream>

namespace Boophie {
  namespace Network {
    boost::shared_ptr<Client> Client::create(boost::asio::io_service& io_service) {
      return boost::shared_ptr<Client>(new Client(io_service));
    }

    Client::Client(boost::asio::io_service& io_service)
      : _socket(io_service) {
    }

    void					Client::write() {
      boost::asio::async_write(this->_socket, boost::asio::buffer("Salut :)"),
			       boost::bind(&Client::endWrite, shared_from_this(),
					   boost::asio::placeholders::error,
					   boost::asio::placeholders::bytes_transferred));
    }

    void					Client::endWrite(const boost::system::error_code&, size_t) {
      std::cout << "I'm done writing" << std::endl;
    }

    boost::asio::ip::tcp::socket&	Client::socket() {
      return this->_socket;
    }
  }
}
