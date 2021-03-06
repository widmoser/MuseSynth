find_path(SNDFILE_INCLUDE_DIR sndfile.h PATHS
        "C:/Program Files (x86)/Mega-Nerd/libsndfile/include")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
find_library(SNDFILE_LIBRARY NAMES libsndfile-1 PATHS
        "C:/Program Files (x86)/Mega-Nerd/libsndfile/lib"
        NO_DEFAULT_PATH)

#if (MINGW)
#  set(SNDFILE_INCLUDE_DIR "")
#  set(SNDFILE_LIBRARY "")
#endif(MINGW)

message(STATUS ${SNDFILE_LIBRARY})

if (SNDFILE_INCLUDE_DIR AND SNDFILE_LIBRARY)
      set(SNDFILE_FOUND TRUE)
endif (SNDFILE_INCLUDE_DIR AND SNDFILE_LIBRARY)

if (SNDFILE_FOUND)
      message (STATUS "Found sndfile: ${SNDFILE_LIBRARY}")
else (SNDFILE_FOUND)
      message (FATAL_ERROR "Could not find: sndfile")
endif (SNDFILE_FOUND)
