//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

//#include "unit_tests_vector.hpp"
#include "unit_test_iterator.hpp"
//#include "unit_test_size.hpp"
#include "Vector.h"
#include "func_for_unit_test.hpp"
#include "test_runner.h"
#include <numeric>
#include <vector>

int main() {
	{
		TestRunner tr;
//		tr.RunTest(unit_tests_vector, "base test");
//		tr.RunTest(unit_size, "Size");
		tr.RunTest(unit_test_iterator, "iterator");
	}

	std::vector<int> v(10);
	ft::vector<int> mv(10, 1);
	iota(v.begin(), v.end(), 1);
	InitVector(mv, 1, true);
	__unused std::vector<int>::iterator it = v.begin();
	__unused std::vector<int>::iterator it1 = v.begin();
	__unused ft::vector<int>::iterator mit = v.begin();
	__unused ft::vector<int>::iterator mit1 = v.begin();

	std::cout << boolalpha;

	std::cout << 2 << std::endl;
	std::cout << (++it == it) << std::endl;
	std::cout << (++mit == mit) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *mit << std::endl;

	return 0;
}