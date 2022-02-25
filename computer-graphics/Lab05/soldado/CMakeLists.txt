cmake_minimum_required(VERSION 3.0.0)
project(soldado VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(soldado soldado.cpp objloader.h objloader.cpp)
set_property(TARGET soldado PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(COMPILE_FLAGS "-Wdeprecated-declarations")
include(CPack)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(soldado ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
