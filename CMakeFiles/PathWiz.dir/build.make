# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/charles/Developer/PathWiz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/charles/Developer/PathWiz

# Include any dependencies generated for this target.
include CMakeFiles/PathWiz.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PathWiz.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PathWiz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PathWiz.dir/flags.make

CMakeFiles/PathWiz.dir/main.cpp.o: CMakeFiles/PathWiz.dir/flags.make
CMakeFiles/PathWiz.dir/main.cpp.o: main.cpp
CMakeFiles/PathWiz.dir/main.cpp.o: CMakeFiles/PathWiz.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/charles/Developer/PathWiz/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PathWiz.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PathWiz.dir/main.cpp.o -MF CMakeFiles/PathWiz.dir/main.cpp.o.d -o CMakeFiles/PathWiz.dir/main.cpp.o -c /Users/charles/Developer/PathWiz/main.cpp

CMakeFiles/PathWiz.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PathWiz.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/charles/Developer/PathWiz/main.cpp > CMakeFiles/PathWiz.dir/main.cpp.i

CMakeFiles/PathWiz.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PathWiz.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/charles/Developer/PathWiz/main.cpp -o CMakeFiles/PathWiz.dir/main.cpp.s

# Object files for target PathWiz
PathWiz_OBJECTS = \
"CMakeFiles/PathWiz.dir/main.cpp.o"

# External object files for target PathWiz
PathWiz_EXTERNAL_OBJECTS =

PathWiz: CMakeFiles/PathWiz.dir/main.cpp.o
PathWiz: CMakeFiles/PathWiz.dir/build.make
PathWiz: /opt/homebrew/lib/libsfml-graphics.2.6.1.dylib
PathWiz: /opt/homebrew/lib/libsfml-audio.2.6.1.dylib
PathWiz: /opt/homebrew/lib/libsfml-network.2.6.1.dylib
PathWiz: /opt/homebrew/lib/libsfml-window.2.6.1.dylib
PathWiz: /opt/homebrew/lib/libsfml-system.2.6.1.dylib
PathWiz: CMakeFiles/PathWiz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/charles/Developer/PathWiz/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PathWiz"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PathWiz.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PathWiz.dir/build: PathWiz
.PHONY : CMakeFiles/PathWiz.dir/build

CMakeFiles/PathWiz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PathWiz.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PathWiz.dir/clean

CMakeFiles/PathWiz.dir/depend:
	cd /Users/charles/Developer/PathWiz && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/charles/Developer/PathWiz /Users/charles/Developer/PathWiz /Users/charles/Developer/PathWiz /Users/charles/Developer/PathWiz /Users/charles/Developer/PathWiz/CMakeFiles/PathWiz.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PathWiz.dir/depend
