//
// Created by Marco Bassaletti on 12-03-21.
//

#include <algorithm>
#include <vector>
#include <random>
#include "InitializationVector.h"

namespace OwnPass::Crypto {

	std::vector<uint8_t> InitializationVectorFactory::make(size_t block_size)
	{
		std::vector<uint8_t> init_vector;
		init_vector.resize(block_size, 0);
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution<uint8_t> distribution(0, 255);
		std::generate(init_vector.begin(), init_vector.end(), [&]{ return distribution(generator); });
		return init_vector;
	}
}
