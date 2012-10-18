#include <stdio.h>
#include <errno.h>
#include <iostream>
#include "lightMultiplexer/select.h"

namespace zia
{
  namespace Tools
    {

      lightMultiplexer::lightMultiplexer(IlightMultiplexer::flag flag,
	  ioCallback* callback,
	  Network::ISocket* s,
	  int timeOut)
	: _flag(flag), _eventNbr(0), _socket(s), _callback(callback)
	{
	  FD_ZERO(&_evlist);
	  _timeout.tv_sec = timeOut;
	  _timeout.tv_usec = 0;
	}

      lightMultiplexer::~lightMultiplexer()
	{
	  ;
	}

      lightMultiplexer::lightMultiplexer(const lightMultiplexer& src)
	: _flag(src._flag), _eventNbr(0), _timeout(src._timeout), _evlist(src._evlist), _socket(src._socket), _callback(src._callback) 
	{
	  ;
	}

      lightMultiplexer&	lightMultiplexer::operator=(const lightMultiplexer& src)
	{
	  if (this != &src)
	    {
	      _flag = src._flag;
	      _eventNbr = 0;
	      _timeout = src._timeout;
	      _evlist = src._evlist;
	      _socket = src._socket;
	      _callback = src._callback;
	    }
	  return (*this);
	}

      int	lightMultiplexer::process(void)
	{
	  if (_flag == IMultiplexer::READ)
	    {
	      if ((_eventNbr = select(_socket->getDescriptor() + 1, &_evlist, 0, 0, &_timeout)) < 0)
		perror("select");
	    }
	  else
	    {
	      if ((_eventNbr = select(_socket->getDescriptor() + 1, 0, &_evlist, 0, &_timeout)) < 0)
		perror("select");
	    }
	  return (_eventNbr);
	}

      void		lightMultiplexer::execute(void)
	{
	  if (FD_ISSET((_socket->getDescriptor(), &_evlist)))
	    (*callback)(_socket);
	}
    }
}
