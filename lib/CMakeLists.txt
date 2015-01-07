SET(SRC_FILES simobject.cpp)
SET(HEADERS_FILES simobject.h base.h)

#======================================================
IF (USERPATH)
  SET(CMAKE_SKIP_BUILD_RPATH FALSE)
  SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/")
  SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
ENDIF (USERPATH)
#======================================================

#===========================================================
ADD_LIBRARY(dem SHARED ${SRC_FILES})
TARGET_LINK_LIBRARIES(dem ${Boost_LIBRARIES})
  
SET_TARGET_PROPERTIES(dem PROPERTIES
  VERSION ${VERSION}
  SOVERSION ${SOVERSION})

INSTALL(TARGETS dem DESTINATION "${CMAKE_INSTALL_LIBDIR}/")
INSTALL(FILES ${HEADERS_FILES} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/libdem/")
#===========================================================
