add_library(entities
  heros.cpp heros.h
  monsters.cpp
        ../actions/opendoor.cpp
        ../actions/opendoor.h
        wander.h
        wander.cpp
)

target_include_directories(entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities PUBLIC engine actions items)
