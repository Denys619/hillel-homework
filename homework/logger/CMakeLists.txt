cmake_minimum_required(VERSION 3.10)
project(LoggingLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(logger
    libraries/logger/logger.cpp
    libraries/logger/log_sinks.cpp
)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE logger)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/libraries/logger)
