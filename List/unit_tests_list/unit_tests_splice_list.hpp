//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_splice_list() {
	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 17)
		SIZE_LIST(sl, ml)
		slRes << "before l: ";
		mlRes << "before l: ";
		PRINT_L(sl, ml)


		std::list<int> sl1(4);
		ft::list<int> ml1(4);
		INIT_LIST(sl1, ml1, 2)
		slRes << "before l1: ";
		mlRes << "before l1: ";
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl1, ml1)
		sl.splice(sl.begin(), sl1);
		ml.splice(ml.begin(), ml1);
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		slRes << "after l: ";
		mlRes << "after l: ";
		PRINT_L(sl, ml)
		slRes << "after l1: ";
		mlRes << "after l1: ";
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		std::list<int> sl1(4);
		ft::list<int> ml1(4);

		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		sl.splice(sl.begin(), sl1, sl1.begin());
		ml.splice(ml.begin(), ml1, ml1.begin());

		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		std::list<int> sl1(4);
		ft::list<int> ml1(4);

		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		sl.splice(sl.begin(), sl1, sl1.begin());
		ml.splice(ml.begin(), ml1, ml1.begin());

		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}


}
