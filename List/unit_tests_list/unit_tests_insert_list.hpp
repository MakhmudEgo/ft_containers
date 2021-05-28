//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_insert_list() {
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

		std::list<int> sl1;
		ft::list<int> ml1;

		std::cout << *sl.insert(sl.begin(), 0) << std::endl;
		std::cout << *ml.insert(ml.begin(), 0) << std::endl;
		std::cout << *sl.insert(sl.begin(), 13) << std::endl;
		std::cout << *ml.insert(ml.begin(), 13) << std::endl;

		PRINT_L(sl, ml)
//		PRINT_L(sl1, ml1) // todo _+_+_

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		std::cout << *sl.insert(sl.begin(), 0) << std::endl;
		std::cout << *ml.insert(ml.begin(), 0) << std::endl;
		std::cout << *sl.insert(sl.begin(), 13) << std::endl;
		std::cout << *ml.insert(ml.begin(), 13) << std::endl;

		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}
}
