//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_IDGENERATOR_H
#define OWNPASS_IDGENERATOR_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace NSPass {
	class IdGenerator {
	public:
		static boost::uuids::uuid make() { return boost::uuids::random_generator()(); }
	};
}

#endif //OWNPASS_IDGENERATOR_H
