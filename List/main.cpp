//
// Created by Mahmud Jego on 5/15/21.
//

#include <list>
#include "List.h"
#include <numeric>
#include "unit_tests_modifers.hpp"
#include "unit_tests_insert_and_erase_list.hpp"
#include "unit_tests_resize_list.hpp"
#include "unit_tests_merge_list.hpp"
#include "unit_tests_iter.hpp"
#include "test_runner.h"
#include "func_utils.hpp"

int main() {
	{
		TestRunner tr;
		tr.RunTest(unit_tests_modifers, "unit_tests_modifers");
		tr.RunTest(unit_tests_iter, "unit_tests_iter");
		tr.RunTest(unit_tests_insert_list, "insert");
		tr.RunTest(unit_tests_resize_list, "resize");
		tr.RunTest(unit_tests_merge_list, "unit_tests_merge_list");
	}
}
