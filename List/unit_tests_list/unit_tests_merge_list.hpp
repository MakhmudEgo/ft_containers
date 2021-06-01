//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_merge_list() {
	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)


		std::list<int> sl1(4);
		ft::list<int> ml1(4);
		INIT_LIST(sl1, ml1, 2)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl1, ml1)

		sl.merge(sl1);
		ml.merge(ml1);
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 70)
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)


		std::list<int> sl1(4);
		ft::list<int> ml1(4);
		INIT_LIST(sl1, ml1, 2)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl1, ml1)

		sl.merge(sl1);
		ml.merge(ml1);
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10);
		ft::list<int> ml(10);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 70)
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)


		std::list<int> sl1;
		ft::list<int> ml1;
		INIT_LIST(sl1, ml1, 2)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl1, ml1)

		sl.merge(sl1);
		ml.merge(ml1);
		SIZE_LIST(sl, ml)
		SIZE_LIST(sl1, ml1)
		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

}
