//
// Created by Mahmud Jego on 5/6/21.
//

//#include "overloadNewAndDelete.h"

//#include "unit_tests_vector.hpp"
#include "unit_test_iterator.hpp"
#include "test_runner.h"

int main() {
	{
		TestRunner tr;
//		tr.RunTest(unit_tests_vector, "base test");
//		tr.RunTest(unit_size, "Size");
		tr.RunTest(unit_test_iterator, "iterator");
	}
	return 0;

}