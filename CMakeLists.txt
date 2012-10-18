cmake_minimum_required (VERSION 2.6)
project (Sophie)

include_directories("includes/")
include_directories("/usr/include/")

link_directories("/lib/")

add_executable(	Sophie
		tools/Sockets/SockTraits.cpp
                tools/Sockets/TCPPolicy.cpp
                src/Acceptor/Acceptor.cpp
                main.cpp
		)
target_link_libraries(
	Sophie
)
