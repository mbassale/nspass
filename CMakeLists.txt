cmake_minimum_required(VERSION 3.17)
project(ownpass)

find_package(Boost REQUIRED COMPONENTS Json)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/Group.cpp src/Group.h
        src/Password.cpp src/Password.h
        src/Site.cpp src/Site.h
        src/Application.cpp src/Application.h
        src/Category.cpp src/Category.h
        src/Storage.cpp src/Storage.h
        src/JSONStorage.h src/JSONStorage.cpp)

# Password Manager
add_executable(ownpass src/main.cpp ${SOURCE_FILES})

# Test Suites
add_executable(tests src/test/test.cpp src/test/test_database.cpp ${SOURCE_FILES})

target_link_libraries(ownpass Boost::headers)

target_link_libraries(tests Boost::headers)
