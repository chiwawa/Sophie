cmake_minimum_required (VERSION 2.6)
project (Sophie)

set(CMAKE_CXX_FLAGS "-ggdb")
set(CMAKE_EXE_LINKER_FLAGS "-ggdb")

include_directories("includes/")
include_directories("tools/")

SET(SYSTEM_NAME "${SYSTEM_NAME}" CACHE INTERNAL "")

MESSAGE("TEST "  ${SYSTEM_NAME})

IF (WIN32)
  set (MULTIPLEXER
    src/Multiplexer/select.cpp)
ELSE (WIN32)

  EXEC_PROGRAM(uname OUTPUT_VARIABLE SYSTEM_NAME)

  IF (${SYSTEM_NAME} STREQUAL "Linux")
    MESSAGE("------------------------ LINUX compilation")
    set (MULTIPLEXER
      tools/Multiplexer/epoll.cpp)
    set (LIGHT_MULTIPLEXER
      tools/Multiplexer/lightEpoll.cpp)
    set (DL
      -ldl)
  ENDIF (${SYSTEM_NAME} STREQUAL "Linux")

  IF (${SYSTEM_NAME} STREQUAL "FreeBSD")
     MESSAGE("----BSD")
  ENDIF (${SYSTEM_NAME} STREQUAL "FreeBSD")

  IF (APPLE)
    MESSAGE("------------------------ FREEBSD compilation")
    set (MULTIPLEXER
      tools/Multiplexer/kqueue.cpp)
    set (LIGHT_MULTIPLEXER
      tools/Multiplexer/lightKqueue.cpp)
  ENDIF (${SYSTEM_NAME} STREQUAL "FreeBSD")
ENDIf (WIN32)

add_executable(	Sophie
		tools/Sockets/SockTraits.cpp
                tools/Sockets/TCPPolicy.cpp
                src/Acceptor/Acceptor.cpp
		src/Server/Server.cpp
		${MULTIPLEXER}
                ${LIGHT_MULTIPLEXER}
                main.cpp
		)
target_link_libraries(
	Sophie
)
