//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include "sstream"
#include "test_runner.h"
#include "func_for_unit_test.hpp"

/*class Hello {
public:
	Hello(const std::string& name) : _name(name), _N(++n) {
		std::cout << _name << " born " << _N << std::endl;
	}
	Hello(const Hello& ot) {
		_name = ot._name;
		_N = ++n;
		std::cout << _name << " born copy " << _N << " from " << ot._N << std::endl;
	}
	Hello operator=(const Hello& hello) {
		std::cout << "oper =: " << this->_N << ' ' << hello._N << std::endl;
		//		this->_N = hello._N + 100;
		return *this;
	}
	~Hello() {
		std::cout << _name << " death " << _N << std::endl;
	}
	int getN() const {
		return 0;
	}
	static int n;

private:
	std::string _name;
	int _N;
};
int Hello::n = 0;

Hello h("hey");
Hello h1("HELLO");

std::cout << "======do" << std::endl;
ft::vector<Hello> hello;
hello.reserve(25);
hello.assign(12, h);
std::cout << "size: " << hello.size() << std::endl;
std::cout << "cap: " << hello.capacity() << std::endl;
//	hello.push_back(h1);
//	std::cout << "size: " << hello.size() << std::endl;
//	std::cout << "cap: " << hello.capacity() << std::endl;

hello.insert(hello.begin(), h);
std::cout << "hello[0] = " << hello[0].getN() << std::endl;
std::cout << "hello[0] = " << hello[1].getN() << std::endl;
std::cout << "size: " << hello.size() << std::endl;
std::cout << "cap: " << hello.capacity() << std::endl;
std::cout << "====================" << std::endl;*/

void unit_tests_insert() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(25);
		mv.reserve(25);
		sv.assign(12, 1);
		mv.assign(12, 1);
		UNIT_SIZE_INIT_SS
		svRes << "return value insert: " << *sv.insert(sv.begin(), 13) << std::endl;
		mvRes << "return value insert: " << *mv.insert(mv.begin(), 13) << std::endl;
		PRINT_V

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.erase(sv.begin() + static_cast<int>(sv.size()) - 1);
		mv.erase(mv.begin() + static_cast<int>(mv.size()) - 1);
		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(25);
		mv.reserve(25);
		sv.assign(13, 1);
		mv.assign(13, 1);
		UNIT_SIZE_INIT_SS
		svRes << "return value insert: " << *sv.insert(sv.begin(), 13) << std::endl;
		mvRes << "return value insert: " << *mv.insert(mv.begin(), 13) << std::endl;
		PRINT_V

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.erase(sv.begin() + static_cast<int>(sv.size()) - 1);
		mv.erase(mv.begin() + static_cast<int>(mv.size()) - 1);

		sv.insert(sv.begin(), 3, 3);
		mv.insert(mv.begin(), 3, 3);

		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(25);
		mv.reserve(25);
		sv.assign(13, 1);
		mv.assign(13, 1);
		UNIT_SIZE_INIT_SS
		svRes << "return value insert: " << *sv.insert(sv.begin(), 13) << std::endl;
		mvRes << "return value insert: " << *mv.insert(mv.begin(), 13) << std::endl;
		PRINT_V

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.erase(sv.begin() + static_cast<int>(sv.size()) - 1);
		mv.erase(mv.begin() + static_cast<int>(mv.size()) - 1);

		sv.insert(sv.begin() + 2, 3, 3);
		mv.insert(mv.begin() + 2, 3, 3);
		SIZE_PRINT_V

		sv.insert(sv.begin(), 7);
		mv.insert(mv.begin(), 7);
		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv(3);
		ft::vector<int> mv(3);
		std::stringstream svRes;
		std::stringstream mvRes;

		InitVector(sv, 1, true);
		InitVector(mv, 1, true);

		sv.insert(sv.end(), 3);
		mv.insert(mv.end(), 3);
		SIZE_PRINT_V

		sv.reserve(12);
		mv.reserve(12);

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.push_back(43);
		mv.push_back(43);
		SIZE_PRINT_V

		sv.insert(sv.begin() + 3, 5, 13);
		mv.insert(mv.begin() + 3, 5, 13);
		PRINT_V
		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}


	{
		std::vector<int> sv(3);
		ft::vector<int> mv(3);
		std::ostringstream svRes;
		std::ostringstream mvRes;

		InitVector(sv, 1, true);
		InitVector(mv, 1, true);

		sv.insert(sv.end(), 3);
		mv.insert(mv.end(), 3);
		SIZE_PRINT_V

		sv.reserve(12);
		mv.reserve(12);

		sv.push_back(67);
		sv.push_back(67);
		sv.push_back(67);
		mv.push_back(67);
		mv.push_back(67);
		mv.push_back(67);
		SIZE_PRINT_V


		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.push_back(43);
		mv.push_back(43);
		SIZE_PRINT_V

		sv.insert(sv.begin() + 3, 5, 13);
		mv.insert(mv.begin() + 3, 5, 13);
		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::ostringstream svRes;
		std::ostringstream mvRes;

		sv.insert(sv.begin(), 3);
		mv.insert(mv.begin(), 3);
		SIZE_PRINT_V

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		SIZE_PRINT_V

		sv.reserve(34);
		mv.reserve(34);
		SIZE_PRINT_V

		sv.insert(sv.end(), 35);
		mv.insert(mv.end(), 35);
		SIZE_PRINT_V


		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::ostringstream svRes;
		std::ostringstream mvRes;

		std::vector<int> sv1(10);
		ft::vector<int> mv1(10);

		InitVector(sv1, 1, true);
		InitVector(mv1, 1, true);
		PrintV(sv1, svRes);
		PrintV(mv1, mvRes);

		sv.insert(sv.begin(), 10, 13);
		mv.insert(mv.begin(), 10, 13);
		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::ostringstream svRes;
		std::ostringstream mvRes;

		std::vector<int> sv1(10);
		ft::vector<int> mv1(10);

		InitVector(sv1, 1, true);
		InitVector(mv1, 1, true);
		PrintV(sv1, svRes);
		PrintV(mv1, mvRes);

		sv.insert(sv.begin(), 10, 13);
		mv.insert(mv.begin(), 10, 13);
		SIZE_PRINT_V

		sv.insert(sv.begin(), sv.begin(), sv.end());
		mv.insert(mv.begin(), mv.begin(), mv.end());
		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::ostringstream svRes;
		std::ostringstream mvRes;

		sv.insert(sv.begin(), 0, 13);
		mv.insert(mv.begin(), 0, 13);
		SIZE_PRINT_V

		sv.insert(sv.begin(), sv.begin(), sv.end());
		mv.insert(mv.begin(), mv.begin(), mv.end());
		SIZE_PRINT_V

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}
}
