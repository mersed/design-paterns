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
CMAKE_SOURCE_DIR = /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/good_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/good_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/good_example.dir/flags.make

CMakeFiles/good_example.dir/main.cpp.o: CMakeFiles/good_example.dir/flags.make
CMakeFiles/good_example.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/good_example.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/good_example.dir/main.cpp.o -c /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/main.cpp

CMakeFiles/good_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/good_example.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/main.cpp > CMakeFiles/good_example.dir/main.cpp.i

CMakeFiles/good_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/good_example.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/main.cpp -o CMakeFiles/good_example.dir/main.cpp.s

CMakeFiles/good_example.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/good_example.dir/main.cpp.o.requires

CMakeFiles/good_example.dir/main.cpp.o.provides: CMakeFiles/good_example.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/good_example.dir/build.make CMakeFiles/good_example.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/good_example.dir/main.cpp.o.provides

CMakeFiles/good_example.dir/main.cpp.o.provides.build: CMakeFiles/good_example.dir/main.cpp.o


# Object files for target good_example
good_example_OBJECTS = \
"CMakeFiles/good_example.dir/main.cpp.o"

# External object files for target good_example
good_example_EXTERNAL_OBJECTS =

good_example: CMakeFiles/good_example.dir/main.cpp.o
good_example: CMakeFiles/good_example.dir/build.make
good_example: CMakeFiles/good_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable good_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/good_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/good_example.dir/build: good_example

.PHONY : CMakeFiles/good_example.dir/build

CMakeFiles/good_example.dir/requires: CMakeFiles/good_example.dir/main.cpp.o.requires

.PHONY : CMakeFiles/good_example.dir/requires

CMakeFiles/good_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/good_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/good_example.dir/clean

CMakeFiles/good_example.dir/depend:
	cd /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug /home/mersed/CLionProjects/DesignPatterns/4.InterfaceSegregationPrinciple/good_example/cmake-build-debug/CMakeFiles/good_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/good_example.dir/depend

