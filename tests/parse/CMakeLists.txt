add_executable(t_parse main.cpp TestCommand.cpp)

target_link_libraries(t_parse AWE_Console)

add_test(NAME Parse COMMAND t_parse)
