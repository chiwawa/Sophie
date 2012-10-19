cmake_minimum_required (VERSION 2.6)
project (Boophie)

set(CMAKE_CXX_FLAGS "-ggdb")
set(CMAKE_EXE_LINKER_FLAGS "-ggdb")

include_directories("includes/")

add_executable(	Boophie
                src/Client.cpp
		src/Server.cpp
                main.cpp
		)

link_directories(/usr/lib)
target_link_libraries(
	Boophie
	boost_system
	pthread
	boost_thread
)
