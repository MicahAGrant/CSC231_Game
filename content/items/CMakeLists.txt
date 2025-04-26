add_library(items
        bite.cpp bite.h
        potion.cpp potion.h
        sword_red_gem.h sword_red_gem.cpp
        sword_red_gem.cpp
        sword_red_gem.h
        knife.cpp
        knife.h
        staff_green.cpp
        staff_green.h
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
