cmake_minimum_required(VERSION 3.17)
project(ownpass)

#SET(Boost_USE_STATIC_LIBS ON)
find_package(ICU REQUIRED COMPONENTS data)
find_package(Boost REQUIRED COMPONENTS json log program_options)
find_library(LIBGCRYPT_LIBRARIES gcrypt)


set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/OwnPass.h src/OwnPass.cpp
        src/Application.h src/Application.cpp
        src/ApplicationException.h src/ApplicationException.cpp
        src/Vault.h src/Vault.cpp
        src/Group.cpp src/Group.h
        src/Password.cpp src/Password.h
        src/Category.cpp src/Category.h
        src/IdGenerator.h src/IdGenerator.cpp
        src/cli/CommandLine.h src/cli/CommandLine.cpp
        src/cli/CommandParser.h src/cli/CommandParser.cpp
        src/cli/InvalidCommandSyntaxException.h src/cli/InvalidCommandSyntaxException.cpp
        src/cli/parsers/Parser.h src/cli/parsers/Parser.cpp
        src/cli/parsers/InspectStorageCommandParser.cpp src/cli/parsers/InspectStorageCommandParser.h
        src/cli/parsers/CreatePasswordCommandParser.h src/cli/parsers/CreatePasswordCommandParser.cpp
        src/cli/parsers/PurgeStorageCommandParser.h src/cli/parsers/PurgeStorageCommandParser.cpp
        src/cli/input/SecretInput.h
        src/cli/input/StringSecretInput.h src/cli/input/StringSecretInput.cpp
        src/cli/input/PromptSecretInput.h src/cli/input/PromptSecretInput.cpp
        src/cli/input/UserInput.cpp src/cli/input/UserInput.h
        src/cli/input/ConfirmInput.cpp src/cli/input/ConfirmInput.h
        src/cli/input/PromptConfirmInput.cpp src/cli/input/PromptConfirmInput.h
        src/cli/input/BoolConfirmInput.cpp src/cli/input/BoolConfirmInput.h
        src/commands/CannotUndoException.cpp src/commands/CannotUndoException.h
        src/commands/CommandRunner.h src/commands/CommandRunner.cpp
        src/commands/Command.h src/commands/Command.cpp
        src/commands/HelpCommand.h src/commands/HelpCommand.cpp
        src/commands/VerboseCommand.h src/commands/VerboseCommand.cpp
        src/commands/VersionCommand.h src/commands/VersionCommand.cpp
        src/commands/InspectStorageCommand.cpp src/commands/InspectStorageCommand.h
        src/commands/CreatePasswordCommand.h src/commands/CreatePasswordCommand.cpp
        src/commands/PurgeStorageCommand.h src/commands/PurgeStorageCommand.cpp
        src/storage/Storage.cpp src/storage/Storage.h
        src/storage/StorageFactory.cpp src/storage/StorageFactory.h
        src/storage/StorageHeader.cpp src/storage/StorageHeader.h
        src/storage/StorageException.cpp src/storage/StorageException.h
        src/storage/InvalidStorageException.cpp src/storage/InvalidStorageException.h
        src/storage/JsonStorage.h src/storage/JsonStorage.cpp
        src/storage/JsonStorageFactory.cpp src/storage/JsonStorageFactory.h
        src/storage/JsonParser.h src/storage/JsonParser.cpp
        src/storage/JsonWriter.h src/storage/JsonWriter.cpp
        src/storage/serializer/JsonSerializer.h src/storage/serializer/JsonSerializer.cpp
        src/storage/serializer/CategorySerializer.h src/storage/serializer/CategorySerializer.cpp
        src/storage/serializer/GroupSerializer.h src/storage/serializer/GroupSerializer.cpp
        src/storage/serializer/PasswordSerializer.h src/storage/serializer/PasswordSerializer.cpp
        src/storage/serializer/StorageHeaderSerializer.cpp src/storage/serializer/StorageHeaderSerializer.h
        src/storage/serializer/StorageSerializer.cpp src/storage/serializer/StorageSerializer.h
        src/crypto/InitCrypto.h src/crypto/InitCrypto.cpp
        src/crypto/BlockCrypto.h src/crypto/BlockCrypto.cpp
        src/crypto/StringCrypto.h src/crypto/StringCrypto.cpp
        src/crypto/Base64Encoder.h src/crypto/Base64Encoder.cpp
        src/crypto/InitializationVector.h src/crypto/InitializationVector.cpp
        src/crypto/SecureString.h src/crypto/SecureString.cpp
        src/crypto/EncryptedFile.h src/crypto/EncryptedFile.cpp)

set(TEST_FILES
        test/TestUtility.h
        test/TestUtility.cpp
        test/test_main.cpp
        test/test_models.cpp
        test/test_vault.cpp
        #test/test_json_storage.cpp
        test/test_command_line.cpp
        test/crypto/test_initialization_vector.cpp
        test/crypto/test_base64_encoder.cpp
        test/crypto/test_block_crypto.cpp
        test/crypto/test_string_crypto.cpp
        test/crypto/test_secure_string.cpp
        test/crypto/test_encrypted_file.cpp
        test/cli/test_command_parser.cpp
        test/cli/parsers/test_inspect_storage_command_parser.cpp
        test/cli/parsers/test_create_password_command_parser.cpp
        test/cli/parsers/test_purge_storage_command_parser.cpp
        test/cli/input/test_string_secret_input.cpp
        test/cli/input/test_prompt_secret_input.cpp
        test/cli/input/test_prompt_confirm_input.cpp
        test/cli/input/test_bool_confirm_input.cpp
        test/commands/test_command_runner.cpp
        test/storage/test_storage_header.cpp
        test/storage/serializers/test_storage_header_serializer.cpp
        test/storage/serializers/test_storage_serializer.cpp
        test/storage/serializers/test_password_serializer.cpp
        test/storage/serializers/test_group_serializer.cpp)

include_directories(${Boost_INCLUDE_DIRS})

link_directories(${ICU_LIBRARY_DIRS})

# Password Manager
add_executable(ownpass src/main.cpp ${SOURCE_FILES})
# Test Suites
add_executable(tests ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(ownpass ${Boost_LIBRARIES} ${LIBGCRYPT_LIBRARIES} ${ICU_LIBRARIES})

target_link_libraries(tests ${Boost_LIBRARIES} ${LIBGCRYPT_LIBRARIES} ${ICU_LIBRARIES})
