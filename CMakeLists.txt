cmake_minimum_required(VERSION 3.17)
project(nspass)

#SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS json program_options)
find_library(LIBGCRYPT_LIBRARIES gcrypt)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(CLIP_EXAMPLES OFF CACHE BOOL "Compile clip examples")
set(CLIP_TESTS OFF CACHE BOOL "Compile clip tests")
set(CLIP_X11_WITH_PNG OFF CACHE BOOL "Compile with libpng to support copy/paste image in png format")
add_subdirectory(clip)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/NSPass.h src/NSPass.cpp
        src/Application.h src/Application.cpp
        src/ApplicationException.h src/ApplicationException.cpp
        src/Vault.h src/Vault.cpp
        src/Group.cpp src/Group.h
        src/Password.cpp src/Password.h
        src/Category.cpp src/Category.h
        src/IdGenerator.h src/IdGenerator.cpp
        src/config/Settings.cpp src/config/Settings.h
        src/config/MacSettings.mm src/config/MacSettings.h
        src/query/Query.cpp src/query/Query.h
        src/query/CategoryQuery.cpp src/query/CategoryQuery.h
        src/query/GroupQuery.cpp src/query/GroupQuery.h
        src/query/PasswordQuery.cpp src/query/PasswordQuery.h
        src/query/RecordNotFoundException.h
        src/query/CategoryNotFoundException.h
        src/query/GroupNotFoundException.h
        src/query/PasswordNotFoundException.h
        src/cli/CommandLine.h src/cli/CommandLine.cpp
        src/cli/CommandParser.h src/cli/CommandParser.cpp
        src/cli/InvalidCommandSyntaxException.h src/cli/InvalidCommandSyntaxException.cpp
        src/cli/parsers/Parser.h src/cli/parsers/Parser.cpp
        src/cli/parsers/ListCommandParser.cpp src/cli/parsers/ListCommandParser.h
        src/cli/parsers/CreatePasswordCommandParser.h src/cli/parsers/CreatePasswordCommandParser.cpp
        src/cli/parsers/UpdatePasswordCommandParser.cpp src/cli/parsers/UpdatePasswordCommandParser.h
        src/cli/parsers/DeletePasswordCommandParser.cpp src/cli/parsers/DeletePasswordCommandParser.h
        src/cli/parsers/CopyPasswordCommandParser.cpp src/cli/parsers/CopyPasswordCommandParser.h
        src/cli/parsers/ImportCommandParser.cpp src/cli/parsers/ImportCommandParser.h
        src/cli/parsers/InspectStorageCommandParser.cpp src/cli/parsers/InspectStorageCommandParser.h
        src/cli/parsers/DumpStorageCommandParser.cpp src/cli/parsers/DumpStorageCommandParser.h
        src/cli/parsers/PurgeStorageCommandParser.h src/cli/parsers/PurgeStorageCommandParser.cpp
        src/cli/input/SecretInput.h
        src/cli/input/StringSecretInput.h src/cli/input/StringSecretInput.cpp
        src/cli/input/PromptSecretInput.h src/cli/input/PromptSecretInput.cpp
        src/cli/input/UserInput.cpp src/cli/input/UserInput.h
        src/cli/input/ConfirmInput.cpp src/cli/input/ConfirmInput.h
        src/cli/input/PromptConfirmInput.cpp src/cli/input/PromptConfirmInput.h
        src/cli/input/BoolConfirmInput.cpp src/cli/input/BoolConfirmInput.h
        src/cli/output/TableOutput.cpp src/cli/output/TableOutput.h
        src/cli/output/TableOutputFactory.cpp src/cli/output/TableOutputFactory.h
        src/cli/output/StreamTableOutput.cpp src/cli/output/StreamTableOutput.h
        src/cli/output/CSVTableOutput.cpp src/cli/output/CSVTableOutput.h
        src/commands/CannotUndoException.cpp src/commands/CannotUndoException.h
        src/commands/CommandRunner.h src/commands/CommandRunner.cpp
        src/commands/Command.h src/commands/Command.cpp
        src/commands/HelpCommand.h src/commands/HelpCommand.cpp
        src/commands/VerboseCommand.h src/commands/VerboseCommand.cpp
        src/commands/VersionCommand.h src/commands/VersionCommand.cpp
        src/commands/InspectStorageCommand.cpp src/commands/InspectStorageCommand.h
        src/commands/CreatePasswordCommand.h src/commands/CreatePasswordCommand.cpp
        src/commands/UpdatePasswordCommand.cpp src/commands/UpdatePasswordCommand.h
        src/commands/DeletePasswordCommand.cpp src/commands/DeletePasswordCommand.h
        src/commands/PurgeStorageCommand.h src/commands/PurgeStorageCommand.cpp
        src/commands/SetStorageLocationCommand.cpp src/commands/SetStorageLocationCommand.h
        src/commands/DumpStorageCommand.cpp src/commands/DumpStorageCommand.h
        src/commands/ListCommand.cpp src/commands/ListCommand.h
        src/commands/ListCategoriesCommand.cpp src/commands/ListCategoriesCommand.h
        src/commands/ListGroupsCommand.cpp src/commands/ListGroupsCommand.h
        src/commands/ListPasswordsCommand.cpp src/commands/ListPasswordsCommand.h
        src/commands/CopyPasswordCommand.cpp src/commands/CopyPasswordCommand.h
        src/commands/ImportLastPassCommand.cpp src/commands/ImportLastPassCommand.h
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

set(GUI_FILES src/gui/GlobalIds.h
        src/gui/App.h src/gui/App.cpp
        src/gui/MainFrame.cpp src/gui/MainFrame.h
        src/gui/TreeView.cpp src/gui/TreeView.h
        src/gui/ContentPanel.cpp src/gui/ContentPanel.h
        src/gui/MainMenuBar.cpp src/gui/MainMenuBar.h
        src/gui/BaseCategoryForm.cpp src/gui/BaseCategoryForm.h
        src/gui/CategoryForm.cpp src/gui/CategoryForm.h)
if(APPLE)
    # Add an icon for the apple .app file
    list(APPEND GUI_FILES ./assets/icons/wxmac.icns)
endif()

set(TEST_FILES
        test/TestUtility.h test/TestUtility.cpp
        test/SampleStorageFixture.cpp test/SampleStorageFixture.h
        test/test_main.cpp
        test/test_models.cpp
        test/test_vault.cpp
        test/test_command_line.cpp
        test/config/test_settings.cpp
        test/config/test_mac_settings.cpp
        test/query/test_category_query.cpp
        test/query/test_group_query.cpp
        test/query/test_password_query.cpp
        test/crypto/test_initialization_vector.cpp
        test/crypto/test_base64_encoder.cpp
        test/crypto/test_block_crypto.cpp
        test/crypto/test_string_crypto.cpp
        test/crypto/test_secure_string.cpp
        test/crypto/test_encrypted_file.cpp
        test/cli/test_command_parser.cpp
        test/cli/parsers/test_list_command_parser.cpp
        test/cli/parsers/test_import_command_parser.cpp
        test/cli/parsers/test_create_password_command_parser.cpp
        test/cli/parsers/test_update_password_command_parser.cpp
        test/cli/parsers/test_delete_password_command_parser.cpp
        test/cli/parsers/test_copy_password_command_parser.cpp
        test/cli/parsers/test_inspect_storage_command_parser.cpp
        test/cli/parsers/test_purge_storage_command_parser.cpp
        test/cli/parsers/test_dump_storage_command_parser.cpp
        test/cli/input/test_string_secret_input.cpp
        test/cli/input/test_prompt_secret_input.cpp
        test/cli/input/test_prompt_confirm_input.cpp
        test/cli/input/test_bool_confirm_input.cpp
        test/cli/output/test_csv_table_output.cpp
        test/commands/test_command_runner.cpp
        test/commands/test_copy_password_command.cpp
        test/commands/test_update_password_command.cpp
        test/commands/test_delete_password_command.cpp
        test/commands/test_import_lastpass_command.cpp
        test/storage/test_storage_header.cpp
        test/storage/serializers/test_storage_header_serializer.cpp
        test/storage/serializers/test_storage_serializer.cpp
        test/storage/serializers/test_password_serializer.cpp
        test/storage/serializers/test_group_serializer.cpp
        test/storage/serializers/test_category_serializer.cpp
        test/storage/test_json_storage.cpp)

include_directories(${Boost_INCLUDE_DIRS})

# Password Manager Command Line
add_executable(nspass src/main.cpp ${SOURCE_FILES})

# Password Manager GUI
add_executable(nspass-gui WIN32 MACOSX_BUNDLE ${GUI_FILES} ${SOURCE_FILES})

# Test Suites
add_executable(tests ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(nspass clip ${Boost_LIBRARIES} ${LIBGCRYPT_LIBRARIES})

target_link_libraries(nspass-gui clip ${Boost_LIBRARIES} ${LIBGCRYPT_LIBRARIES} ${wxWidgets_LIBRARIES})

target_link_libraries(tests clip ${Boost_LIBRARIES} ${LIBGCRYPT_LIBRARIES} ${wxWidgets_LIBRARIES})

install(TARGETS nspass DESTINATION bin)

if(APPLE)
    set_target_properties(nspass-gui PROPERTIES
            OUTPUT_NAME "nspass"
            RESOURCE "./assets/icons/wxmac.icns"
            MACOSX_BUNDLE_ICON_FILE wxmac.icns
            MACOSX_BUNDLE_COPYRIGHT "Copyright Marco Bassaletti <bassaletti@gmail.com>"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.mbassale.nspass"
            )
endif()
