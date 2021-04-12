//
// Created by Marco Bassaletti on 12-04-21.
//
#include "../catch.hpp"
#include <string>
#include <memory>
#include <functional>
#include "../../src/signals/Signal.h"

using NSPass::Signals::Signal;

class SignalFixture {
public:
	static constexpr auto Tag = "[signal]";
	SignalFixture() = default;
protected:
	size_t invoke_count = 0;
};

typedef std::function<void(const std::string&, const std::string&)> StringSlotFunction;

class TestSignal : public Signal<StringSlotFunction, const std::string&, const std::string&> {
};

TEST_CASE_METHOD(SignalFixture, "Signal - construct", SignalFixture::Tag)
{
	REQUIRE_NOTHROW(TestSignal{});
}

TEST_CASE_METHOD(SignalFixture, "Signal - connect", SignalFixture::Tag)
{
	TestSignal test_signal{};
	test_signal.connect([&](const std::string& s1, const std::string& s2) { });
	test_signal.connect([&](const std::string& s1, const std::string& s2) { });
	test_signal.connect([&](const std::string& s1, const std::string& s2) { });
	REQUIRE_FALSE(test_signal.get_slots().empty());
	REQUIRE(test_signal.get_slots().size() == 3);
}

TEST_CASE_METHOD(SignalFixture, "Signal - invoke", SignalFixture::Tag)
{
	TestSignal test_signal{};
	test_signal.connect([&](const std::string& s1, const std::string& s2) {
		REQUIRE(s1 == s2);
		invoke_count++;
	});
	test_signal.connect([&](const std::string& s1, const std::string& s2) {
		REQUIRE(s1 == s2);
		invoke_count++;
	});
	test_signal.connect([&](const std::string& s1, const std::string& s2) {
		REQUIRE(s1 == s2);
		invoke_count++;
	});
	std::string s1{ "test" };
	std::string s2{ "test" };
	test_signal.invoke(s1, s2);
	REQUIRE(invoke_count == 3);
}
