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

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;

		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.insert(sl.end(), 0) << std::endl;
		mlRes << *ml.insert(ml.end(), 0) << std::endl;
		slRes << *sl.insert(sl.end(), 13) << std::endl;
		mlRes << *ml.insert(ml.end(), 13) << std::endl;
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.insert(sl.end(), 0) << std::endl;
		mlRes << *ml.insert(ml.end(), 0) << std::endl;
		slRes << *sl.insert(sl.end(), 13) << std::endl;
		mlRes << *ml.insert(ml.end(), 13) << std::endl;
		PRINT_L(sl, ml)

		std::list<int> sl1;
		ft::list<int> ml1;

		sl1.insert(sl1.begin(), 4, 1);
		ml1.insert(ml1.begin(), 4, 1);
		PRINT_L(sl1, ml1)


		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.insert(sl.end(), 0) << std::endl;
		mlRes << *ml.insert(ml.end(), 0) << std::endl;
		slRes << *sl.insert(sl.end(), 13) << std::endl;
		mlRes << *ml.insert(ml.end(), 13) << std::endl;
		PRINT_L(sl, ml)

		std::list<int> sl1;
		ft::list<int> ml1;

		sl1.push_back(13);
		ml1.push_back(13);
		sl1.insert(sl1.begin(), 4, 1);
		ml1.insert(ml1.begin(), 4, 1);
		PRINT_L(sl1, ml1)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.insert(sl.end(), 0) << std::endl;
		mlRes << *ml.insert(ml.end(), 0) << std::endl;
		slRes << *sl.insert(sl.end(), 13) << std::endl;
		mlRes << *ml.insert(ml.end(), 13) << std::endl;
		PRINT_L(sl, ml)

		std::list<int> sl1;
		ft::list<int> ml1;

		sl1.push_back(13);
		ml1.push_back(13);
		sl1.insert(sl1.begin(), 4, 1);
		ml1.insert(ml1.begin(), 4, 1);
		PRINT_L(sl1, ml1)

		std::list<int> sl2;
		ft::list<int> ml2;

		sl2.insert(sl2.begin(), sl1.begin(), sl1.end());
		ml2.insert(ml2.begin(), ml1.begin(), ml1.end());
		PRINT_L(sl2, ml2)

		sl2.insert(sl2.end(), sl1.begin(), sl1.end());
		ml2.insert(ml2.end(), ml1.begin(), ml1.end());
		PRINT_L(sl2, ml2)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << *sl.insert(sl.begin(), 0) << std::endl;
		mlRes << *ml.insert(ml.begin(), 0) << std::endl;
		slRes << *sl.insert(sl.begin(), 13) << std::endl;
		mlRes << *ml.insert(ml.begin(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.insert(sl.end(), 0) << std::endl;
		mlRes << *ml.insert(ml.end(), 0) << std::endl;
		slRes << *sl.insert(sl.end(), 13) << std::endl;
		mlRes << *ml.insert(ml.end(), 13) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.erase(sl.begin()) << std::endl;
		mlRes << *ml.erase(ml.begin()) << std::endl;
		PRINT_L(sl, ml)

		slRes << *sl.erase(++sl.begin()) << std::endl;
		mlRes << *ml.erase(++ml.begin()) << std::endl;
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(7);
		ft::list<int> ml(7);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		PRINT_L(sl, ml)

		sl.erase(sl.begin(), sl.end());
		ml.erase(ml.begin(), ml.end());
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(7);
		ft::list<int> ml(7);
		std::stringstream slRes;
		std::stringstream mlRes;

		INIT_LIST(sl, ml, 1)
		PRINT_L(sl, ml)

		sl.erase(++(++sl.begin()), --sl.end());
		ml.erase(++(++ml.begin()), --ml.end());
		PRINT_L(sl, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

}
