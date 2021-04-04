//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONPARSER_H
#define OWNPASS_JSONPARSER_H

#include <sstream>
#include <boost/json.hpp>

namespace NSPass::Storage {
	class JsonParser {
	public:
		explicit JsonParser(std::string_view contents);
		void load();
		void parse();
		void create_empty();

		[[nodiscard]] boost::json::value get_root() noexcept { return root; }
	private:
		std::string_view contents;
		boost::json::value root;
	};
}

#endif //OWNPASS_JSONPARSER_H
