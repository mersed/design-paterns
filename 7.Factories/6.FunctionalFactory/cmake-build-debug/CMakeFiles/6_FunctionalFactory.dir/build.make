# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/6_FunctionalFactory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/6_FunctionalFactory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/6_FunctionalFactory.dir/flags.make

CMakeFiles/6_FunctionalFactory.dir/main.cpp.o: CMakeFiles/6_FunctionalFactory.dir/flags.make
CMakeFiles/6_FunctionalFactory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6_FunctionalFactory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/6_FunctionalFactory.dir/main.cpp.o -c /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/main.cpp

CMakeFiles/6_FunctionalFactory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6_FunctionalFactory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/main.cpp > CMakeFiles/6_FunctionalFactory.dir/main.cpp.i

CMakeFiles/6_FunctionalFactory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6_FunctionalFactory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/main.cpp -o CMakeFiles/6_FunctionalFactory.dir/main.cpp.s

CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.requires

CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.provides: CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/6_FunctionalFactory.dir/build.make CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.provides

CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.provides.build: CMakeFiles/6_FunctionalFactory.dir/main.cpp.o


# Object files for target 6_FunctionalFactory
6_FunctionalFactory_OBJECTS = \
"CMakeFiles/6_FunctionalFactory.dir/main.cpp.o"

# External object files for target 6_FunctionalFactory
6_FunctionalFactory_EXTERNAL_OBJECTS =

6_FunctionalFactory: CMakeFiles/6_FunctionalFactory.dir/main.cpp.o
6_FunctionalFactory: CMakeFiles/6_FunctionalFactory.dir/build.make
6_FunctionalFactory: CMakeFiles/6_FunctionalFactory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6_FunctionalFactory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/6_FunctionalFactory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/6_FunctionalFactory.dir/build: 6_FunctionalFactory

.PHONY : CMakeFiles/6_FunctionalFactory.dir/build

CMakeFiles/6_FunctionalFactory.dir/requires: CMakeFiles/6_FunctionalFactory.dir/main.cpp.o.requires

.PHONY : CMakeFiles/6_FunctionalFactory.dir/requires

CMakeFiles/6_FunctionalFactory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/6_FunctionalFactory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/6_FunctionalFactory.dir/clean

CMakeFiles/6_FunctionalFactory.dir/depend:
	cd /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug /home/mersed/CLionProjects/DesignPatterns/7.Factories/6.FunctionalFactory/cmake-build-debug/CMakeFiles/6_FunctionalFactory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/6_FunctionalFactory.dir/depend

