//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

static bool comp_unique(int a, int b) { return (a == b); }

void unit_tests_unique_list() {
	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique();
		ml.unique();
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		sl.push_back(19);
		sl.push_back(19);
		ml.push_back(19);
		ml.push_back(19);
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique();
		ml.unique();
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique(comp_unique);
		ml.unique(comp_unique);
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		sl.push_back(19);
		sl.push_back(19);
		ml.push_back(19);
		ml.push_back(19);
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique(comp_unique);
		ml.unique(comp_unique);
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
		sl.push_back(19);
		sl.push_back(19);
		ml.push_back(19);
		ml.push_back(19);
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique(comp_unique);
		ml.unique(comp_unique);
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
		sl.push_back(19);
		sl.push_back(19);
		ml.push_back(19);
		ml.push_back(19);
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique();
		ml.unique();
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

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique();
		ml.unique();
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

		slRes << "after: ";
		mlRes << "after: ";
		sl.unique(comp_unique);
		ml.unique(comp_unique);
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

}
