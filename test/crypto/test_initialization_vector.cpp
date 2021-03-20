//
// Created by Marco Bassaletti on 12-03-21.
//

#include <vector>
#include "../catch.hpp"
#include "../../src/crypto/InitializationVector.h"

using namespace std;
using namespace OwnPass::Crypto;

class InitializationVectorFixture {
public:
	InitializationVectorFixture() {}
protected:
	void assert_init_vector(vector<uint8_t> init_vector, size_t block_size)
	{
		REQUIRE(init_vector.size() == block_size);
		REQUIRE(count_if(init_vector.begin(), init_vector.end(), [](auto& value){ return value >= 0 && value <= 255; }) == block_size);
	}
};

TEST_CASE_METHOD(InitializationVectorFixture, "make")
{
	assert_init_vector(InitializationVectorFactory::make(16), 16);
	assert_init_vector(InitializationVectorFactory::make(32), 32);
	assert_init_vector(InitializationVectorFactory::make(64), 64);
}
