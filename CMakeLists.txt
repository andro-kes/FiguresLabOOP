cmake_minimum_required(VERSION 3.12)
project(Figure)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include(GoogleTest)

# Добавление исполняемого файла
add_executable(figure
    src/figure.cpp
    src/figure.h
    src/main.cpp
    src/triangle.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/array.cpp
)

add_executable(test_figure
    test/test_figure.cpp
    src/figure.cpp
    src/triangle.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/array.cpp
    src/figure.h
)

# Связывание тестов с Google Test
target_link_libraries(test_figure GTest::GTest GTest::Main)

# Добавление тестов в CTest
gtest_discover_tests(test_figure)

# Настройка компилятора
target_compile_features(figure PRIVATE cxx_std_14)
target_compile_options(figure PRIVATE -Wall -Wextra -Wpedantic)
target_compile_features(test_figure PRIVATE cxx_std_14)
target_compile_options(test_figure PRIVATE -Wall -Wextra -Wpedantic)