cmake_minimum_required(VERSION 3.10) # 3.13 later, then 3.14

project(LearnOpenGL)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/output/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/output/$<CONFIG>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/output/$<CONFIG>")

add_subdirectory(externals/glfw-3.3)
add_subdirectory(externals/glad)
add_subdirectory(externals/stb-image-2.22)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(source_code_ide)
include(copy)

add_subdirectory(src)

copy_dirs_to_runtime_dir(
    DIRS            ${CMAKE_CURRENT_LIST_DIR}/resources
    CONFIGURATIONS  ${CMAKE_CONFIGURATION_TYPES}
)
