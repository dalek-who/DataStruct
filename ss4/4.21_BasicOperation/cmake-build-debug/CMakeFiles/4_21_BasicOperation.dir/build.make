# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\DataStruct\ss4\4.21_BasicOperation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4_21_BasicOperation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4_21_BasicOperation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4_21_BasicOperation.dir/flags.make

CMakeFiles/4_21_BasicOperation.dir/main.c.obj: CMakeFiles/4_21_BasicOperation.dir/flags.make
CMakeFiles/4_21_BasicOperation.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/4_21_BasicOperation.dir/main.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\4_21_BasicOperation.dir\main.c.obj   -c E:\DataStruct\ss4\4.21_BasicOperation\main.c

CMakeFiles/4_21_BasicOperation.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4_21_BasicOperation.dir/main.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss4\4.21_BasicOperation\main.c > CMakeFiles\4_21_BasicOperation.dir\main.c.i

CMakeFiles/4_21_BasicOperation.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4_21_BasicOperation.dir/main.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss4\4.21_BasicOperation\main.c -o CMakeFiles\4_21_BasicOperation.dir\main.c.s

CMakeFiles/4_21_BasicOperation.dir/main.c.obj.requires:

.PHONY : CMakeFiles/4_21_BasicOperation.dir/main.c.obj.requires

CMakeFiles/4_21_BasicOperation.dir/main.c.obj.provides: CMakeFiles/4_21_BasicOperation.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\4_21_BasicOperation.dir\build.make CMakeFiles/4_21_BasicOperation.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/4_21_BasicOperation.dir/main.c.obj.provides

CMakeFiles/4_21_BasicOperation.dir/main.c.obj.provides.build: CMakeFiles/4_21_BasicOperation.dir/main.c.obj


CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj: CMakeFiles/4_21_BasicOperation.dir/flags.make
CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj: ../LinkList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\4_21_BasicOperation.dir\LinkList.c.obj   -c E:\DataStruct\ss4\4.21_BasicOperation\LinkList.c

CMakeFiles/4_21_BasicOperation.dir/LinkList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4_21_BasicOperation.dir/LinkList.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss4\4.21_BasicOperation\LinkList.c > CMakeFiles\4_21_BasicOperation.dir\LinkList.c.i

CMakeFiles/4_21_BasicOperation.dir/LinkList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4_21_BasicOperation.dir/LinkList.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss4\4.21_BasicOperation\LinkList.c -o CMakeFiles\4_21_BasicOperation.dir\LinkList.c.s

CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.requires:

.PHONY : CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.requires

CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.provides: CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.requires
	$(MAKE) -f CMakeFiles\4_21_BasicOperation.dir\build.make CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.provides.build
.PHONY : CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.provides

CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.provides.build: CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj


# Object files for target 4_21_BasicOperation
4_21_BasicOperation_OBJECTS = \
"CMakeFiles/4_21_BasicOperation.dir/main.c.obj" \
"CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj"

# External object files for target 4_21_BasicOperation
4_21_BasicOperation_EXTERNAL_OBJECTS =

4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/main.c.obj
4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj
4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/build.make
4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/linklibs.rsp
4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/objects1.rsp
4_21_BasicOperation.exe: CMakeFiles/4_21_BasicOperation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 4_21_BasicOperation.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\4_21_BasicOperation.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4_21_BasicOperation.dir/build: 4_21_BasicOperation.exe

.PHONY : CMakeFiles/4_21_BasicOperation.dir/build

CMakeFiles/4_21_BasicOperation.dir/requires: CMakeFiles/4_21_BasicOperation.dir/main.c.obj.requires
CMakeFiles/4_21_BasicOperation.dir/requires: CMakeFiles/4_21_BasicOperation.dir/LinkList.c.obj.requires

.PHONY : CMakeFiles/4_21_BasicOperation.dir/requires

CMakeFiles/4_21_BasicOperation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\4_21_BasicOperation.dir\cmake_clean.cmake
.PHONY : CMakeFiles/4_21_BasicOperation.dir/clean

CMakeFiles/4_21_BasicOperation.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\DataStruct\ss4\4.21_BasicOperation E:\DataStruct\ss4\4.21_BasicOperation E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug E:\DataStruct\ss4\4.21_BasicOperation\cmake-build-debug\CMakeFiles\4_21_BasicOperation.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4_21_BasicOperation.dir/depend

