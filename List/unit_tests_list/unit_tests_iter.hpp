//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_iter() {
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

		std::list<int> sl1(sl.begin(), sl.end());
		ft::list<int> ml1(ml.begin(), ml.end());

		PRINT_L(sl, ml)
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}
}
