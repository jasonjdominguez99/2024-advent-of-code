add_library(day03_lib
    part1.cpp
    part2.cpp
)

target_link_libraries(day03_lib
    PUBLIC common_lib
)

target_include_directories(day03_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(day03
    main.cpp
)

target_link_libraries(day03
    PRIVATE day03_lib
)
