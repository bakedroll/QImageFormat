cmake_minimum_required(VERSION 3.4)

set(CMAKE_SCRIPTS_DIRECTORY "" CACHE STRING "The CMake scripts directory")
if(EXISTS ${CMAKE_SCRIPTS_DIRECTORY}/scripts.cmake)
  include(${CMAKE_SCRIPTS_DIRECTORY}/scripts.cmake)
else()
  message(FATAL_ERROR "Please specify CMAKE_SCRIPTS_DIRECTORY")
  return()
endif()

project(QImageFormat)

begin_project(QImageFormat EXECUTABLE)

require_library(Qt6 MODULES Core Gui Widgets)

add_source_directory(src)

make_projects()

if (MSVC)
  qt_copy_plugins(platforms/qwindows styles/qwindowsvistastyle)
endif()
