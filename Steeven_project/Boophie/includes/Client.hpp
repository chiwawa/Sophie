#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <boost/bind.hpp>
# include <boost/shared_ptr.hpp>
# include <boost/asio.hpp>
# include <boost/enable_shared_from_this.hpp>

namespace Boophie {
  namespace Network {

    class Client : public boost::enable_shared_from_this<Client> {
    public:
      static boost::shared_ptr<Client>	create(boost::asio::io_service&);

      void				start();
      void				write();
      void				endWrite(const boost::system::error_code&, size_t);

      boost::asio::ip::tcp::socket&	socket();

    private:
      Client(boost::asio::io_service&);
      boost::asio::ip::tcp::socket	_socket;
    };
  }
}

#endif
