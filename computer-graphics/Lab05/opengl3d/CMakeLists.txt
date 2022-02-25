cmake_minimum_required(VERSION 3.0.0)
project(opengl3d VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(opengl3d opengl3d.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(opengl3d ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )