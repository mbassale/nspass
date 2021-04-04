//
// Created by Marco Bassaletti on 24-03-21.
//
#include <boost/uuid/uuid_io.hpp>
#include "NSPass.h"

namespace NSPass {

	std::string object_id_to_string(ObjectId object_id)
	{
		return boost::uuids::to_string(object_id);
	}

	std::string timestamp_to_string(time_t timestamp)
	{
		std::tm* p_tm = std::localtime(&timestamp);
		char buffer[32] = {};
		std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", p_tm);
		return std::string(buffer);
	}

}
