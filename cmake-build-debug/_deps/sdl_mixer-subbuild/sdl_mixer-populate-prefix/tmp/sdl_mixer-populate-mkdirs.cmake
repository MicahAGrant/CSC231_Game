# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-src"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-build"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/tmp"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/src/sdl_mixer-populate-stamp"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/src"
  "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/src/sdl_mixer-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/src/sdl_mixer-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/grant/Documents/WLC/Spring2025/CSC231/ClassPersonal/game/cmake-build-debug/_deps/sdl_mixer-subbuild/sdl_mixer-populate-prefix/src/sdl_mixer-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
