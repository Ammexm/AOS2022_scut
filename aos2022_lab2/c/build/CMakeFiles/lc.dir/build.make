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
CMAKE_SOURCE_DIR = /mnt/Chenxm/project/aos2022_lab2/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/Chenxm/project/aos2022_lab2/c/build

# Include any dependencies generated for this target.
include CMakeFiles/lc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lc.dir/flags.make

CMakeFiles/lc.dir/src/lcTools.c.o: CMakeFiles/lc.dir/flags.make
CMakeFiles/lc.dir/src/lcTools.c.o: ../src/lcTools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/Chenxm/project/aos2022_lab2/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lc.dir/src/lcTools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc.dir/src/lcTools.c.o   -c /mnt/Chenxm/project/aos2022_lab2/c/src/lcTools.c

CMakeFiles/lc.dir/src/lcTools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc.dir/src/lcTools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/Chenxm/project/aos2022_lab2/c/src/lcTools.c > CMakeFiles/lc.dir/src/lcTools.c.i

CMakeFiles/lc.dir/src/lcTools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc.dir/src/lcTools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/Chenxm/project/aos2022_lab2/c/src/lcTools.c -o CMakeFiles/lc.dir/src/lcTools.c.s

CMakeFiles/lc.dir/src/lcTools.c.o.requires:

.PHONY : CMakeFiles/lc.dir/src/lcTools.c.o.requires

CMakeFiles/lc.dir/src/lcTools.c.o.provides: CMakeFiles/lc.dir/src/lcTools.c.o.requires
	$(MAKE) -f CMakeFiles/lc.dir/build.make CMakeFiles/lc.dir/src/lcTools.c.o.provides.build
.PHONY : CMakeFiles/lc.dir/src/lcTools.c.o.provides

CMakeFiles/lc.dir/src/lcTools.c.o.provides.build: CMakeFiles/lc.dir/src/lcTools.c.o


CMakeFiles/lc.dir/src/threadTools.c.o: CMakeFiles/lc.dir/flags.make
CMakeFiles/lc.dir/src/threadTools.c.o: ../src/threadTools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/Chenxm/project/aos2022_lab2/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lc.dir/src/threadTools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc.dir/src/threadTools.c.o   -c /mnt/Chenxm/project/aos2022_lab2/c/src/threadTools.c

CMakeFiles/lc.dir/src/threadTools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc.dir/src/threadTools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/Chenxm/project/aos2022_lab2/c/src/threadTools.c > CMakeFiles/lc.dir/src/threadTools.c.i

CMakeFiles/lc.dir/src/threadTools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc.dir/src/threadTools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/Chenxm/project/aos2022_lab2/c/src/threadTools.c -o CMakeFiles/lc.dir/src/threadTools.c.s

CMakeFiles/lc.dir/src/threadTools.c.o.requires:

.PHONY : CMakeFiles/lc.dir/src/threadTools.c.o.requires

CMakeFiles/lc.dir/src/threadTools.c.o.provides: CMakeFiles/lc.dir/src/threadTools.c.o.requires
	$(MAKE) -f CMakeFiles/lc.dir/build.make CMakeFiles/lc.dir/src/threadTools.c.o.provides.build
.PHONY : CMakeFiles/lc.dir/src/threadTools.c.o.provides

CMakeFiles/lc.dir/src/threadTools.c.o.provides.build: CMakeFiles/lc.dir/src/threadTools.c.o


CMakeFiles/lc.dir/main/lc.c.o: CMakeFiles/lc.dir/flags.make
CMakeFiles/lc.dir/main/lc.c.o: ../main/lc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/Chenxm/project/aos2022_lab2/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lc.dir/main/lc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc.dir/main/lc.c.o   -c /mnt/Chenxm/project/aos2022_lab2/c/main/lc.c

CMakeFiles/lc.dir/main/lc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc.dir/main/lc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/Chenxm/project/aos2022_lab2/c/main/lc.c > CMakeFiles/lc.dir/main/lc.c.i

CMakeFiles/lc.dir/main/lc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc.dir/main/lc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/Chenxm/project/aos2022_lab2/c/main/lc.c -o CMakeFiles/lc.dir/main/lc.c.s

CMakeFiles/lc.dir/main/lc.c.o.requires:

.PHONY : CMakeFiles/lc.dir/main/lc.c.o.requires

CMakeFiles/lc.dir/main/lc.c.o.provides: CMakeFiles/lc.dir/main/lc.c.o.requires
	$(MAKE) -f CMakeFiles/lc.dir/build.make CMakeFiles/lc.dir/main/lc.c.o.provides.build
.PHONY : CMakeFiles/lc.dir/main/lc.c.o.provides

CMakeFiles/lc.dir/main/lc.c.o.provides.build: CMakeFiles/lc.dir/main/lc.c.o


# Object files for target lc
lc_OBJECTS = \
"CMakeFiles/lc.dir/src/lcTools.c.o" \
"CMakeFiles/lc.dir/src/threadTools.c.o" \
"CMakeFiles/lc.dir/main/lc.c.o"

# External object files for target lc
lc_EXTERNAL_OBJECTS =

lc: CMakeFiles/lc.dir/src/lcTools.c.o
lc: CMakeFiles/lc.dir/src/threadTools.c.o
lc: CMakeFiles/lc.dir/main/lc.c.o
lc: CMakeFiles/lc.dir/build.make
lc: CMakeFiles/lc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/Chenxm/project/aos2022_lab2/c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lc.dir/build: lc

.PHONY : CMakeFiles/lc.dir/build

CMakeFiles/lc.dir/requires: CMakeFiles/lc.dir/src/lcTools.c.o.requires
CMakeFiles/lc.dir/requires: CMakeFiles/lc.dir/src/threadTools.c.o.requires
CMakeFiles/lc.dir/requires: CMakeFiles/lc.dir/main/lc.c.o.requires

.PHONY : CMakeFiles/lc.dir/requires

CMakeFiles/lc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lc.dir/clean

CMakeFiles/lc.dir/depend:
	cd /mnt/Chenxm/project/aos2022_lab2/c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/Chenxm/project/aos2022_lab2/c /mnt/Chenxm/project/aos2022_lab2/c /mnt/Chenxm/project/aos2022_lab2/c/build /mnt/Chenxm/project/aos2022_lab2/c/build /mnt/Chenxm/project/aos2022_lab2/c/build/CMakeFiles/lc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lc.dir/depend
