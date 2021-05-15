//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

#include "func_for_unit_test.hpp"
#include "unit_tests_vector.hpp"
#include "unit_test_iterator.hpp"
#include "unit_test_size.hpp"
#include "unit_test_assign.hpp"
#include "unit_test_erase.hpp"
#include "unit_tests_push_back.hpp"
#include "unit_tests_insert.hpp"
#include "unit_tests_pop.hpp"
#include "unit_tests_swap.hpp"
#include "unit_tests_cmp_oper.hpp"
#include "unit_tests_reverse_iterator.hpp"
#include "test_runner.h"
#include "Vector.h"
#include <vector>

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
int Hello::n = 0;*/

int main() {
	{
		TestRunner tr;
		tr.RunTest(unit_tests_vector, "base test");
		tr.RunTest(unit_size, "Size");
		tr.RunTest(unit_test_iterator, "iterator");
		tr.RunTest(unit_test_assign, "assign");
		tr.RunTest(unit_test_erase, "erase");
		tr.RunTest(unit_tests_push_back, "push_back");
		tr.RunTest(unit_tests_insert, "insert");
		tr.RunTest(unit_tests_pop, "pop");
		tr.RunTest(unit_tests_swap, "swap");
		tr.RunTest(unit_tests_cmp_oper, "cmp_oper");
		tr.RunTest(unit_tests_reverse_iterator, "reverse_iterator");
	}

	return 0;
}