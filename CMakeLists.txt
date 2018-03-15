cmake_minimum_required(VERSION 3.1.0)
project(spatial_hashing)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


#Environment Variable
file(GLOB headers "${CMAKE_SOURCE_DIR}/*.h")
file(GLOB sources "${CMAKE_SOURCE_DIR}/*.cpp")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -Wno-sign-compare")
set(CMAKE_BUILD_TYPE Release)

add_executable(${PROJECT_NAME} ${headers} ${sources})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} 
${VEGA}  ${MKL} )