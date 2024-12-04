add_library(day01_lib
    part1.cpp
    part2.cpp
    utils.cpp
)

target_link_libraries(day01_lib
    PUBLIC common_lib
)

target_include_directories(day01_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Create executable for day01
add_executable(day01
    main.cpp
)

target_link_libraries(day01
    PRIVATE day01_lib
)
