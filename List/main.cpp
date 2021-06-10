//
// Created by Mahmud Jego on 5/15/21.
//

#include <list>
#include "List.h"
#include <numeric>
#include "unit_tests_modifiers.hpp"
#include "unit_tests_insert_and_erase_list.hpp"
#include "unit_tests_list_cmp_oper.hpp"
#include "unit_tests_reverse_list.hpp"
#include "unit_tests_splice_list.hpp"
#include "unit_tests_resize_list.hpp"
#include "unit_tests_remove_list.hpp"
#include "unit_tests_unique_list.hpp"
#include "unit_tests_merge_list.hpp"
#include "unit_tests_swap_list.hpp"
#include "unit_tests_sort_list.hpp"
#include "unit_tests_iter.hpp"
#include "test_runner.h"
#include "func_utils.hpp"

int main() {
	{
		TestRunner tr;
		tr.RunTest(unit_tests_modifiers, "unit_tests_modifiers");
		tr.RunTest(unit_tests_iter, "unit_tests_iter");
		tr.RunTest(unit_tests_insert_list, "insert");
		tr.RunTest(unit_tests_resize_list, "resize");
		tr.RunTest(unit_tests_merge_list, "unit_tests_merge_list");
		tr.RunTest(unit_tests_swap_list, "unit_tests_swap_list");
		tr.RunTest(unit_tests_splice_list, "unit_tests_splice_list");
		tr.RunTest(unit_tests_remove_list, "unit_tests_remove_list");
		tr.RunTest(unit_tests_reverse_list, "unit_tests_reverse_list");
		tr.RunTest(unit_tests_unique_list, "unit_tests_unique_list");
		tr.RunTest(unit_tests_sort_list, "unit_tests_sort_list");
		tr.RunTest(unit_tests_list_cmp_oper, "unit_tests_list_cmp_oper");
	}
}
