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
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

add_library(libmscore STATIC
        xmlreader.cpp
        xmlwriter.cpp)
target_link_libraries(libmscore Qt5::Core Qt5::Gui)

#include (${PROJECT_SOURCE_DIR}/build/gch.cmake)
#
#if (APPLE)
#      file(GLOB_RECURSE INCS "*.h")
#else (APPLE)
#      set(INCS "")
#endif (APPLE)
#
#if (NOT MSVC)
#   set(_all_h_file "${PROJECT_BINARY_DIR}/all.h")
#else (NOT MSVC)
#   set(_all_h_file "${PROJECT_SOURCE_DIR}/all.h")
#endif (NOT MSVC)
#
#add_library (synthesizer STATIC
#      ${_all_h_file}
#      ${PCH}
#      msynthesizer.cpp
#      event.cpp
#      synthesizergui.cpp
#      ${INCS}
#      )
#if (NOT MSVC)
#   set_target_properties (
#      synthesizer
#      PROPERTIES
#         COMPILE_FLAGS "${PCH_INCLUDE} -g -Wall -Wextra -Winvalid-pch"
#      )
#else (NOT MSVC)
#   set_target_properties (
#      synthesizer
#      PROPERTIES
#         COMPILE_FLAGS "${PCH_INCLUDE}"
#      )
#endif (NOT MSVC)
#target_include_directories(synthesizer PUBLIC .)
#
#xcode_pch(synthesizer all)
#
## Use MSVC pre-compiled headers
#vstudio_pch( synthesizer )
#
## MSVC does not depend on mops1 & mops2 for PCH
##if (NOT MSVC)
##   ADD_DEPENDENCIES(synthesizer mops1)
##   ADD_DEPENDENCIES(synthesizer mops2)
##endif (NOT MSVC)

