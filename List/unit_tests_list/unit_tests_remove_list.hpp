//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"


bool pred(const int &value) {
	return value > 1;
}

void unit_tests_remove_list() {
	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove(0);
		ml.remove(0);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1);
		ft::list<int> ml(1);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove(1);
		ml.remove(1);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove(1);
		ml.remove(1);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(12);
		ft::list<int> ml(12);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		for (int i = 0; i < 10; ++i) {
			sl.push_front(2);
			ml.push_front(2);
		}
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove(1);
		ml.remove(1);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(12);
		ft::list<int> ml(12);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		for (int i = 0; i < 5; ++i) {
			sl.push_front(2);
			sl.push_back(2);
			ml.push_front(2);
			ml.push_back(2);
		}
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove(2);
		ml.remove(2);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(12);
		ft::list<int> ml(12);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		for (int i = 0; i < 5; ++i) {
			sl.push_front(2);
			sl.push_back(2);
			ml.push_front(2);
			ml.push_back(2);
		}
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove_if(pred);
		ml.remove_if(pred);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		sl.remove_if(pred);
		ml.remove_if(pred);

		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}


}
