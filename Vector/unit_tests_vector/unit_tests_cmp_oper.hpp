//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include "sstream"
#include "test_runner.h"
#include "func_for_unit_test.hpp"
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
	CMP(x1, x2, svRes) \
	CMP(y1, y2, mvRes)

void unit_tests_cmp_oper() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		CMP_ALL(sv, sv, mv, mv)

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(1, 4), sv1(4, 4);
		ft::vector<int> mv(1, 4), mv1(4, 4);
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		CMP_ALL(sv, sv1, mv, mv1)
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(1, 40), sv1(4, 14);
		ft::vector<int> mv(1, 40), mv1(4, 14);
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		CMP_ALL(sv, sv1, mv, mv1)
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(1, 40), sv1(4, 44);
		ft::vector<int> mv(1, 40), mv1(4, 44);
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		CMP_ALL(sv, sv1, mv, mv1)
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(10, 40), sv1(4, 44);
		ft::vector<int> mv(10, 40), mv1(4, 44);
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		CMP_ALL(sv, sv1, mv, mv1)
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(10, 40), sv1(4, 44);
		ft::vector<int> mv(10, 40), mv1(4, 44);
		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		sv.insert(sv.begin(), 55);
		mv.insert(mv.begin(), 55);
		SIZE_PRINT_V(sv, mv);
		SIZE_PRINT_V(sv1, mv1);
		CMP_ALL(sv, sv1, mv, mv1)
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}
