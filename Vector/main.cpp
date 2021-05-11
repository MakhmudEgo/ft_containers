//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

//#include "func_for_unit_test.hpp"
//#include "unit_tests_vector.hpp"
//#include "unit_test_iterator.hpp"
//#include "unit_test_size.hpp"
//#include "unit_test_assign.hpp"
//#include "unit_test_erase.hpp"
#include "unit_tests_push_back.hpp"
#include "Vector.h"
#include "test_runner.h"
#include <numeric>
#include <vector>

int main() {
	{
		TestRunner tr;
//		tr.RunTest(unit_tests_vector, "base test");
//		tr.RunTest(unit_size, "Size");
//		tr.RunTest(unit_test_iterator, "iterator");
//		tr.RunTest(unit_test_assign, "assign");
//		tr.RunTest(unit_test_erase, "erase");
//		tr.RunTest(unit_tests_push_back, "push_back");
	}

	std::vector<int> i(100, 1);
	std::vector<int> v5(5, 5);

	std::cout << "sz: " << v5.size() << std::endl;
	std::cout << "cp: " << v5.capacity() << std::endl;

	v5 = i;
//	PrintV(v5, std::cout);
	std::cout << "after" << std::endl;
	std::cout << "sz: " << v5.size() << std::endl;
	std::cout << "cp: " << v5.capacity() << std::endl;
	return 0;
}