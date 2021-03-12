//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_INITIALIZATIONVECTOR_H
#define OWNPASS_INITIALIZATIONVECTOR_H

#include <vector>
#include <memory>

namespace OwnPass::Crypto {
	class InitializationVectorFactory {
	public:
		static std::vector<uint8_t> make(size_t block_size);
	};
}

#endif //OWNPASS_INITIALIZATIONVECTOR_H
