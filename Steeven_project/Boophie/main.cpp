#include <iostream>
#include "Server.hpp"

int		main(int ac, char **av)
{
  boost::asio::io_service	io_service;
  Boophie::Network::Server	boophie(io_service);

  boophie.accept();
  io_service.run();
  return (0);
}
