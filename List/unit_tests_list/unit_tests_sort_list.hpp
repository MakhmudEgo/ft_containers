//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

static bool comp_sort1(int a, int b) { return (a > b); }
static bool comp_sort2(int a, int b) { return (a < b); }


void unit_tests_sort_list() {
	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort();
		ml.sort();
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort();
		ml.sort();
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.push_back(4);
		ml.push_back(4);
		sl.sort();
		ml.sort();
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		srand(time(0x0));
		for (int i = 0; i < 10; ++i) {
			int res = rand() % 100;
			sl.push_back(res);
			ml.push_back(res);
		}
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort();
		ml.sort();
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort1);
		ml.sort(comp_sort1);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort1);
		ml.sort(comp_sort1);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.push_back(4);
		ml.push_back(4);
		sl.sort(comp_sort1);
		ml.sort(comp_sort1);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		srand(time(0x0));
		for (int i = 0; i < 10; ++i) {
			int res = rand() % 100;
			sl.push_back(res);
			ml.push_back(res);
		}
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort1);
		ml.sort(comp_sort1);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort2);
		ml.sort(comp_sort2);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort2);
		ml.sort(comp_sort2);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.push_back(4);
		ml.push_back(4);
		sl.sort(comp_sort2);
		ml.sort(comp_sort2);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		srand(time(0x0));
		for (int i = 0; i < 10; ++i) {
			int res = rand() % 100;
			sl.push_back(res);
			ml.push_back(res);
		}
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		sl.sort(comp_sort2);
		ml.sort(comp_sort2);
		slRes << "after: ";
		mlRes << "after: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}
}
