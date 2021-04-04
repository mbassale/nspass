//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_NSPASS_H
#define OWNPASS_NSPASS_H

#include <ctime>
#include <chrono>
#include <memory>
#include <iterator>
#include <string>
#include <string_view>
#include <regex>
#include <array>
#include <list>
#include <vector>
#include <optional>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>
#include <boost/uuid/uuid.hpp>
#include <boost/algorithm/string.hpp>
#include "IdGenerator.h"
#include "ApplicationException.h"

namespace NSPass {
	typedef boost::uuids::uuid ObjectId;

	std::string object_id_to_string(ObjectId object_id);
	std::string timestamp_to_string(time_t timestamp);
}

#endif //OWNPASS_NSPASS_H
