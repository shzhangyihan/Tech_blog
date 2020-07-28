add_executable(main main.cpp test.cpp)
target_link_libraries(main dl)

add_library(counter SHARED counter.c)

