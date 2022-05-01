cmake_minimum_required(VERSION 3.10)

# set the project name
project(CrazyCraft-launcher)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(RUNTIME_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls and binaries")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for binaries")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls")

IF(NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls and binaries")
endif()



file(GLOB_RECURSE PROJECT_SOURCE_FILES src/*.hpp src/*.h src/*.cpp)
add_executable(CrazyCraft-launcher ${PROJECT_SOURCE_FILES})
target_include_directories(CrazyCraft-launcher PUBLIC src)
target_include_directories(CrazyCraft-launcher PUBLIC lib/RmlUi/Include)
target_include_directories(CrazyCraft-launcher PUBLIC lib/glad/include)
target_include_directories(CrazyCraft-launcher PUBLIC lib/glfw/include)

add_subdirectory(lib)

target_link_libraries(CrazyCraft-launcher PUBLIC glad glfw RmlCore RmlDebugger)