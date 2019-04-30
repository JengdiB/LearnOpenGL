cmake_minimum_required(VERSION 3.10) # 3.13 later, then 3.14

project(LearnOpenGL)

add_subdirectory(externals/glfw-3.3)
add_subdirectory(externals/glad)

add_subdirectory(src)