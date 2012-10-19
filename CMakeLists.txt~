cmake_minimum_required (VERSION 2.6)
project (Sophie)

set(CMAKE_CXX_FLAGS "-ggdb")
set(CMAKE_EXE_LINKER_FLAGS "-ggdb")

include_directories("includes/")
include_directories("tools/")
include_directories("/usr/include/")

link_directories("/lib/")

add_executable(	Sophie
		tools/Sockets/SockTraits.cpp
                tools/Sockets/TCPPolicy.cpp
                src/Acceptor/Acceptor.cpp
		src/Server/Server.cpp
		tools/Multiplexer/epoll.cpp
		tools/Multiplexer/lightEpoll.cpp
                main.cpp
		)
target_link_libraries(
	Sophie
)
