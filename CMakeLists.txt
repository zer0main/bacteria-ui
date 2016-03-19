cmake_minimum_required(VERSION 2.6)
project(bacteria-ui)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(bacteria-core/src)
include_directories(bacteria-core/src/util)
include_directories(bacteria-core/src/model)
include_directories(bacteria-core/src/interpreter)
include_directories(src/gui)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB sources "src/gui/*.cpp" "bacteria-core/src/*/*.cpp")
file(GLOB uis "src/gui/*.ui")
file(GLOB qheaders "src/gui/*.hpp")

QT4_WRAP_UI(UISrcs ${uis})
QT4_WRAP_CPP(MOCrcs ${qheaders})

add_executable(bacteria-ui ${sources} ${MOCrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(bacteria-ui ${QT_LIBRARIES})
