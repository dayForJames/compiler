cmake_minimum_required (VERSION 3.8)

option(USE_ML "For ML purposes" OFF)
if(USE_ML)
  add_definitions(-DUSE_ML)
endif()

project(compiler)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#   Include OpenMP
find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_C_FLAGS_RELEASE_INIT "-Wall")

if (USE_ML)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/ML/*.c)

add_executable(main ${SOURCES})
set_property(TARGET main PROPERTY C_STANDARD 99)
set_target_properties(main PROPERTIES LINKER_LANGUAGE C)

else()
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(main ${SOURCES})
set_property(TARGET main PROPERTY C_STANDARD 99)
set_target_properties(main PROPERTIES LINKER_LANGUAGE C)
endif()

set_target_properties(main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
target_link_libraries(main LINK_PUBLIC OpenMP::OpenMP_C)