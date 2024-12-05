add_library(day02_lib
    part1.cpp
    utils.cpp
)

target_link_libraries(day02_lib
    PUBLIC common_lib
)

target_include_directories(day02_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(day02
    main.cpp
)

target_link_libraries(day02
    PRIVATE day02_lib
)
