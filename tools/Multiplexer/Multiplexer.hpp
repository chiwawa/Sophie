#ifndef __MULTIPLEXER__
#define __MULTIPLEXER__

#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
  #define  __BSD__MULTIPLEXER__
  #include "kqueue.h"
  #include "lightKqueue.h"

#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
  #define __BSD_MULTIPLEXER
  #include "kqueue.h"
  #include "lightKqueue.h"

#elif defined(__OpenBSD__) || defined(__OpenBSD_kernel__)
  #define __BSD__MULTIPLEXER__
  #include "kqueue.h"
  #include "lightKqueue.h"

#elif defined(linux) || defined(__linux)
  #define __LINUX_MULTIPLEXER
  #include "epoll.h"
  #include "lightEpoll.h"

#elif defined(_WIN32) || defined(__WIN32__)
  #define __WIN_MULTIPLEXER
  #include "select.h"

#else
  #error "Can't config Multiplexer : uknown Operating system"
# endif



#endif /* __MULTIPLEXER__ */
