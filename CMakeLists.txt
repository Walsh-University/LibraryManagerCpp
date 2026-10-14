cmake_minimum_required(VERSION 4.3)
project(LibraryManagerCpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenSSL REQUIRED)
find_package(SQLite3 REQUIRED)

add_library(library_manager
        src/SecureString.cpp
        includes/library_manager/SecureString.h
)
target_include_directories(library_manager PUBLIC includes)
target_link_libraries(library_manager PUBLIC OpenSSL::Crypto SQLite3::SQLite3)
target_compile_options(library_manager PRIVATE
        $<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-Wall;-Wextra;-Wpedantic;-Wconversion>
)

add_executable(library_manager_app src/main.cpp)
target_link_libraries(library_manager_app PRIVATE library_manager)

option(BUILD_TESTING "Build the test suite" ON)
if(BUILD_TESTING)
    enable_testing()
    add_executable(library_manager_tests tests/library_manager_tests.cpp)
    target_link_libraries(library_manager_tests PRIVATE library_manager)
    add_test(NAME library_manager_tests COMMAND library_manager_tests)
endif()
