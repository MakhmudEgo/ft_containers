//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include "sstream"
#include "test_runner.h"
#include "func_for_unit_test.hpp"

void unit_tests_pop() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

//		sv.pop_back();
//		mv.pop_back();

		sv.resize(10);
		mv.resize(10);

		InitVector(sv, 1, true);
		InitVector(mv, 1, true);

		sv.pop_back();
		mv.pop_back();
		SIZE_PRINT_V(sv, mv)

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
	{
		std::vector<int> sv(1, 1);
		ft::vector<int> mv(1, 1);
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.pop_back();
		mv.pop_back();
		SIZE_PRINT_V(sv, mv)

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}
