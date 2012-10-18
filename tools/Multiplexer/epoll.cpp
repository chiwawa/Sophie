#include <algorithm>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include "Multiplexer/epoll.h"

static void	_deleteSocketCallback(const socketCallback* socket)
{
  delete socket;
}

namespace Tools
{
  Multiplexer::Multiplexer(ioCallback* read,
			   ioCallback* write,
			   int nbrMax,
			   int timeout)
    : _nbrMax(nbrMax), _resNbr(0)
  {
    std::cout << "Entree dans la fonction Multiplexer" << std::endl;
    if ((this->_efd = epoll_create(nbrMax)) < 0)
      perror("epoll_create");
    _eventsRes = new struct epoll_event[nbrMax];

    _evTab[IMultiplexer::READ].events = EPOLLIN | EPOLLPRI;
    _cbTab[IMultiplexer::READ] = read;

    _evTab[IMultiplexer::WRITE].events = EPOLLOUT;
    _cbTab[IMultiplexer::WRITE] = write;

    _timeOut = timeout;
  }

  Multiplexer::~Multiplexer()
  {
    delete  this->_eventsRes;
    ::close(this->_efd);
    std::for_each(this->_polled.begin(), this->_polled.end(), &_deleteSocketCallback);
  }

  Multiplexer::Multiplexer(const Multiplexer& src)
    : IMultiplexer()
  {
    ;
  }

  Multiplexer&	Multiplexer::operator=(const Multiplexer& src)
  {
    if (this != &src)
      {
	;
      }
    return (*this);
  }

  void	Multiplexer::addSocket(Network::ISocket* s, const IMultiplexer::flag flag)
  {
    socketCallback	*socket = new socketCallback;

    socket->callback = _cbTab[flag];
    socket->socket = s;
    _evTab[flag].data.ptr = (void*)socket;

    _polled.push_back(socket);
    if (epoll_ctl(this->_efd, EPOLL_CTL_ADD, s->getDescriptor(), &_evTab[flag]) < 0)
      perror("epoll_ctl");
    std::cout << "last added socket : " << (int)s->getDescriptor() << std::endl;
  }

  void	Multiplexer::addSocket(Network::ISocket* s, ioCallback& cb, const IMultiplexer::flag flag)
  {
    socketCallback	*socket = new socketCallback;

    socket->callback = &cb;
    socket->socket = s;
    _evTab[flag].data.ptr = (void*)socket;

    _polled.push_back(socket);
    if (epoll_ctl(this->_efd, EPOLL_CTL_ADD, s->getDescriptor(), &_evTab[flag]) < 0)
      perror("epoll_ctl");
  }


  void	Multiplexer::addSockets(const std::list<Network::ISocket*>& list, const IMultiplexer::flag flag)
  {
    std::list<Network::ISocket*>::const_iterator	begin = list.begin();
    std::list<Network::ISocket*>::const_iterator	end = list.end();

    while (begin != end)
      {
	this->addSocket(*begin, flag);
	++begin;
      }

  }

  void	Multiplexer::addSockets(const std::list<Network::ISocket*>& list, ioCallback& cb, const IMultiplexer::flag flag)
  {
    std::list<Network::ISocket*>::const_iterator	begin = list.begin();
    std::list<Network::ISocket*>::const_iterator	end = list.end();

    while (begin != end)
      {
	this->addSocket(*begin, cb, flag);
	++begin;
      }

  }


  int Multiplexer::process(void)
  {
    if ((_resNbr = epoll_wait(this->_efd, this->_eventsRes, this->_nbrMax, _timeOut)) < 0)
      perror("epoll_wait");
    return (_resNbr);
  }

  void	Multiplexer::execute(void)
  {
    socketCallback* current;

    for (int index = 0;index < _resNbr; ++index)
      {
	current = reinterpret_cast<socketCallback*>(_eventsRes[index].data.ptr);
	if (!(_eventsRes[index].events & EPOLLHUP)
	    && !(_eventsRes[index].events & EPOLLERR))
	  {
	    if (current == NULL)
	      std::cout << "duong_a a raison --'" << std::endl;
	    else
	      std::cout << "Add current : " << std::hex << current << std::endl;

	    if (current->callback == NULL)
	      std::cout << "callback est null" << std::endl;
	    else
	      std::cout << "Add current->callback : " << std::hex << current->callback << std::endl;

	    if (current->socket == NULL)
	      std::cout << "socket est null" << std::endl;
	    else
	      std::cout << "Add current : " << std::hex << current->socket << std::endl;
	    std::cout << "GAH ?!" << std::endl;
	    (*(current->callback))(current->socket);
	  }
	else if (_eventsRes[index].events & EPOLLERR)
	  {
	    int	ret = 0;
	    socklen_t	sizeofret = sizeof(ret);

	    if (getsockopt(current->socket->getDescriptor(), SOL_SOCKET, SO_ERROR, &ret, &sizeofret) == -1)
	      perror("getsockopt");
	    else
	      std::cerr << "epoll_wait : on socket polling - " << strerror(ret) << std::endl;
	  }
	else
	  this->_close(current->socket);
      }
  }

  void	Multiplexer::clear(const IMultiplexer::flag flag)
  {
    std::list<socketCallback*>::const_iterator	begin = _polled.begin();
    std::list<socketCallback*>::const_iterator	end = _polled.end();

    while (begin != end)
      {
	if (epoll_ctl(this->_efd, EPOLL_CTL_DEL, (*begin)->socket->getDescriptor(), 0) < 0)
	  perror("epoll_ctl");
	++begin;
      }
    _polled.clear();
  }

  static void	_deleteSocketCallbackBySocket(const socketCallback* socket)
  {
    ;
  }

  inline void	Multiplexer::_close(Network::ISocket *s)
  {
    // et si il est close la et qu'on essaye de le close plus loin?
    std::list<socketCallback*>::iterator	begin = _polled.begin();
    std::list<socketCallback*>::iterator	end = _polled.end();
	  
    while (begin != end)
      {
	if ((*begin)->socket == s)
	  {
	    s->close();
	    delete (*begin);
	    return ;
	  }
	++begin;
      }
  }
}
