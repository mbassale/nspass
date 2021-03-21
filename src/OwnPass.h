//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_OWNPASS_H
#define OWNPASS_OWNPASS_H

#include <memory>
#include <string>
#include <string_view>
#include <list>
#include <vector>
#include <optional>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <boost/uuid/uuid.hpp>
#include "IdGenerator.h"
#include "ApplicationException.h"

namespace OwnPass {
	typedef boost::uuids::uuid ObjectId;
}

#endif //OWNPASS_OWNPASS_H
