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
CMAKE_SOURCE_DIR = E:\DataStruct\ss4\4.30_LongestSubString

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4_30_LongestSubString.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4_30_LongestSubString.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4_30_LongestSubString.dir/flags.make

CMakeFiles/4_30_LongestSubString.dir/main.c.obj: CMakeFiles/4_30_LongestSubString.dir/flags.make
CMakeFiles/4_30_LongestSubString.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/4_30_LongestSubString.dir/main.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\4_30_LongestSubString.dir\main.c.obj   -c E:\DataStruct\ss4\4.30_LongestSubString\main.c

CMakeFiles/4_30_LongestSubString.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4_30_LongestSubString.dir/main.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss4\4.30_LongestSubString\main.c > CMakeFiles\4_30_LongestSubString.dir\main.c.i

CMakeFiles/4_30_LongestSubString.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4_30_LongestSubString.dir/main.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss4\4.30_LongestSubString\main.c -o CMakeFiles\4_30_LongestSubString.dir\main.c.s

CMakeFiles/4_30_LongestSubString.dir/main.c.obj.requires:

.PHONY : CMakeFiles/4_30_LongestSubString.dir/main.c.obj.requires

CMakeFiles/4_30_LongestSubString.dir/main.c.obj.provides: CMakeFiles/4_30_LongestSubString.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\4_30_LongestSubString.dir\build.make CMakeFiles/4_30_LongestSubString.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/4_30_LongestSubString.dir/main.c.obj.provides

CMakeFiles/4_30_LongestSubString.dir/main.c.obj.provides.build: CMakeFiles/4_30_LongestSubString.dir/main.c.obj


CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj: CMakeFiles/4_30_LongestSubString.dir/flags.make
CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj: ../SqList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\4_30_LongestSubString.dir\SqList.c.obj   -c E:\DataStruct\ss4\4.30_LongestSubString\SqList.c

CMakeFiles/4_30_LongestSubString.dir/SqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4_30_LongestSubString.dir/SqList.c.i"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\DataStruct\ss4\4.30_LongestSubString\SqList.c > CMakeFiles\4_30_LongestSubString.dir\SqList.c.i

CMakeFiles/4_30_LongestSubString.dir/SqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4_30_LongestSubString.dir/SqList.c.s"
	D:\CodeBlocks\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\DataStruct\ss4\4.30_LongestSubString\SqList.c -o CMakeFiles\4_30_LongestSubString.dir\SqList.c.s

CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.requires:

.PHONY : CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.requires

CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.provides: CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.requires
	$(MAKE) -f CMakeFiles\4_30_LongestSubString.dir\build.make CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.provides.build
.PHONY : CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.provides

CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.provides.build: CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj


# Object files for target 4_30_LongestSubString
4_30_LongestSubString_OBJECTS = \
"CMakeFiles/4_30_LongestSubString.dir/main.c.obj" \
"CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj"

# External object files for target 4_30_LongestSubString
4_30_LongestSubString_EXTERNAL_OBJECTS =

4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/main.c.obj
4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj
4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/build.make
4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/linklibs.rsp
4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/objects1.rsp
4_30_LongestSubString.exe: CMakeFiles/4_30_LongestSubString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 4_30_LongestSubString.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\4_30_LongestSubString.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4_30_LongestSubString.dir/build: 4_30_LongestSubString.exe

.PHONY : CMakeFiles/4_30_LongestSubString.dir/build

CMakeFiles/4_30_LongestSubString.dir/requires: CMakeFiles/4_30_LongestSubString.dir/main.c.obj.requires
CMakeFiles/4_30_LongestSubString.dir/requires: CMakeFiles/4_30_LongestSubString.dir/SqList.c.obj.requires

.PHONY : CMakeFiles/4_30_LongestSubString.dir/requires

CMakeFiles/4_30_LongestSubString.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\4_30_LongestSubString.dir\cmake_clean.cmake
.PHONY : CMakeFiles/4_30_LongestSubString.dir/clean

CMakeFiles/4_30_LongestSubString.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\DataStruct\ss4\4.30_LongestSubString E:\DataStruct\ss4\4.30_LongestSubString E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug E:\DataStruct\ss4\4.30_LongestSubString\cmake-build-debug\CMakeFiles\4_30_LongestSubString.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4_30_LongestSubString.dir/depend
