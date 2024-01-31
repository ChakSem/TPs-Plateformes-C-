# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\calculatorbuilder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calculatorbuilder_autogen.dir\\ParseCache.txt"
  "calculatorbuilder_autogen"
  )
endif()
