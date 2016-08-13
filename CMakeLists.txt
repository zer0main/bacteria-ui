cmake_minimum_required(VERSION 2.6)
project(bacteria-ui)

IF (CMP0017)
    cmake_policy(SET CMP0017 NEW)
ENDIF(CMP0017)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(bacteria-core/src)
include_directories(bacteria-core/src/util)
include_directories(bacteria-core/src/model)
include_directories(bacteria-core/src/interpreter)
include_directories(src/gui)
include_directories(src)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB sources
    "src/gui/*.cpp"
    "bacteria-core/src/*.cpp"
    "bacteria-core/src/util/*.cpp"
    "bacteria-core/src/model/*.cpp"
    "bacteria-core/src/interpreter/*.cpp"
)
file(GLOB uis "src/gui/*.ui")
file(GLOB qheaders "src/gui/*.hpp")

QT4_WRAP_UI(UISrcs ${uis})
QT4_WRAP_CPP(MOCrcs ${qheaders})
QT4_ADD_RESOURCES(RCSrcs "src/gui/qbacteria.qrc")

add_executable(bacteria-ui ${sources} ${MOCrcs} ${UISrcs} ${RCSrcs})
TARGET_LINK_LIBRARIES(bacteria-ui ${QT_LIBRARIES})

IF (MINGW)
    SET(CMAKE_EXE_LINKER_FLAGS -mwindows)
ENDIF (MINGW)
