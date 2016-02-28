cmake_minimum_required(VERSION 2.6)
project(bacteria-ui)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UISrcs mainwindow.ui)
QT4_WRAP_CPP(MOCrcs mainwindow.h)

add_executable(bacteria-ui mainwindow.cpp main.cpp ${MOCrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(bacteria-ui ${QT_LIBRARIES})
