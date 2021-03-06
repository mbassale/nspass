cmake_minimum_required(VERSION 3.17)
project(ownpass)

find_package(Boost REQUIRED)
find_package(SQLite3 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# Password Manager
add_executable(ownpass main.cpp Group.cpp Group.h Password.cpp Password.h Site.cpp Site.h Application.cpp Application.h Category.cpp Category.h Database.cpp Database.h)

# Test Suites
add_executable(tests test/test.cpp Group.cpp Group.h Password.cpp Password.h Site.cpp Site.h Application.cpp Application.h Category.cpp Category.h)

target_link_libraries(ownpass Boost::headers ${SQLite3_LIBRARIES})

target_link_libraries(tests Boost::headers ${SQLite3_LIBRARIES})
