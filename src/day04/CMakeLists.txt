add_library(day04_lib
    part1.cpp
    part2.cpp
)

target_link_libraries(day04_lib
    PUBLIC common_lib
)

target_include_directories(day04_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(day04
    main.cpp
)

target_link_libraries(day04
    PRIVATE day04_lib
)
