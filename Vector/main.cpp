//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

//#include "unit_tests_vector.hpp"
#include "unit_test_iterator.hpp"
#include "unit_test_size.hpp"
#include "test_runner.h"
#include <numeric>

int main() {
	{
		TestRunner tr;
//		tr.RunTest(unit_tests_vector, "base test");
//		tr.RunTest(unit_size, "Size");
		tr.RunTest(unit_test_iterator, "iterator");
	}
	return 0;
}