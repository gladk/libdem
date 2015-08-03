SET(SRC_FILES 
      body.cpp
      contact.cpp
      material.cpp
      scene.cpp
      state.cpp
)
SET(HEADERS_FILES 
      ${CMAKE_BINARY_DIR}/lib/base.hpp
      body.hpp
      scene.hpp
      node.hpp
      state.hpp
      material.hpp
      dem.hpp
      contact.hpp
)

CONFIGURE_FILE(base.hpp.in "base.hpp")

#===========================================================
ADD_LIBRARY(dem SHARED ${SRC_FILES})
TARGET_LINK_LIBRARIES(dem ${Boost_LIBRARIES})

SET_TARGET_PROPERTIES(dem PROPERTIES
  VERSION ${VERSION}
  SOVERSION ${SOVERSION})

INSTALL(TARGETS dem DESTINATION "${CMAKE_INSTALL_LIBDIR}/")
INSTALL(FILES ${HEADERS_FILES} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/libdem/")
#===========================================================

INCLUDE_DIRECTORIES("${CMAKE_BINARY_DIR}/lib/")
