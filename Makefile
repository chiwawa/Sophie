# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Chiwawa/Documents/cpp/SophieGit/Sophie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Chiwawa/Documents/cpp/SophieGit/Sophie

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Chiwawa/Documents/cpp/SophieGit/Sophie/CMakeFiles /Users/Chiwawa/Documents/cpp/SophieGit/Sophie/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Chiwawa/Documents/cpp/SophieGit/Sophie/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Sophie

# Build rule for target.
Sophie: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Sophie
.PHONY : Sophie

# fast build rule for target.
Sophie/fast:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/build
.PHONY : Sophie/fast

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/main.cpp.s
.PHONY : main.cpp.s

src/Acceptor/Acceptor.o: src/Acceptor/Acceptor.cpp.o
.PHONY : src/Acceptor/Acceptor.o

# target to build an object file
src/Acceptor/Acceptor.cpp.o:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Acceptor/Acceptor.cpp.o
.PHONY : src/Acceptor/Acceptor.cpp.o

src/Acceptor/Acceptor.i: src/Acceptor/Acceptor.cpp.i
.PHONY : src/Acceptor/Acceptor.i

# target to preprocess a source file
src/Acceptor/Acceptor.cpp.i:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Acceptor/Acceptor.cpp.i
.PHONY : src/Acceptor/Acceptor.cpp.i

src/Acceptor/Acceptor.s: src/Acceptor/Acceptor.cpp.s
.PHONY : src/Acceptor/Acceptor.s

# target to generate assembly for a file
src/Acceptor/Acceptor.cpp.s:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Acceptor/Acceptor.cpp.s
.PHONY : src/Acceptor/Acceptor.cpp.s

src/Server/Server.o: src/Server/Server.cpp.o
.PHONY : src/Server/Server.o

# target to build an object file
src/Server/Server.cpp.o:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Server/Server.cpp.o
.PHONY : src/Server/Server.cpp.o

src/Server/Server.i: src/Server/Server.cpp.i
.PHONY : src/Server/Server.i

# target to preprocess a source file
src/Server/Server.cpp.i:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Server/Server.cpp.i
.PHONY : src/Server/Server.cpp.i

src/Server/Server.s: src/Server/Server.cpp.s
.PHONY : src/Server/Server.s

# target to generate assembly for a file
src/Server/Server.cpp.s:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/src/Server/Server.cpp.s
.PHONY : src/Server/Server.cpp.s

tools/Sockets/SockTraits.o: tools/Sockets/SockTraits.cpp.o
.PHONY : tools/Sockets/SockTraits.o

# target to build an object file
tools/Sockets/SockTraits.cpp.o:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/SockTraits.cpp.o
.PHONY : tools/Sockets/SockTraits.cpp.o

tools/Sockets/SockTraits.i: tools/Sockets/SockTraits.cpp.i
.PHONY : tools/Sockets/SockTraits.i

# target to preprocess a source file
tools/Sockets/SockTraits.cpp.i:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/SockTraits.cpp.i
.PHONY : tools/Sockets/SockTraits.cpp.i

tools/Sockets/SockTraits.s: tools/Sockets/SockTraits.cpp.s
.PHONY : tools/Sockets/SockTraits.s

# target to generate assembly for a file
tools/Sockets/SockTraits.cpp.s:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/SockTraits.cpp.s
.PHONY : tools/Sockets/SockTraits.cpp.s

tools/Sockets/TCPPolicy.o: tools/Sockets/TCPPolicy.cpp.o
.PHONY : tools/Sockets/TCPPolicy.o

# target to build an object file
tools/Sockets/TCPPolicy.cpp.o:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/TCPPolicy.cpp.o
.PHONY : tools/Sockets/TCPPolicy.cpp.o

tools/Sockets/TCPPolicy.i: tools/Sockets/TCPPolicy.cpp.i
.PHONY : tools/Sockets/TCPPolicy.i

# target to preprocess a source file
tools/Sockets/TCPPolicy.cpp.i:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/TCPPolicy.cpp.i
.PHONY : tools/Sockets/TCPPolicy.cpp.i

tools/Sockets/TCPPolicy.s: tools/Sockets/TCPPolicy.cpp.s
.PHONY : tools/Sockets/TCPPolicy.s

# target to generate assembly for a file
tools/Sockets/TCPPolicy.cpp.s:
	$(MAKE) -f CMakeFiles/Sophie.dir/build.make CMakeFiles/Sophie.dir/tools/Sockets/TCPPolicy.cpp.s
.PHONY : tools/Sockets/TCPPolicy.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... Sophie"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Acceptor/Acceptor.o"
	@echo "... src/Acceptor/Acceptor.i"
	@echo "... src/Acceptor/Acceptor.s"
	@echo "... src/Server/Server.o"
	@echo "... src/Server/Server.i"
	@echo "... src/Server/Server.s"
	@echo "... tools/Sockets/SockTraits.o"
	@echo "... tools/Sockets/SockTraits.i"
	@echo "... tools/Sockets/SockTraits.s"
	@echo "... tools/Sockets/TCPPolicy.o"
	@echo "... tools/Sockets/TCPPolicy.i"
	@echo "... tools/Sockets/TCPPolicy.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

