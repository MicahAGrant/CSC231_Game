# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-src"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-build"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/tmp"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/src/sdl_image-populate-stamp"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/src"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/src/sdl_image-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/src/sdl_image-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_image-subbuild/sdl_image-populate-prefix/src/sdl_image-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
