//
// Created by Marco Bassaletti on 21-03-21.
//
#include "../clip/clip.h"
#include <filesystem>
#include "TestUtility.h"

int TestUtility::get_argc(const char* argv[])
{
	int count = 0;
	for (char** ptr = const_cast<char**>(argv); *ptr != nullptr; ptr++) count++;
	return count;
}

std::string TestUtility::convert_json_to_string(const boost::json::object& json)
{
	std::stringstream ss;
	ss << json;
	return ss.str();
}

boost::json::object TestUtility::convert_string_to_json(std::string_view str)
{
	boost::json::parser p;
	p.reset();
	p.write(str.data());
	auto root = p.release();
	return root.as_object();
}

uint32_t TestUtility::random_integer(uint32_t min, uint32_t max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint32_t> distrib(min, max);
	return distrib(gen);
}

std::string TestUtility::random_string(size_t length)
{
	const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
	const size_t max_index = (sizeof(charset)-1);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, max_index-1);
	auto randchar = [&charset, &distrib, &gen]() -> char {
		return charset[distrib(gen)];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

std::string TestUtility::get_random_filename()
{
	auto random_filename = TestUtility::random_string(16)+".dat";
	if (std::filesystem::exists(random_filename))
		std::filesystem::remove(random_filename);
	return random_filename;
}
std::string TestUtility::get_clipboard_text()
{
	std::string value;
	clip::get_text(value);
	return value;
}

std::pair<int, std::unique_ptr<const char*>> TestUtility::create_command_line_args(
		const std::vector<std::string>& args)
{
	const char** argv = new const char* [args.size()+1];
	for (size_t i = 0; i < args.size(); i++) {
		argv[i] = args[i].c_str();
	}
	argv[args.size()] = nullptr;
	int argc = TestUtility::get_argc(argv);
	return std::pair<int, std::unique_ptr<const char*>>{ argc, std::unique_ptr<const char*>(argv) };
}
