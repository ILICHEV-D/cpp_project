# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danililichev/Desktop/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danililichev/Desktop/test/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/proj.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/proj.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/proj.dir/flags.make

src/CMakeFiles/proj.dir/main.cpp.o: src/CMakeFiles/proj.dir/flags.make
src/CMakeFiles/proj.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danililichev/Desktop/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/proj.dir/main.cpp.o"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj.dir/main.cpp.o -c /Users/danililichev/Desktop/test/src/main.cpp

src/CMakeFiles/proj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj.dir/main.cpp.i"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danililichev/Desktop/test/src/main.cpp > CMakeFiles/proj.dir/main.cpp.i

src/CMakeFiles/proj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj.dir/main.cpp.s"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danililichev/Desktop/test/src/main.cpp -o CMakeFiles/proj.dir/main.cpp.s

src/CMakeFiles/proj.dir/game.cpp.o: src/CMakeFiles/proj.dir/flags.make
src/CMakeFiles/proj.dir/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danililichev/Desktop/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/proj.dir/game.cpp.o"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj.dir/game.cpp.o -c /Users/danililichev/Desktop/test/src/game.cpp

src/CMakeFiles/proj.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj.dir/game.cpp.i"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danililichev/Desktop/test/src/game.cpp > CMakeFiles/proj.dir/game.cpp.i

src/CMakeFiles/proj.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj.dir/game.cpp.s"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danililichev/Desktop/test/src/game.cpp -o CMakeFiles/proj.dir/game.cpp.s

# Object files for target proj
proj_OBJECTS = \
"CMakeFiles/proj.dir/main.cpp.o" \
"CMakeFiles/proj.dir/game.cpp.o"

# External object files for target proj
proj_EXTERNAL_OBJECTS =

src/proj: src/CMakeFiles/proj.dir/main.cpp.o
src/proj: src/CMakeFiles/proj.dir/game.cpp.o
src/proj: src/CMakeFiles/proj.dir/build.make
src/proj: src/CMakeFiles/proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danililichev/Desktop/test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable proj"
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/proj.dir/build: src/proj

.PHONY : src/CMakeFiles/proj.dir/build

src/CMakeFiles/proj.dir/clean:
	cd /Users/danililichev/Desktop/test/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/proj.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/proj.dir/clean

src/CMakeFiles/proj.dir/depend:
	cd /Users/danililichev/Desktop/test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danililichev/Desktop/test /Users/danililichev/Desktop/test/src /Users/danililichev/Desktop/test/cmake-build-debug /Users/danililichev/Desktop/test/cmake-build-debug/src /Users/danililichev/Desktop/test/cmake-build-debug/src/CMakeFiles/proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/proj.dir/depend

