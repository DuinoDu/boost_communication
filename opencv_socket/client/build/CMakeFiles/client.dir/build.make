# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/duino/project/cpp/opencv_socket/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/duino/project/cpp/opencv_socket/client/build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/main.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/duino/project/cpp/opencv_socket/client/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/client.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client.dir/main.cpp.o -c /home/duino/project/cpp/opencv_socket/client/main.cpp

CMakeFiles/client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/duino/project/cpp/opencv_socket/client/main.cpp > CMakeFiles/client.dir/main.cpp.i

CMakeFiles/client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/duino/project/cpp/opencv_socket/client/main.cpp -o CMakeFiles/client.dir/main.cpp.s

CMakeFiles/client.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/client.dir/main.cpp.o.requires

CMakeFiles/client.dir/main.cpp.o.provides: CMakeFiles/client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/main.cpp.o.provides

CMakeFiles/client.dir/main.cpp.o.provides.build: CMakeFiles/client.dir/main.cpp.o

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/main.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/main.cpp.o
client: CMakeFiles/client.dir/build.make
client: /usr/local/lib/libopencv_videostab.so.3.1.0
client: /usr/local/lib/libopencv_videoio.so.3.1.0
client: /usr/local/lib/libopencv_video.so.3.1.0
client: /usr/local/lib/libopencv_superres.so.3.1.0
client: /usr/local/lib/libopencv_stitching.so.3.1.0
client: /usr/local/lib/libopencv_shape.so.3.1.0
client: /usr/local/lib/libopencv_photo.so.3.1.0
client: /usr/local/lib/libopencv_objdetect.so.3.1.0
client: /usr/local/lib/libopencv_ml.so.3.1.0
client: /usr/local/lib/libopencv_imgproc.so.3.1.0
client: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
client: /usr/local/lib/libopencv_highgui.so.3.1.0
client: /usr/local/lib/libopencv_flann.so.3.1.0
client: /usr/local/lib/libopencv_features2d.so.3.1.0
client: /usr/local/lib/libopencv_cudev.so.3.1.0
client: /usr/local/lib/libopencv_cudawarping.so.3.1.0
client: /usr/local/lib/libopencv_cudastereo.so.3.1.0
client: /usr/local/lib/libopencv_cudaoptflow.so.3.1.0
client: /usr/local/lib/libopencv_cudaobjdetect.so.3.1.0
client: /usr/local/lib/libopencv_cudalegacy.so.3.1.0
client: /usr/local/lib/libopencv_cudaimgproc.so.3.1.0
client: /usr/local/lib/libopencv_cudafilters.so.3.1.0
client: /usr/local/lib/libopencv_cudafeatures2d.so.3.1.0
client: /usr/local/lib/libopencv_cudacodec.so.3.1.0
client: /usr/local/lib/libopencv_cudabgsegm.so.3.1.0
client: /usr/local/lib/libopencv_cudaarithm.so.3.1.0
client: /usr/local/lib/libopencv_core.so.3.1.0
client: /usr/local/lib/libopencv_calib3d.so.3.1.0
client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
client: /usr/lib/x86_64-linux-gnu/libboost_system.so
client: /usr/local/lib/libopencv_cudawarping.so.3.1.0
client: /usr/local/lib/libopencv_objdetect.so.3.1.0
client: /usr/local/lib/libopencv_cudafilters.so.3.1.0
client: /usr/local/lib/libopencv_cudaarithm.so.3.1.0
client: /usr/local/lib/libopencv_features2d.so.3.1.0
client: /usr/local/lib/libopencv_ml.so.3.1.0
client: /usr/local/lib/libopencv_highgui.so.3.1.0
client: /usr/local/lib/libopencv_videoio.so.3.1.0
client: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
client: /usr/local/lib/libopencv_flann.so.3.1.0
client: /usr/local/lib/libopencv_video.so.3.1.0
client: /usr/local/lib/libopencv_imgproc.so.3.1.0
client: /usr/local/lib/libopencv_core.so.3.1.0
client: /usr/local/lib/libopencv_cudev.so.3.1.0
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client
.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/main.cpp.o.requires
.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/duino/project/cpp/opencv_socket/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/duino/project/cpp/opencv_socket/client /home/duino/project/cpp/opencv_socket/client /home/duino/project/cpp/opencv_socket/client/build /home/duino/project/cpp/opencv_socket/client/build /home/duino/project/cpp/opencv_socket/client/build/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend
