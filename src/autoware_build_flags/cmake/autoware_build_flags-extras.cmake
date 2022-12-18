if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-undefined,error")
endif()

# Enable support for C++11
# dont need add_compile_options(-std=c++11) in individual CMakelists
if(${CMAKE_VERSION} VERSION_LESS "3.1.0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else()
  set(CMAKE_CXX_STANDARD 14)
endif()

# options
# CUDA 10.0 / Eigen v>=3.3.7 / CMAKE v>3.12 
# set USE_CUDA manually please
macro(CHECK_CUDA)

  set(USE_CUDA OFF)
  # set(USE_CUDA ON)

endmacro()












































