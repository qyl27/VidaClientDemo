cmake_minimum_required(VERSION 3.24)
project(VidaClientDemo)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(VidaClientDemo main.cpp src/glad.c)

include_directories(include)
link_directories(lib)

target_link_libraries(VidaClientDemo
        ${PROJECT_SOURCE_DIR}/lib/libfreetype-6.dll
        ${PROJECT_SOURCE_DIR}/lib/libfreetype.a
        ${PROJECT_SOURCE_DIR}/lib/libfreetype.dll.a
        ${PROJECT_SOURCE_DIR}/lib/glfw3.dll
        ${PROJECT_SOURCE_DIR}/lib/libglfw3.a
        ${PROJECT_SOURCE_DIR}/lib/libglfw3dll.a)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/resources)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/resources)

file(COPY "lib" DESTINATION ${CMAKE_BINARY_DIR})
file(COPY "resources" DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB_RECURSE  src_dir "./src/*.c" "./src/*.h" "./src/*.cpp" )
