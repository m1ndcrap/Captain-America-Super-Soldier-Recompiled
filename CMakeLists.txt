# captainamericasupersoldier - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(captainamericasupersoldier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(CAPTAINAMERICASUPERSOLDIER_SOURCES
    src/main.cpp
)

if(WIN32)
    add_executable(captainamericasupersoldier WIN32 ${CAPTAINAMERICASUPERSOLDIER_SOURCES})
else()
    add_executable(captainamericasupersoldier ${CAPTAINAMERICASUPERSOLDIER_SOURCES})
endif()

rexglue_setup_target(captainamericasupersoldier)

