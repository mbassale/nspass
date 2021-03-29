//
// Created by Marco Bassaletti on 29-03-21.
//

#include "../../catch.hpp"
#include <sstream>
#include <boost/algorithm/string/join.hpp>
#include "../../../src/cli/output/CSVTableOutput.h"

using namespace std;
using OwnPass::CLI::Output::CSVTableOutputOptions;
using OwnPass::CLI::Output::CSVTableOutput;

class CSVTableOutputFixture {
public:
	CSVTableOutputFixture() = default;
protected:
	vector<string> headers = { "test1", "test2", "test3" };
};

TEST_CASE_METHOD(CSVTableOutputFixture, "CSVTableOutput - construct")
{
	ostringstream ss;
	CSVTableOutputOptions options{ ss };
	REQUIRE(options.column_separator == CSVTableOutputOptions::DefaultColumnSeparator);
	REQUIRE(options.max_rows == 0);
	REQUIRE(&(options.out) == &(ss));
	REQUIRE_NOTHROW(CSVTableOutput{ options, headers });
}

TEST_CASE_METHOD(CSVTableOutputFixture, "CSVTableOutput - output csv")
{
	ostringstream ss;
	CSVTableOutputOptions options{ ss };
	CSVTableOutput output{ options, headers };
	output.print_headers();
	string expected = boost::algorithm::join(headers, ",")+"\n";
	REQUIRE(ss.str() == expected);
	for (size_t i = 0; i < 10; i++) {
		auto row = { std::to_string(i+1), std::to_string(i+2), std::to_string(i+3) };
		output.print_row(row);
		expected += boost::algorithm::join(row, ",")+"\n";
		REQUIRE(ss.str() == expected);
	}
}
