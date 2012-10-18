
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/epoll.h>
#include "Multiplexer/lightEpoll.h"

namespace Tools
{
  static int	__flagTab[2] =
    {
      (EPOLLIN | EPOLLPRI),
      (EPOLLOUT)
    };

  lightMultiplexer::lightMultiplexer(IMultiplexer::flag flag,
				     ioCallback* cb,
				     Network::ISocket* s,
				     int timeout)
    : 
    _eventNbr(0),
    _timeOut(timeout),
    _evlist(new struct epoll_event),
    _eventRes(new struct epoll_event),
    _socket(s),
    _callback(cb)
  {
    if ((_queueFd = epoll_create(1)) < 0)
      perror("epoll_create");
    _evlist->events =  __flagTab[flag];
  }

  lightMultiplexer::~lightMultiplexer()
  {
    ::close(_queueFd);
    delete _eventRes;
    delete _evlist;
  }

  lightMultiplexer::lightMultiplexer(const lightMultiplexer& src)
    : 
    _eventNbr(0),
    _queueFd(src._queueFd),
    _timeOut(src._timeOut),
    _socket(src._socket),
    _callback(src._callback)
  {
  }

  lightMultiplexer&	lightMultiplexer::operator=(const lightMultiplexer& src)
  {
    if (this != &src)
      {
	_eventNbr = 0;
	_timeOut = src._timeOut;
	_queueFd = src._queueFd;
	_socket = src._socket;
	_callback = src._callback;
      }
    return (*this);
  }

  int lightMultiplexer::process(void)
  {
    if (epoll_ctl(_queueFd, EPOLL_CTL_ADD, _socket->getDescriptor(), _evlist) < 0)
      perror("epoll_ctl");

    if ((_eventNbr = epoll_wait(_queueFd, _eventRes, 1, _timeOut)) < 0)
      perror("epoll_wait");
    return (_eventNbr);
  }

  void	lightMultiplexer::execute(void)
  {
    if (!(_eventRes->events & EPOLLHUP)
	&& !(_eventRes->events & EPOLLERR))
      (*(_callback))(_socket);
    else if (_eventRes->events & EPOLLERR)
      {
	int	ret = 0;
	socklen_t sizeofret = sizeof(ret);

	if (getsockopt(_socket->getDescriptor(), SOL_SOCKET, SO_ERROR, &ret, &sizeofret) == -1)
	  perror("getsockopt");
	else
	  std::cerr << "epoll_wait : on socket polling - " << strerror(ret) << std::endl;
      }
    else
      _socket->close();
  }
}


