# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/labell_s/Astek/git/Boophie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/labell_s/Astek/git/Boophie

# Include any dependencies generated for this target.
include CMakeFiles/Boophie.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Boophie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Boophie.dir/flags.make

CMakeFiles/Boophie.dir/src/Client.cpp.o: CMakeFiles/Boophie.dir/flags.make
CMakeFiles/Boophie.dir/src/Client.cpp.o: src/Client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/labell_s/Astek/git/Boophie/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Boophie.dir/src/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Boophie.dir/src/Client.cpp.o -c /home/labell_s/Astek/git/Boophie/src/Client.cpp

CMakeFiles/Boophie.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boophie.dir/src/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/labell_s/Astek/git/Boophie/src/Client.cpp > CMakeFiles/Boophie.dir/src/Client.cpp.i

CMakeFiles/Boophie.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boophie.dir/src/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/labell_s/Astek/git/Boophie/src/Client.cpp -o CMakeFiles/Boophie.dir/src/Client.cpp.s

CMakeFiles/Boophie.dir/src/Client.cpp.o.requires:
.PHONY : CMakeFiles/Boophie.dir/src/Client.cpp.o.requires

CMakeFiles/Boophie.dir/src/Client.cpp.o.provides: CMakeFiles/Boophie.dir/src/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/Boophie.dir/build.make CMakeFiles/Boophie.dir/src/Client.cpp.o.provides.build
.PHONY : CMakeFiles/Boophie.dir/src/Client.cpp.o.provides

CMakeFiles/Boophie.dir/src/Client.cpp.o.provides.build: CMakeFiles/Boophie.dir/src/Client.cpp.o

CMakeFiles/Boophie.dir/src/Server.cpp.o: CMakeFiles/Boophie.dir/flags.make
CMakeFiles/Boophie.dir/src/Server.cpp.o: src/Server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/labell_s/Astek/git/Boophie/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Boophie.dir/src/Server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Boophie.dir/src/Server.cpp.o -c /home/labell_s/Astek/git/Boophie/src/Server.cpp

CMakeFiles/Boophie.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boophie.dir/src/Server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/labell_s/Astek/git/Boophie/src/Server.cpp > CMakeFiles/Boophie.dir/src/Server.cpp.i

CMakeFiles/Boophie.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boophie.dir/src/Server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/labell_s/Astek/git/Boophie/src/Server.cpp -o CMakeFiles/Boophie.dir/src/Server.cpp.s

CMakeFiles/Boophie.dir/src/Server.cpp.o.requires:
.PHONY : CMakeFiles/Boophie.dir/src/Server.cpp.o.requires

CMakeFiles/Boophie.dir/src/Server.cpp.o.provides: CMakeFiles/Boophie.dir/src/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/Boophie.dir/build.make CMakeFiles/Boophie.dir/src/Server.cpp.o.provides.build
.PHONY : CMakeFiles/Boophie.dir/src/Server.cpp.o.provides

CMakeFiles/Boophie.dir/src/Server.cpp.o.provides.build: CMakeFiles/Boophie.dir/src/Server.cpp.o

CMakeFiles/Boophie.dir/main.cpp.o: CMakeFiles/Boophie.dir/flags.make
CMakeFiles/Boophie.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/labell_s/Astek/git/Boophie/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Boophie.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Boophie.dir/main.cpp.o -c /home/labell_s/Astek/git/Boophie/main.cpp

CMakeFiles/Boophie.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boophie.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/labell_s/Astek/git/Boophie/main.cpp > CMakeFiles/Boophie.dir/main.cpp.i

CMakeFiles/Boophie.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boophie.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/labell_s/Astek/git/Boophie/main.cpp -o CMakeFiles/Boophie.dir/main.cpp.s

CMakeFiles/Boophie.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Boophie.dir/main.cpp.o.requires

CMakeFiles/Boophie.dir/main.cpp.o.provides: CMakeFiles/Boophie.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Boophie.dir/build.make CMakeFiles/Boophie.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Boophie.dir/main.cpp.o.provides

CMakeFiles/Boophie.dir/main.cpp.o.provides.build: CMakeFiles/Boophie.dir/main.cpp.o

# Object files for target Boophie
Boophie_OBJECTS = \
"CMakeFiles/Boophie.dir/src/Client.cpp.o" \
"CMakeFiles/Boophie.dir/src/Server.cpp.o" \
"CMakeFiles/Boophie.dir/main.cpp.o"

# External object files for target Boophie
Boophie_EXTERNAL_OBJECTS =

Boophie: CMakeFiles/Boophie.dir/src/Client.cpp.o
Boophie: CMakeFiles/Boophie.dir/src/Server.cpp.o
Boophie: CMakeFiles/Boophie.dir/main.cpp.o
Boophie: CMakeFiles/Boophie.dir/build.make
Boophie: CMakeFiles/Boophie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Boophie"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Boophie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Boophie.dir/build: Boophie
.PHONY : CMakeFiles/Boophie.dir/build

CMakeFiles/Boophie.dir/requires: CMakeFiles/Boophie.dir/src/Client.cpp.o.requires
CMakeFiles/Boophie.dir/requires: CMakeFiles/Boophie.dir/src/Server.cpp.o.requires
CMakeFiles/Boophie.dir/requires: CMakeFiles/Boophie.dir/main.cpp.o.requires
.PHONY : CMakeFiles/Boophie.dir/requires

CMakeFiles/Boophie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Boophie.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Boophie.dir/clean

CMakeFiles/Boophie.dir/depend:
	cd /home/labell_s/Astek/git/Boophie && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/labell_s/Astek/git/Boophie /home/labell_s/Astek/git/Boophie /home/labell_s/Astek/git/Boophie /home/labell_s/Astek/git/Boophie /home/labell_s/Astek/git/Boophie/CMakeFiles/Boophie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Boophie.dir/depend
