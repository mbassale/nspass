//
// Created by Marco Bassaletti on 15-03-21.
//

#include <string>
#include <sstream>
#include <fstream>
#include "StringCrypto.h"
#include "EncryptedFile.h"

namespace NSPass::Crypto {
	using namespace std;

	EncryptedFile::EncryptedFile(std::string_view filename, std::string_view shared_key)
			:filename{ filename, }, shared_key{ shared_key }
	{
	}

	void EncryptedFile::encrypt(std::string_view contents)
	{
		StringCrypto string_crypto{ shared_key };
		std::string encrypted_contents = string_crypto.encrypt(contents);
		ofstream outfile(filename, ios::binary | ios::out);
		if (!outfile.is_open()) {
			ostringstream error_message;
			error_message << "cannot open file: " << filename << " for writing.";
			throw std::runtime_error(error_message.str());
		}
		outfile.write(encrypted_contents.c_str(), encrypted_contents.size());
		outfile.close();
	}

	std::string EncryptedFile::decrypt()
	{
		ifstream infile(filename, ios::binary | ios::in);
		if (!infile.is_open()) {
			ostringstream error_message;
			error_message << "cannot open file: " << filename << " for reading.";
			throw std::runtime_error(error_message.str());
		}

		std::stringstream  in_str_stream;
		in_str_stream << infile.rdbuf();
		std::string encrypted_contents = in_str_stream.str();
		StringCrypto string_crypto{ shared_key };
		return string_crypto.decrypt(encrypted_contents);
	}
}
