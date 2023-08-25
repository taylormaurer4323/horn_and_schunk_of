cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

#Set project
project(new_project VERSION 1.0
    DESCRIPTION "Intro to OpenCV, Eigen, CMAKE"
    LANGUAGES CXX)

get_filename_component(INCLUDE_DIR "include" ABSOLUTE)
set(HEADER_LIST_LOC ${INCLUDE_DIR}/project/)
add_subdirectory(src)






