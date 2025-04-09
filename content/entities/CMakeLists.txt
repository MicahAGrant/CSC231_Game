add_library(entities
  heros.cpp
  monsters.cpp
        ../actions/opendoor.cpp
        ../actions/opendoor.h
)

target_include_directories(entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities PUBLIC engine actions items)
