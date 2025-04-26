add_library(actions
  rest.cpp rest.h
        move.cpp move.h
        closedoor.cpp closedoor.h
        ../entities/wander.cpp
        ../entities/wander.h
        opendoor.cpp
        opendoor.h
        dash.cpp
        dash.h
        use.cpp
        use.h
        use.cpp
        attack.cpp
        attack.h
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
