#=============================================================================
#  MuseScore
#  Music Composition & Notation
#
#  Copyright (C) 2013 Werner Schweer
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License version 2
#  as published by the Free Software Foundation and appearing in
#  the file LICENSE.GPL
#=============================================================================

cmake_minimum_required(VERSION 3.10)

project(MuseSynth VERSION 0.1)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build" ${CMAKE_MODULE_PATH})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(SOUNDFONT3 "Ogg Vorbis compressed fonts" ON) # Enable Ogg Vorbis compressed fonts, requires Ogg & Vorbis
option(FLUID "Include sound font support in the build" ON)
option(ZERBERUS "Include sfz support in the build" OFF)

configure_file(config.h.in config.h)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_subdirectory(libmscore)
add_subdirectory(synthesizer)
if (FLUID)
    message("Fluid enabled")
    add_subdirectory(fluid)
    list(APPEND SYNTHESIZER_IMPL_LIBS fluid)
endif()
message(${ZERBERUS})
if (${ZERBERUS})
    message("Zerberus enabled")
    add_subdirectory(thirdparty/qzip)
    add_subdirectory(audiofile)
    add_subdirectory(zerberus)
    list(APPEND SYNTHESIZER_IMPL_LIBS zerberus)
endif()

add_executable(msplay msplay.cpp)
target_link_libraries(msplay
        synthesizer
        Qt5::Core
        ${SYNTHESIZER_IMPL_LIBS})
target_include_directories(msplay PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}")


# Libraries linked via full path no longer produce linker search paths.
#cmake_policy(SET CMP0003 NEW)
## Don't process generated source files with AUTOMOC
#if(POLICY CMP0071)
#    cmake_policy(SET CMP0071 OLD)
#endif(POLICY CMP0071)
## Apparently needed on Mac only (?)
#if (APPLE)
#    # Issue no warning non-existent target argument to get_target_property()
#    # and set the result variable to a -NOTFOUND value rather than issuing a FATAL_ERROR 40
#    if(POLICY CMP0045)
#        cmake_policy(SET CMP0045 OLD)
#    endif(POLICY CMP0045)
#
#    # Silently ignore non-existent dependencies (mops1, mops2)
#    if(POLICY CMP0046)
#        cmake_policy(SET CMP0046 OLD)
#    endif(POLICY CMP0046)
#endif (APPLE)
#
#set(SCRIPT_INTERFACE  TRUE)
##  Look for Qt5
#if (SCRIPT_INTERFACE)
#    SET(QT_MIN_VERSION    "5.8.0")
#else (SCRIPT_INTERFACE)
#    SET(QT_MIN_VERSION    "5.7.0")
#endif (SCRIPT_INTERFACE)
#
## Include modules
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build" ${CMAKE_MODULE_PATH})
#include (FindQt5)
#include (CreatePrecompiledHeader)
#
## For debugging the make system uncomment next line:
## set(CMAKE_VERBOSE_MAKEFILE ON)
#
#set(CMAKE_AUTOMOC     TRUE)
#set(MSCORE_UNSTABLE   TRUE)          # Mark as unstable
#set(MSCORE_RELEASE_CHANNEL "devel")
##set(MSCORE_RELEASE_CHANNEL "testing")
##set(MSCORE_RELEASE_CHANNEL "stable")
#set(USE_SSE           TRUE)
#
## Disable components not supported on Windows
#if (MSVC OR MINGW)
#    set(WIN_NOT_AVAIL "Not available on Windows")
#    option(BUILD_PULSEAUDIO ${WIN_NOT_AVAIL} OFF)
#    option(BUILD_ALSA ${WIN_NOT_AVAIL} OFF)
#endif (MSVC OR MINGW)
#
## Disable components not supported on Mac
#if (APPLE)
#    set(MAC_NOT_AVAIL "Not available on Mac")
#    option(BUILD_PULSEAUDIO ${MAC_NOT_AVAIL} OFF)
#    option(BUILD_ALSA ${MAC_NOT_AVAIL} OFF)
#endif (APPLE)
#
## Disable components not supported on Linux/BSD
#if (NOT APPLE AND NOT MINGW AND NOT MSVC)
#    set(NIX_NOT_AVAIL "Not available on Linux/BSD")
#    #option(BUILD_PORTMIDI "PortMidi disabled on Linux. (It uses ALSA but it's better to use ALSA directly)" OFF)
#endif (NOT APPLE AND NOT MINGW AND NOT MSVC)
#
#add_subdirectory(fluid)
#add_subdirectory(synthesizer)
#add_subdirectory(zerberus)