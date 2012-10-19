
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <map>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include "Multiplexer/kqueue.h"

static void	_deleteSocketCallback(const socketCallback* socket)
{
  delete socket;
}

namespace Tools
{
  Multiplexer::Multiplexer(ioCallback* read,
			   ioCallback* write,
			   int maxClient,
			   int timeout)
    : _evlist(0), _socketNbr(0), _maxClient(maxClient)
  {
    if ((_queueFd = kqueue()) < 0)
      perror("kqueue");
    _flag[IMultiplexer::READ] = EVFILT_READ;
    _flag[IMultiplexer::WRITE] = EVFILT_WRITE;
    _cbTab[IMultiplexer::READ] = read;
    _cbTab[IMultiplexer::WRITE] = write;
    _scklist = new struct kevent[maxClient];
    _evlist = new struct kevent[maxClient];
    _setTable();

    if (timeout != -1)
      {
	_timeOut = new struct timespec;
	_timeOut->tv_sec = timeout;
	_timeOut->tv_nsec = 0;
      }
    else
	    _timeOut = 0;
	}

      Multiplexer::~Multiplexer()
	{
	  ::close(this->_queueFd);
	  std::for_each(this->_polled.begin(), this->_polled.end(), &_deleteSocketCallback);
	  delete[] this->_scklist;
          delete[] this->_evlist;
	  if (_timeOut)
	    delete this->_timeOut;
	}

      Multiplexer::Multiplexer(const Multiplexer&)
	: Tools::IMultiplexer()
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
 
      void			Multiplexer::addSocket(Network::ISocket* s, const IMultiplexer::flag flag)
	{
	  socketCallback*	socket = new socketCallback;

	  socket->socket = s;
	  socket->callback = _cbTab[flag];

	  int index = _findNextIndex();
	  _clientIndexMap[s] = index;
	  _polled.push_back(socket);
	  EV_SET(&_scklist[index], s->getDescriptor(), _flag[flag], EV_ADD | EV_ENABLE, 0, 0, socket);
	  ++_socketNbr;
	}

      void			Multiplexer::addSocket(Network::ISocket* s, ioCallback& cb, const IMultiplexer::flag flag)
	{
	  socketCallback*	socket = new socketCallback;

	  socket->socket = s;
	  socket->callback = &cb;

	  int index = _findNextIndex();
	  _clientIndexMap[s] = index;
	  EV_SET(&_scklist[index], s->getDescriptor(), _flag[flag], EV_ADD | EV_ENABLE, 0, 0, socket);
	  ++_socketNbr;
	}

	void			Multiplexer::addSockets(const std::list<Network::ISocket*>& list, const IMultiplexer::flag flag)
	  {
	    std::list<Network::ISocket*>::const_iterator	begin = list.begin();
	    std::list<Network::ISocket*>::const_iterator	end = list.end();

	    while (begin != end)
	      {
		addSocket((*begin), flag);
		++begin;
	      }
	  }

	void			Multiplexer::addSockets(const std::list<Network::ISocket*>& list, ioCallback& cb, const IMultiplexer::flag flag)
	  {
	    std::list<Network::ISocket*>::const_iterator	begin = list.begin();
	    std::list<Network::ISocket*>::const_iterator	end = list.end();

	    while (begin != end)
	      {
		addSocket((*begin), cb, flag);
		++begin;
	      }
	  }

	void			Multiplexer::clear(const IMultiplexer::flag flag)
	  {
	    (void)flag;
	    if (_scklist != 0)
	      {
		delete _scklist;
		_scklist = new struct kevent[_maxClient];
		_setTable();
		_socketNbr = 0;
	      }
	    if (_evlist != 0)
	      {
		delete _evlist;
		_evlist = new struct kevent[_maxClient];
		_socketNbr = 0;
	      }
	  }

	int			Multiplexer::process(void)
	  {
	    if ((_eventNbr = kevent(_queueFd, _scklist, _maxClient, _evlist, _maxClient, _timeOut)) < 0)
	      perror("kevent");
	    return (_eventNbr);
	  }

	void			Multiplexer::execute(void)
	  {
	    socketCallback*	current;

	    for (int index = 0; index < _eventNbr; ++index)
	      {
		current = reinterpret_cast<socketCallback*>(_evlist[index].udata);
		if (_evlist[index].flags & EV_ERROR) 
    		  {
		    std::cerr << "kqueue : on socket polling - " << strerror(_evlist[index].data) << std::endl;
		    _close(current->socket);
		    delete current;
		  }
		else if (_evlist[index].flags & EV_EOF)
		  {
		    _close(current->socket);
		    delete current;
		  }
		else
		  (*(current->callback))(current->socket);
	      }
	  }

	int			Multiplexer::_findNextIndex(void)
	  {
	    for (int index = 0; index < _maxClient; ++index)
	      {
		if (_scklist[index].ident == 0)
		  return (index);
	      }
	    return (0);
	  }

	inline void			Multiplexer::_close(Network::ISocket* s)
	  {
	    EV_SET(&_scklist[_clientIndexMap[s]], 0, 0, 0, 0, 0, 0);
	    _clientIndexMap.erase(s);
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

	void				Multiplexer::_setTable(void)
	  {
	    for (int index = 0; index < _maxClient; ++index)
	      EV_SET(&_scklist[index], 0, 0, 0, 0, 0, 0);
	  }
    }
