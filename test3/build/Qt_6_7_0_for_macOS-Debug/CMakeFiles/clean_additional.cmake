# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/testoop_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/testoop_autogen.dir/ParseCache.txt"
  "testoop_autogen"
  )
endif()
