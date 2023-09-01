cmake_minimum_required(VERSION 3.20)



find_package(Eigen3 3.4 REQUIRED)
find_package(OpenCV REQUIRED)

#create a library from include things and source things
add_library(project_lib preprocess_util.cpp gradient.cpp convolution.cpp
    ${HEADER_LIST_LOC}/preprocess_util.h 
    ${HEADER_LIST_LOC}/gradient.h
    ${HEADER_LIST_LOC}/convolution.h)

target_include_directories(project_lib PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(project_lib Eigen3::Eigen ${OpenCV_LIBS})


#Building Main
add_executable(main main.cpp)
target_include_directories(main PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(main Eigen3::Eigen)
target_link_libraries(main ${OpenCV_LIBS} project_lib)

#Build other tests
add_executable(conv_test conv_test.cpp)
target_include_directories(conv_test PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(conv_test Eigen3::Eigen)
target_link_libraries(conv_test ${OpenCV_LIBS} project_lib)