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
CMAKE_SOURCE_DIR = E:\DataStruct\ss3\3.21_RPN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\DataStruct\ss3\3.21_RPN\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3_21_RPN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3_21_RPN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3_21_RPN.dir/flags.make

CMakeFiles/3_21_RPN.dir/main.c.obj: CMakeFiles/3_21_RPN.dir/flags.make
CMakeFiles/3_21_RPN.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss3\3.21_RPN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/3_21_RPN.dir/main.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\3_21_RPN.dir\main.c.obj   -c E:\DataStruct\ss3\3.21_RPN\main.c

CMakeFiles/3_21_RPN.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3_21_RPN.dir/main.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss3\3.21_RPN\main.c > CMakeFiles\3_21_RPN.dir\main.c.i

CMakeFiles/3_21_RPN.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3_21_RPN.dir/main.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss3\3.21_RPN\main.c -o CMakeFiles\3_21_RPN.dir\main.c.s

CMakeFiles/3_21_RPN.dir/main.c.obj.requires:

.PHONY : CMakeFiles/3_21_RPN.dir/main.c.obj.requires

CMakeFiles/3_21_RPN.dir/main.c.obj.provides: CMakeFiles/3_21_RPN.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\3_21_RPN.dir\build.make CMakeFiles/3_21_RPN.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/3_21_RPN.dir/main.c.obj.provides

CMakeFiles/3_21_RPN.dir/main.c.obj.provides.build: CMakeFiles/3_21_RPN.dir/main.c.obj


CMakeFiles/3_21_RPN.dir/Stack.c.obj: CMakeFiles/3_21_RPN.dir/flags.make
CMakeFiles/3_21_RPN.dir/Stack.c.obj: ../Stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss3\3.21_RPN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/3_21_RPN.dir/Stack.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\3_21_RPN.dir\Stack.c.obj   -c E:\DataStruct\ss3\3.21_RPN\Stack.c

CMakeFiles/3_21_RPN.dir/Stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3_21_RPN.dir/Stack.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss3\3.21_RPN\Stack.c > CMakeFiles\3_21_RPN.dir\Stack.c.i

CMakeFiles/3_21_RPN.dir/Stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3_21_RPN.dir/Stack.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss3\3.21_RPN\Stack.c -o CMakeFiles\3_21_RPN.dir\Stack.c.s

CMakeFiles/3_21_RPN.dir/Stack.c.obj.requires:

.PHONY : CMakeFiles/3_21_RPN.dir/Stack.c.obj.requires

CMakeFiles/3_21_RPN.dir/Stack.c.obj.provides: CMakeFiles/3_21_RPN.dir/Stack.c.obj.requires
	$(MAKE) -f CMakeFiles\3_21_RPN.dir\build.make CMakeFiles/3_21_RPN.dir/Stack.c.obj.provides.build
.PHONY : CMakeFiles/3_21_RPN.dir/Stack.c.obj.provides

CMakeFiles/3_21_RPN.dir/Stack.c.obj.provides.build: CMakeFiles/3_21_RPN.dir/Stack.c.obj


# Object files for target 3_21_RPN
3_21_RPN_OBJECTS = \
"CMakeFiles/3_21_RPN.dir/main.c.obj" \
"CMakeFiles/3_21_RPN.dir/Stack.c.obj"

# External object files for target 3_21_RPN
3_21_RPN_EXTERNAL_OBJECTS =

3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/main.c.obj
3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/Stack.c.obj
3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/build.make
3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/linklibs.rsp
3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/objects1.rsp
3_21_RPN.exe: CMakeFiles/3_21_RPN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\DataStruct\ss3\3.21_RPN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 3_21_RPN.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3_21_RPN.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3_21_RPN.dir/build: 3_21_RPN.exe

.PHONY : CMakeFiles/3_21_RPN.dir/build

CMakeFiles/3_21_RPN.dir/requires: CMakeFiles/3_21_RPN.dir/main.c.obj.requires
CMakeFiles/3_21_RPN.dir/requires: CMakeFiles/3_21_RPN.dir/Stack.c.obj.requires

.PHONY : CMakeFiles/3_21_RPN.dir/requires

CMakeFiles/3_21_RPN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3_21_RPN.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3_21_RPN.dir/clean

CMakeFiles/3_21_RPN.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\DataStruct\ss3\3.21_RPN E:\DataStruct\ss3\3.21_RPN E:\DataStruct\ss3\3.21_RPN\cmake-build-debug E:\DataStruct\ss3\3.21_RPN\cmake-build-debug E:\DataStruct\ss3\3.21_RPN\cmake-build-debug\CMakeFiles\3_21_RPN.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3_21_RPN.dir/depend
