//
// Created by Mahmud Jego on 5/2/21.
//

#pragma once

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


#define RESET_COLOR "\x1b[0m\n"

/*template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}*/

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = std::string()) {
	if (!(t == u)) {
		std::ostringstream os;
		os << "Assertion failed: " << std::endl << t << " != " << std::endl << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw std::runtime_error(os.str());
	}
	std::cout << "\x1b[42m" << "first arg\n" << t << RESET_COLOR;
	std::cout << "\x1b[43m" << "second arg\n" << u << RESET_COLOR;
}

inline void Assert(bool b, const std::string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	TestRunner() : fail_count(0) {}
	template <class TestFunc>
	void RunTest(TestFunc func, const std::string& test_name) {
		try {
			func();
			std::cout << "\x1b[32m" << test_name << " OK" << RESET_COLOR << std::endl;
		} catch (std::exception& e) {
			++fail_count;
			std::cout << "\x1b[31m" << test_name << " fail: " << e.what() << RESET_COLOR << std::endl;
		} catch (...) {
			++fail_count;
			std::cout << "\x1b[31m" << "Unknown exception caught" << RESET_COLOR << std::endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			std::cout << "\x1b[31m" << fail_count << " unit tests failed. Terminate" << RESET_COLOR << std::endl;
			exit(1);
		}
	}

private:
	int fail_count;
};

#define ASSERT_EQUAL(x, y) {            \
  std::ostringstream os;                     \
  os << #x << " != " << #y << ", "      \
    << __FILE__ << ":" << __LINE__;     \
  AssertEqual(x, y, os.str());          \
}

#define ASSERT(x) {                     \
  ostringstream os;                     \
  os << #x << " is false, "             \
    << __FILE__ << ":" << __LINE__;     \
  Assert(x, os.str());                  \
}

#define RUN_TEST(tr, func) \
  tr.RunTest(func, #func)


