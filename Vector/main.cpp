//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

//#include "func_for_unit_test.hpp"
//#include "unit_tests_vector.hpp"
//#include "unit_test_iterator.hpp"
//#include "unit_test_size.hpp"
//#include "unit_test_assign.hpp"
#include "unit_test_erase.hpp"
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
	}
	std::vector<int > v;
	ft::vector<int > v1;
	std::cout << v.max_size() << std::endl;
	std::cout << v1.max_size() << std::endl;


	return 0;
}