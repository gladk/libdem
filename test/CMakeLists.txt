INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/lib/")
INCLUDE_DIRECTORIES("/usr/src/gtest")

#======================================================
IF (USERPATH)
  SET(CMAKE_SKIP_BUILD_RPATH FALSE)
  SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/")
  SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
ENDIF (USERPATH)
#======================================================

ADD_EXECUTABLE(test1 test1.cpp /usr/src/gtest/src/gtest-all.cc)
TARGET_LINK_LIBRARIES(test1 ${Boost_LIBRARIES})
