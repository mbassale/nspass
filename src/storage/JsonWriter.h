//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONWRITER_H
#define OWNPASS_JSONWRITER_H

#include <boost/json.hpp>

namespace OwnPass::Storage {
    class JsonWriter {
    public:
        JsonWriter(boost::json::value& root, const char* filename);
        void save();
    private:
        boost::json::value& root;
        const char* filename;
    };
}

#endif //OWNPASS_JSONWRITER_H
