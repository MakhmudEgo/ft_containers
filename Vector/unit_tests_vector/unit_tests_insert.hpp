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
}
