//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <list>
#include "List.h"
#include "sstream"
#include "test_runner.h"
#include "func_utils.hpp"
#include <iostream>

#define CMP_N(cmp, x, y, out) \
	out << "\""#cmp"\": " << (x cmp y) << std::endl;

#define CMP(x, y, out) \
	CMP_N(==, x, y, out) \
	CMP_N(>=, x, y, out) \
	CMP_N(<=, x, y, out) \
	CMP_N(!=, x, y, out) \
	CMP_N(<, x, y, out) \
	CMP_N(>, x, y, out)

#define CMP_ALL(x1, x2, y1, y2) \
	CMP(x1, x2, slRes) \
	CMP(y1, y2, mlRes)

void unit_tests_list_cmp_oper() {
	{
		std::list<int> sl;
		ft::list<int> ml;
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		CMP_ALL(sl, sl, ml, ml)

		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1, 4), sl1(4, 4);
		ft::list<int> ml(1, 4), ml1(4, 4);
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		CMP_ALL(sl, sl1, ml, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1, 40), sl1(4, 14);
		ft::list<int> ml(1, 40), ml1(4, 14);
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		CMP_ALL(sl, sl1, ml, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(1, 40), sl1(4, 44);
		ft::list<int> ml(1, 40), ml1(4, 44);
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		CMP_ALL(sl, sl1, ml, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10, 40), sl1(4, 44);
		ft::list<int> ml(10, 40), ml1(4, 44);
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		CMP_ALL(sl, sl1, ml, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}

	{
		std::list<int> sl(10, 40), sl1(4, 44);
		ft::list<int> ml(10, 40), ml1(4, 44);
		std::stringstream slRes;
		std::stringstream mlRes;

		slRes << std::boolalpha;
		mlRes << std::boolalpha;

		sl.insert(sl.begin(), 55);
		ml.insert(ml.begin(), 55);
		SIZE_LIST(sl, ml)
		PRINT_L(sl, ml)
		SIZE_LIST(sl1, ml1);
		PRINT_L(sl1, ml1);
		CMP_ALL(sl, sl1, ml, ml1)
		ASSERT_EQUAL(slRes.str(), mlRes.str());
	}
}
