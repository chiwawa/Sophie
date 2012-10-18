#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>
#include <iostream>
#include <iomanip>

#include "SockTraits.hpp"
#include "Sockets/ISocket.hpp"
#include "api/IConnection.hpp"

namespace Network
{

  template<class ProtPolicy>
  class Socket :  public ISocket, public ProtPolicy
  {
  public:
    Socket();
    Socket(SockTraits::SockDescriptor);
    ~Socket();

    Socket(const Socket<ProtPolicy> &);
    Socket	&operator=(const Socket<ProtPolicy> &);

    bool				bind(const std::string &, const unsigned short);
    bool				close();
    bool				connect(const std::string &, const unsigned short);
    void				error() const;
    void				clearError();
    bool				ready() const;

    virtual inline bool     listen(unsigned int i = SockTraits::defaultListenValue)
    {
      return ProtPolicy::listen(i);
    }

    operator int();
    int	operator+(int);

    virtual inline SockTraits::SockDescriptor	getDescriptor() const
    {
      return this->_socket;
    }

    inline int				getErrCode() const
    {
      return this->_errcode;
    }

    virtual inline ISocket  *accept(struct sockaddr_in *p) const
    {
      return ProtPolicy::accept(p);
    }

    virtual inline int		recvfrom(void* buffer, int size, int flag = 0)
    {
      return ProtPolicy::recvfrom(buffer, size, flag);
    }

    virtual inline int		sendto(const void* buffer, int size, int flag = 0)
    {
      return ProtPolicy::sendto(buffer, size, flag);
    }

	virtual inline ssize_t	read(SockTraits::SockDescriptor fd, void* buffer, size_t s)
    {
      return ProtPolicy::read(fd, buffer, s);
    }

	virtual inline ssize_t	write(SockTraits::SockDescriptor fd, void* buffer, size_t s)
    {
      return ProtPolicy::write(fd, buffer, s);
    }

	ssize_t					api_read(zia::api::Resource fd, void *buffer, size_t s)
	{
		return ProtPolicy::write((SockTraits::SockDescriptor)fd, buffer, s);
	}

	ssize_t					api_write(zia::api::Resource fd, void *buffer, size_t s)
	{
		return ProtPolicy::read((SockTraits::SockDescriptor)fd, buffer, s);
	}

  private:
    int				_errcode;
    SockTraits::SockDescriptor 	_socket;
    struct sockaddr_in	 	*_addr;

    bool			_errmanagement(bool);

  };

  template<class ProtPolicy>
  Socket<ProtPolicy>::Socket()
    : ProtPolicy(), _errcode(0), _socket(0), _addr(NULL)
  {
    if ((this->_socket = this->socket()) < 0)
      this->_errcode = SockTraits::getLastError();
  }

  template<class ProtPolicy>
  Socket<ProtPolicy>::Socket(SockTraits::SockDescriptor s)
    : ProtPolicy(), _errcode(0), _socket(s), _addr(NULL)
  {
    if (this->_socket < 0)
      this->_errcode = SockTraits::getLastError();
  }

  template<class ProtPolicy>
  Socket<ProtPolicy>::~Socket()
  {
    this->close();
  }

  template<class ProtPolicy>
  Socket<ProtPolicy>::Socket(const Socket<ProtPolicy> &s)
    : ProtPolicy(), _errcode(s._errcode), _socket(s._socket), _addr()
  {
    if (!s._addr)
      return;
    this->_addr = new struct sockaddr_in;
    memcpy(this->_addr, s._addr, sizeof(*this->_addr));
  }

  template<class ProtPolicy>
  Socket<ProtPolicy>	&Socket<ProtPolicy>::operator=(const Socket<ProtPolicy> &s)
  {
    if (this != &s)
      {
	this->_errcode = s._errcode;
	this->_socket = s._socket;
	if (this->_addr)
	  delete this->_addr;
	this->_addr = NULL;
	if (s._addr)
	  {
	    this->_addr = new struct sockaddr_in;
	    memcpy(this->_addr, s._addr, sizeof(*this->_addr));
	  }
      }
    return *this;
  }

  template<class ProtPolicy>
  Socket<ProtPolicy>::operator int()
  {
    return (int)this->_socket;
  }

  template<class ProtPolicy>
  int	Socket<ProtPolicy>::operator+(int i)
  {
    return (int)(this->_socket + i);
  }

  //A refaire avecune classe HostAddr ?
  template<class ProtPolicy>
  bool		Socket<ProtPolicy>::bind(const std::string &ip, const unsigned short port)
  {
    struct sockaddr_in	addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (ip == "any")
      addr.sin_addr.s_addr = INADDR_ANY;
    else
      addr.sin_addr.s_addr = htons(port);
    return this->_errmanagement(SockTraits::bind(this->_socket, addr));
  }

  template<class ProtPolicy>
  bool		Socket<ProtPolicy>::connect(const std::string &ip, const unsigned short port)
  {
    struct sockaddr_in	addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (ip == "any")
      addr.sin_addr.s_addr = INADDR_ANY;
    else
      addr.sin_addr.s_addr = htons(port);
    return this->_errmanagement(SockTraits::connect(this->_socket, addr));
  }
  
  template<class ProtPolicy>
  bool		Socket<ProtPolicy>::close()
  {
    return this->_errmanagement(SockTraits::close(this->_socket));
  }


  template<class ProtPolicy>
  bool		Socket<ProtPolicy>::ready() const
  {
    return !this->_errcode;
  }

  template<class ProtPolicy>
  void		Socket<ProtPolicy>::clearError()
  {
    this->_errcode = 0;
  }

  template<class ProtPolicy>
  void		Socket<ProtPolicy>::error() const
  {
    SockTraits::printError(this->_errcode);
  }

  //// Private Methods

  template<class ProtPolicy>
  bool		Socket<ProtPolicy>::_errmanagement(bool retval)
  {
    if (!retval)
      this->_errcode = SockTraits::getLastError();
    return retval;
  }
}



#endif
