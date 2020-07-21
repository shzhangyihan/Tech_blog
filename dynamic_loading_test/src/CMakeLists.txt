add_executable(main main.cpp shape.cpp)
target_link_libraries(main dl)

add_library(circle SHARED circle.cpp shape.cpp)

