cmake_minimum_required (VERSION 3.10)

project(02C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 " CACHE STRING "Set C Compiler Flags" FORCE)
#set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 " CACHE STRING "Set C++ Compiler Flags" FORCE)
include_directories("${CMAKE_CURRENT_DIR}/include")
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

file(GLOB_RECURSE mains RELATIVE "${PROJECT_SOURCE_DIR}/main" "${PROJECT_SOURCE_DIR}/main/*.c")
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    # message('mainfile is ${mainfile}')
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${SRC} main/${mainfile})
    target_link_libraries(${mainname}
    PRIVATE
        pthread
    )
endforeach()
