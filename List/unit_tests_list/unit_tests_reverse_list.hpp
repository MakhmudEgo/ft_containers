//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"



void unit_tests_reverse_list() {
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
		sl.reverse();
		ml.reverse();
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
		sl.reverse();
		ml.reverse();
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

		slRes << "after: ";
		mlRes << "after: ";
		sl.reverse();
		ml.reverse();
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(2);
		ft::list<int> ml(2);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 10)
		slRes << "before: ";
		mlRes << "before: ";
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		slRes << "after: ";
		mlRes << "after: ";
		sl.reverse();
		ml.reverse();
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}


}
