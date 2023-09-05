cmake_minimum_required(VERSION 3.20)



find_package(Eigen3 3.4 REQUIRED)
find_package(OpenCV REQUIRED)

#create a library from include things and source things
add_library(project_lib gradient.cpp hornschunk.cpp
    ${HEADER_LIST_LOC}/gradient.h 
    ${HEADER_LIST_LOC}hornschunk.h)

target_include_directories(project_lib PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(project_lib Eigen3::Eigen ${OpenCV_LIBS})


#Building Main
add_executable(hornschunk_test main.cpp)
target_include_directories(hornschunk_test PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(hornschunk_test Eigen3::Eigen)
target_link_libraries(hornschunk_test ${OpenCV_LIBS} project_lib)

#Build other tests
#add_executable(conv_test conv_test.cpp)
#target_include_directories(conv_test PUBLIC ${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR})
#target_link_libraries(conv_test Eigen3::Eigen)
#target_link_libraries(conv_test ${OpenCV_LIBS} project_lib)