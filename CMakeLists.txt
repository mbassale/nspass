cmake_minimum_required(VERSION 3.17)
project(ownpass)

find_package(Boost REQUIRED COMPONENTS Json)
find_library(LIBGCRYPT_LIBRARIES gcrypt)


set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/Vault.h src/Vault.cpp
        src/Group.cpp src/Group.h
        src/Password.cpp src/Password.h
        src/Category.cpp src/Category.h
        src/IdGenerator.h src/IdGenerator.cpp
        src/storage/Storage.cpp src/storage/Storage.h
        src/storage/JsonStorage.h src/storage/JsonStorage.cpp
        src/storage/JsonParser.h src/storage/JsonParser.cpp
        src/storage/JsonWriter.h src/storage/JsonWriter.cpp
        src/storage/JsonSerializer.h src/storage/JsonSerializer.cpp
        src/storage/CategorySerializer.h src/storage/CategorySerializer.cpp
        src/storage/GroupSerializer.h src/storage/GroupSerializer.cpp
        src/storage/PasswordSerializer.h src/storage/PasswordSerializer.cpp
        src/crypto/BlockCrypto.h src/crypto/BlockCrypto.cpp
        src/crypto/StringCrypto.h src/crypto/StringCrypto.cpp
        src/crypto/Base64Encoder.h src/crypto/Base64Encoder.cpp
        src/crypto/InitializationVector.h src/crypto/InitializationVector.cpp)

set(TEST_FILES
        src/test/test.cpp
        src/test/test_vault.cpp
        src/test/test_json_storage.cpp
        src/test/crypto/test_initialization_vector.cpp
        src/test/crypto/test_base64_encoder.cpp
        src/test/crypto/test_block_crypto.cpp
        src/test/crypto/test_string_crypto.cpp)

# Password Manager
add_executable(ownpass src/main.cpp ${SOURCE_FILES})

# Test Suites
add_executable(tests ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(ownpass Boost::headers Boost::json ${LIBGCRYPT_LIBRARIES})

target_link_libraries(tests Boost::headers Boost::json ${LIBGCRYPT_LIBRARIES})
