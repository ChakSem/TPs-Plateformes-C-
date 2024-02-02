# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FrameworkQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FrameworkQT_autogen.dir\\ParseCache.txt"
  "FrameworkQT_autogen"
  )
endif()
