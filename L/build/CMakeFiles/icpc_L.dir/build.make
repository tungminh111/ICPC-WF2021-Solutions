# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build

# Include any dependencies generated for this target.
include CMakeFiles/icpc_L.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/icpc_L.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/icpc_L.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icpc_L.dir/flags.make

CMakeFiles/icpc_L.dir/main.cpp.o: CMakeFiles/icpc_L.dir/flags.make
CMakeFiles/icpc_L.dir/main.cpp.o: /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/main.cpp
CMakeFiles/icpc_L.dir/main.cpp.o: CMakeFiles/icpc_L.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icpc_L.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icpc_L.dir/main.cpp.o -MF CMakeFiles/icpc_L.dir/main.cpp.o.d -o CMakeFiles/icpc_L.dir/main.cpp.o -c /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/main.cpp

CMakeFiles/icpc_L.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icpc_L.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/main.cpp > CMakeFiles/icpc_L.dir/main.cpp.i

CMakeFiles/icpc_L.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icpc_L.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/main.cpp -o CMakeFiles/icpc_L.dir/main.cpp.s

# Object files for target icpc_L
icpc_L_OBJECTS = \
"CMakeFiles/icpc_L.dir/main.cpp.o"

# External object files for target icpc_L
icpc_L_EXTERNAL_OBJECTS =

icpc_L: CMakeFiles/icpc_L.dir/main.cpp.o
icpc_L: CMakeFiles/icpc_L.dir/build.make
icpc_L: CMakeFiles/icpc_L.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable icpc_L"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icpc_L.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/icpc_L.dir/build: icpc_L
.PHONY : CMakeFiles/icpc_L.dir/build

CMakeFiles/icpc_L.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icpc_L.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icpc_L.dir/clean

CMakeFiles/icpc_L.dir/depend:
	cd /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build /Users/minhsn22/Desktop/homework/c++/ICPC-WF2021-Solutions/L/build/CMakeFiles/icpc_L.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icpc_L.dir/depend
