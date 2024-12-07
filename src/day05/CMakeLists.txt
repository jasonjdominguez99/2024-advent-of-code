add_library(day05_lib
    part1.cpp
)

target_link_libraries(day05_lib
    PUBLIC common_lib
)

target_include_directories(day05_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(day05
    main.cpp
)

target_link_libraries(day05
    PRIVATE day05_lib
)
