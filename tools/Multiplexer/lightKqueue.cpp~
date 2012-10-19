#include <cstdio>
#include <cstring>

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

#include "Multiplexer/IMultiplexer.hpp"
#include "Multiplexer/lightKqueue.h"

namespace zia
{
  namespace Tools
    {
      static const int	__flagTab[2] = {EVFILT_READ, EVFILT_WRITE};

      lightMultiplexer::lightMultiplexer(IMultiplexer::flag flag,
					ioCallback* cb,
					Network::ISocket* s,
					int timeout)
	: _flag(__flagTab[flag]), _eventNbr(0), _evlist(new struct kevent), _socket(s), _callback(cb)
	{
	  if ((_queueFd = kqueue()) < 0)
	    perror("kqueue");

	  if (timeout != -1)
	    {
	      _timeOut = new struct timespec;
	      _timeOut->tv_sec = timeout;
	      _timeOut->tv_nsec = 0;
	    }
	  else
	    _timeOut = 0;
	}

      lightMultiplexer::~lightMultiplexer()
	{
	  ::close(this->_queueFd);
	  if (_timeOut)
	    delete this->_timeOut;
	  delete _evlist;
	}

      lightMultiplexer::lightMultiplexer(const lightMultiplexer& src)
	: _flag(src._flag),
	  _eventNbr(0),
	  _queueFd(src._queueFd),
	  _socket(src._socket),
	  _callback(src._callback)
	{
	  _timeOut = new struct timespec;
	  *_timeOut = *src._timeOut;
	}

      lightMultiplexer&	lightMultiplexer::operator=(const lightMultiplexer& src)
	{
	  if (this != &src)
	    {
	      this->_flag = src._flag;
	      this->_eventNbr = 0;
	      this->_queueFd = src._queueFd;
	      this->_socket = src._socket;
	      this->_callback = src._callback;
	      _timeOut = new struct timespec;
	      *_timeOut = *src._timeOut;
	    }
	  return (*this);
	}


      int			lightMultiplexer::process(void)
	{
	  struct kevent	_scklist;

	  EV_SET(&_scklist, _socket->getDescriptor(), _flag, EV_ADD | EV_ENABLE, 0, 0, 0);
	  if ((_eventNbr = kevent(_queueFd, &_scklist, 1, _evlist, 1, _timeOut)) < 0)
	    perror("kevent");
	  return (_eventNbr);
	}

      void			lightMultiplexer::execute(void)
	{
	  if (_evlist->flags & EV_ERROR) 
	    {
	      std::cerr << "kqueue : on socket polling - " << strerror(_evlist->data) << std::endl;
	      _socket->close();
	    }
	  else if (_evlist->flags & EV_EOF)
	    _socket->close();
	  else
	    (*_callback)(_socket);
	}
    }
}
