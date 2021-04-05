//
// Created by Marco Bassaletti on 05-04-21.
//
#include <CoreFoundation/CoreFoundation.h>
#include <Foundation/Foundation.h>
#include "MacSettings.h"

namespace NSPass::Config {

	constexpr auto DATA_DIRECTORY_NAME = "com.mbassale.nspass";

	std::string MacSettings::get_data_directory()
	{
		NSFileManager* fileManager = [NSFileManager defaultManager];
		NSURL* homeDirURL = [NSURL fileURLWithPath:NSHomeDirectory() isDirectory:YES];
		NSError* error = nil;
		NSURL* applicationSupportDir = [fileManager URLForDirectory:NSApplicationSupportDirectory
														   inDomain:NSUserDomainMask
												  appropriateForURL:homeDirURL
															 create:YES
															  error:&error];
		if (error) {
			throw ApplicationException("Cannot get app data directory");
		}

		BOOL isDir = false;
		NSString* appDir = [NSString stringWithUTF8String:(DATA_DIRECTORY_NAME)];
		NSString* directoryStr = [applicationSupportDir path];
		NSString* appDataDir = [NSString stringWithFormat:@"%@/%@", directoryStr, appDir];
		if (![fileManager fileExistsAtPath:(appDataDir) isDirectory:(&isDir)]) {
			if (![fileManager createDirectoryAtPath:(appDataDir) withIntermediateDirectories:(YES) attributes:(nil) error:(NULL)]) {
				throw ApplicationException("Cannot create app data directory");
			}
		}

		return std::string([appDataDir UTF8String]);
	}

	std::string MacSettings::get_temp_directory()
	{
		NSString* tempDir = NSTemporaryDirectory();
		return std::string([tempDir UTF8String]);
	}
}
