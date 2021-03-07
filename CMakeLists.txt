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
        src/IdGenerator.h src/IdGenerator.cpp
        src/storage/Storage.cpp src/storage/Storage.h
        src/storage/JsonStorage.h src/storage/JsonStorage.cpp
        src/storage/JsonParser.h src/storage/JsonParser.cpp
        src/storage/JsonWriter.h src/storage/JsonWriter.cpp
        src/storage/JsonSerializer.h src/storage/JsonSerializer.cpp
        src/storage/CategorySerializer.h src/storage/CategorySerializer.cpp
        src/storage/GroupSerializer.h src/storage/GroupSerializer.cpp)

# Password Manager
add_executable(ownpass src/main.cpp ${SOURCE_FILES})

# Test Suites
add_executable(tests src/test/test.cpp src/test/test_database.cpp ${SOURCE_FILES})

target_link_libraries(ownpass Boost::headers Boost::json)

target_link_libraries(tests Boost::headers Boost::json)
