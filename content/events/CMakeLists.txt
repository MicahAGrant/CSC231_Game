add_library(events
  updatefov.cpp
        hit.cpp
        hit.h
        die.cpp
        die.h
        thrust.cpp
        thrust.h
        swing.cpp
        swing.h
        animationevent.cpp
        animationevent.h
        animationspin.cpp
        animationspin.h
        audioevent.cpp
        audioevent.h
        pickup.cpp
        pickup.h
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
