//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_OWNPASS_H
#define OWNPASS_OWNPASS_H

#include <ctime>
#include <chrono>
#include <memory>
#include <string>
#include <string_view>
#include <list>
#include <vector>
#include <optional>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <filesystem>
#include <boost/uuid/uuid.hpp>
#include <boost/algorithm/string.hpp>
#include "IdGenerator.h"
#include "ApplicationException.h"

namespace OwnPass {
	typedef boost::uuids::uuid ObjectId;

	std::string object_id_to_string(ObjectId object_id);
	std::string timestamp_to_string(time_t timestamp);
}

#endif //OWNPASS_OWNPASS_H
