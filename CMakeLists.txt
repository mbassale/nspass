cmake_minimum_required(VERSION 3.17)
project(mbassale_pm)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# Password Manager
add_executable(mbassale_pm main.cpp Group.cpp Group.h Password.cpp Password.h Site.cpp Site.h Application.cpp Application.h)

# Test Suites
add_executable(tests test/test.cpp Group.cpp Group.h Password.cpp Password.h Site.cpp Site.h Application.cpp Application.h)

target_link_libraries(mbassale_pm Boost::headers)
