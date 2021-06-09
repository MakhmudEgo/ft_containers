//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"

void unit_tests_modifiers() {
	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		sl.push_back(24);
		ml.push_back(24);

		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(14);
		ft::list<int> ml(14);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		sl.push_back(24);
		ml.push_back(24);


		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(43);
		ft::list<int> ml(43);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)

		SIZE_LIST(sl, ml)
		sl.pop_front();
		ml.pop_front();
		SIZE_LIST(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(43);
		ft::list<int> ml(43);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)

		SIZE_LIST(sl, ml)
		sl.clear();
		slRes << "max_size: " << sl.max_size() << std::endl;
		ml.clear();
		mlRes << "max_size: " << ml.max_size() << std::endl;
		SIZE_LIST(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		SIZE_LIST(sl, ml)

		sl.push_back(2);
		ml.push_back(2);
		PRINT_L(sl, ml)

		sl.push_front(14);
		ml.push_front(14);
		PRINT_L(sl, ml)
		SIZE_LIST(sl, ml)

		sl.clear();
		ml.clear();
		PRINT_L(sl, ml)

		SIZE_LIST(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		SIZE_LIST(sl, ml)

		sl.push_back(2);
		ml.push_back(2);
		PRINT_L(sl, ml)

		sl.push_front(14);
		ml.push_front(14);
		PRINT_L(sl, ml)
		SIZE_LIST(sl, ml)

		slRes << "front: " << sl.front() << std::endl;
		mlRes << "front: " << ml.front() << std::endl;
		slRes << "back: " << sl.back() << std::endl;
		mlRes << "back: " << ml.back() << std::endl;

		sl.pop_front();
		sl.pop_front();
		ml.pop_front();
		ml.pop_front();

		SIZE_LIST(sl, ml)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}
}
