# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  )
# The set of files for implicit dependencies of each language:

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS
  "ASSIMP_BUILD_BOOST_WORKAROUND"
  "ASSIMP_BUILD_NO_C4D_IMPORTER"
  "ASSIMP_BUILD_NO_OWN_ZLIB"
  "GLEW_STATIC"
  "OPENDDL_NO_USE_CPP11"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "../external/glew-cmake/include"
  "../external/glew-cmake/src"
  "../external/glfw/include"
  "../external/glm"
  "external/assimp"
  "../external/assimp/include"
  "../external/assimp/code/BoostWorkaround"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
