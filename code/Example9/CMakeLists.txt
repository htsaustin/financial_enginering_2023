cmake_minimum_required(VERSION 3.5)  # CMake version check
project(financial_engineering_2023)  # Create project "financial_engineering_2023"
set(CMAKE_CXX_STANDARD 17)           # Enable c++17 standard

file(GLOB SOURCES "src/*.cpp")


add_executable(financial_engineering_2023 ${SOURCES})

target_include_directories(financial_engineering_2023
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )