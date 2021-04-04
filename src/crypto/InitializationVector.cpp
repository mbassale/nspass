//
// Created by Marco Bassaletti on 12-03-21.
//

#include <gcrypt.h>
#include <vector>
#include "InitializationVector.h"

namespace NSPass::Crypto {

	std::vector<uint8_t> InitializationVectorFactory::make(size_t block_size)
	{
		std::vector<uint8_t> init_vector;
		init_vector.resize(block_size, 0);
		gcry_create_nonce(init_vector.data(), init_vector.size());
		return init_vector;
	}
}
