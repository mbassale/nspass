//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONPARSER_H
#define OWNPASS_JSONPARSER_H

#include <boost/json.hpp>

namespace OwnPass::DB {
    class JsonParser {
    public:
        explicit JsonParser(const char* filename);
        void load();
        void parse();
        void create_empty();

        [[nodiscard]] boost::json::value get_root() noexcept { return root; }
    private:
        const char* filename;
        boost::json::value root;
    };
}


#endif //OWNPASS_JSONPARSER_H
