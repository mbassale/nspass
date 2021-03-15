//
// Created by Marco Bassaletti on 15-03-21.
//

#ifndef OWNPASS_ENCRYPTEDFILE_H
#define OWNPASS_ENCRYPTEDFILE_H

#include <string>
#include <sstream>

namespace OwnPass::Crypto
{
	class EncryptedFile {
	public:
		EncryptedFile(std::string_view filename, std::string_view shared_key);
		~EncryptedFile() = default;

		void encrypt(std::string_view contents);
		std::string decrypt();
	private:
		std::string_view filename;
		std::string_view shared_key;
	};
}

#endif //OWNPASS_ENCRYPTEDFILE_H
