cmake_minimum_required(VERSION 3.10)
project(NumberProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Додаємо виконуваний файл
add_executable(number_processor
    main.cpp
    reader/number_reader.cpp
    reader/number_reader.h
    processor/number_processor.cpp
    processor/number_processor.h
    observers/number_observer.cpp
    observers/number_observer.h
    filters/filter_factory.cpp
    filters/filter_factory.h
    filters/number_filters.cpp
    filters/number_filters.h
)

# Включаємо директорії для заголовочних файлів
target_include_directories(number_processor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/reader
    ${CMAKE_CURRENT_SOURCE_DIR}/processor
    ${CMAKE_CURRENT_SOURCE_DIR}/observers
    ${CMAKE_CURRENT_SOURCE_DIR}/filters
)
