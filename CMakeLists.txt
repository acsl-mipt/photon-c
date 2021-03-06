project(photon)

cmake_minimum_required(VERSION 2.8.7)
enable_testing()
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


if(MSVC)
    foreach (flag_var
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REPLACE "/W3" "/W4" ${flag_var} "${${flag_var}}")
    endforeach()
else()
    add_definitions(-Wall -Wextra -pipe)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions(-O0 -ggdb3)
    endif()
endif()

macro(enable_sanitizer name)
    add_definitions(
        -fsanitize=${name}
        -fsanitize=integer
        -fsanitize=undefined
    )
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${name} -fsanitize=integer -fsanitize=undefined")
endmacro()

if(SANITIZE_ADDRESS)
    enable_sanitizer(address)
elseif(SANITIZE_MEMORY)
    enable_sanitizer(memory)
    add_definitions(-fsanitize-memory-track-origins=2)
elseif(SANITIZE_THREAD)
    enable_sanitizer(thread)
endif()

file(GLOB_RECURSE PHOTON_CORE_FILES src/*.c src/*.h)
file(GLOB_RECURSE PHOTON_IMPL_FILES impl/*.c impl/*.h)
file(GLOB_RECURSE PHOTON_GENERATED_FILES gen/*.c gen/*.h)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/gen
    ${CMAKE_CURRENT_SOURCE_DIR}/impl
)

add_library(photon-all
    ${PHOTON_CORE_FILES}
    ${PHOTON_GENERATED_FILES}
    ${PHOTON_IMPL_FILES}
)

add_subdirectory(src/photon)
add_subdirectory(impl/photon)

get_directory_property(HAS_PARENT_SCOPE PARENT_DIRECTORY)

if(NOT HAS_PARENT_SCOPE)
    set(GTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/gtest/include)
    add_subdirectory(thirdparty/gtest)
    add_subdirectory(tests)
endif()

if(HAS_PARENT_SCOPE)
    set(PHOTON_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/gen
        ${CMAKE_CURRENT_SOURCE_DIR}/impl
        PARENT_SCOPE
    )
    set(PHOTON_LIBRARIES photon PARENT_SCOPE)
endif()
