//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_resize_list() {
	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		sl.push_back(24);
		sl.push_back(41);
		sl.push_back(34);
		ml.push_back(24);
		ml.push_back(41);
		ml.push_back(34);
		SIZE_LIST
		PRINT_L(sl, ml)

		sl.resize(1);
		ml.resize(1);
		SIZE_LIST
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		sl.push_back(24);
		sl.push_back(41);
		sl.push_back(34);
		ml.push_back(24);
		ml.push_back(41);
		ml.push_back(34);
		SIZE_LIST
		PRINT_L(sl, ml)

		sl.resize(1);
		ml.resize(1);
		SIZE_LIST
		PRINT_L(sl, ml)

		sl.resize(17);
		ml.resize(17);
		SIZE_LIST
		PRINT_L(sl, ml)

		sl.resize(0);
		ml.resize(0);
		SIZE_LIST
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}


	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		sl.resize(0);
		ml.resize(0);
		SIZE_LIST
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

}
