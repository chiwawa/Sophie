#include <stdio.h>
#include <errno.h>
#include <iostream>
#include "Multiplexer/select.h"

namespace zia
{
  namespace Tools
    {

      Multiplexer::Multiplexer(ioCallback* read,
	  ioCallback* write,
	  int maxNbr,
	  int timeOut)
	: _max(0)
	  {
	    (void)maxNbr;
	    FD_ZERO(&_permanent);
	    FD_ZERO(&_read);
	    FD_ZERO(&_write);
	    _cbTab[IMultiplexer::READ] = read;
	    _cbTab[IMultiplexer::WRITE] = write;
	    _timeout.tv_sec = timeOut;
	    _timeout.tv_usec = 0;

	  }

      Multiplexer::~Multiplexer()
	{
	  ;
	}

      Multiplexer::Multiplexer(const Multiplexer&)
	: IMultiplexer()
	{
	  ;
	}

      Multiplexer&	Multiplexer::operator=(const Multiplexer& M)
	{
	  if (this != &M)
	    {
	      ;
	    }
	  return (*this);
	}

      void		Multiplexer::addSocket(Network::ISocket* s, IMultiplexer::flag flag)
	{
	  if (_max < s->getDescriptor())
	    _max = s->getDescriptor();

	  socketCallback	*socket = new socketCallback;

	  socket->socket = s;
	  if (flag == READ)
	    FD_SET(s->getDescriptor(), &_read);
	  else if (flag == WRITE)
	    FD_SET(s->getDescriptor(), &_write);
	  socket->callback = _cbTab[flag];
	}

      void		Multiplexer::addSocket(Network::ISocket* s, ioCallback& cb, IMultiplexer::flag flag)
	{
	  if (_max < s->getDescriptor())
	    _max = s->getDescriptor();

	  socketCallback	*socket = new socketCallback;

	  socket->socket = s;
	  if (flag == READ)
	    FD_SET(s->getDescriptor(), &_read);
	  else if (flag == WRITE)
	    FD_SET(s->getDescriptor(), &_write);
	  socket->callback = &cb;
	}

      void		Multiplexer::addSockets(const std::list<Network::ISocket*>& list, IMultiplexer::flag flag)
	{
	  std::list<Network::ISocket*>::const_iterator	begin = list.begin();
	  std::list<Network::ISocket*>::const_iterator	end = list.end();

	  while (begin != end)
	    {
	      addSocket(*begin, flag);
	      ++begin;
	    }
	}

      void		Multiplexer::addSockets(const std::list<Network::ISocket*>& list, ioCallback& cb, IMultiplexer::flag flag)
	{
	  std::list<Network::ISocket*>::const_iterator	begin = list.begin();
	  std::list<Network::ISocket*>::const_iterator	end = list.end();

	  while (begin != end)
	    {
	      addSocket(*begin, cb, flag);
	      ++begin;
	    }
	}

      void		Multiplexer::clear(IMultiplexer::flag flag)
	{
	  if (flag == READ)
	    FD_ZERO(&_read);
	  else if (flag == WRITE)
	    FD_ZERO(&_write);
	  FD_COPY(&_permanent, &_read);
	  FD_COPY(&_permanent, &_write);
	  _polled.clear();
	}

      int	Multiplexer::process(void)
	{
	  int	res = 0;

	  if ((res = select(_max + 1, &_read, &_write, NULL, &_timeout)) < 0)
	    perror("select");
	  return (res);
	}

      void		Multiplexer::execute(void)
	{
	  std::list<socketCallback*>::const_iterator	begin = _polled.begin();
	  std::list<socketCallback*>::const_iterator	end = _polled.end();

	  while (begin != end)
	    {
	      if (FD_ISSET((*begin)->socket->getDescriptor(), &_read)
		  || FD_ISSET((*begin)->socket->getDescriptor(), &_write))
		(*(*begin)->callback)((*begin)->socket);
	      ++begin;
	    }

	}

      void		Multiplexer::addPermanent(Network::ISocket* s, const IMultiplexer::flag flag)
	{
	  FD_SET(s->getDescriptor(), &_permanent);
	  this->addSocket(s, flag);
	}

      void		Multiplexer::addPermanent(Network::ISocket* s, ioCallback& cb, const IMultiplexer::flag flag)
	{
	  FD_SET(s->getDescriptor(), &_permanent);
	  addSocket(s, cb, flag);
	}

    }
}
