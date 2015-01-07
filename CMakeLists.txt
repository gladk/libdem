# USERPATH: use RPATH for search of the shared library libdem, (ON by default)

PROJECT(libdem CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(VERSION 0.0.1)
SET(SOVERSION 0)
SET(USERPATH 1)
SET(REALNUMBER double)

INCLUDE(GNUInstallDirs)
#===========================================================
IF(NOT(CMAKE_CXX_FLAGS))
  #If flags are not set, add all usefull flags
  SET(CMAKE_BUILD_TYPE Release)
  SET(CMAKE_CXX_FLAGS  "-Wall -fPIC -g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -Werror=format-security")
ENDIF (NOT(CMAKE_CXX_FLAGS))

#C+11 support
set(CMAKE_CXX_FLAGS "-std=c++0x -pthread ${CMAKE_CXX_FLAGS}")
#===========================================================

SET(BOOST_MIN_VERSION "1.54.0")
FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ADD_DEFINITIONS( "-DBOOST_LOG_DYN_LINK" )

FIND_PACKAGE(Eigen3 REQUIRED)
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

#===========================================================
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)
ADD_SUBDIRECTORY("${CMAKE_SOURCE_DIR}/lib")
#===========================================================
ADD_SUBDIRECTORY("${CMAKE_SOURCE_DIR}/test")
#===========================================================

