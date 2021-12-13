cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++11 -ansi")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

# Include dir
include_directories(/usr/local/include)

# Source files
set (LIB_SOURCES
    basic.cpp compact.cpp utf8.cpp alphabet.cpp fst.cpp operators.cpp determinise.cpp hopcroft.cpp
)

set(HEADERS
    alphabet.h basic.h compact.h fst.h interface.h mem.h utf8.h fst-compiler.h
)

# Add library
add_library(libsfst SHARED ${LIB_SOURCES})
set_target_properties(libsfst PROPERTIES POSITION_INDEPENDENT_CODE ON)
# Have the output name libsfst.so
set_target_properties(libsfst PROPERTIES OUTPUT_NAME "sfst")

# Have a static library
add_library(libsfststatic STATIC ${LIB_SOURCES})
set_target_properties(libsfststatic PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(libsfststatic PROPERTIES OUTPUT_NAME "sfst.static")

install(TARGETS libsfst
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib)

# Install the headers
install(FILES ${HEADERS} DESTINATION include)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
