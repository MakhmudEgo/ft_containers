//
// Created by Mahmud Jego on 5/11/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include <sstream>
#include "test_runner.h"
#include "func_for_unit_test.hpp"

void unit_tests_push_back() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		UNIT_SIZE_INIT_SS
		sv.push_back(3);
		mv.push_back(3);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		for (int i = 0; i < 150; ++i) {
			sv.push_back(i);
			mv.push_back(i);
			UNIT_SIZE_INIT_SS;
		}

		sv.resize(12);
		mv.resize(12);
		UNIT_SIZE_INIT_SS

		sv.resize(257);
		mv.resize(257);
		UNIT_SIZE_INIT_SS

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.push_back(7);
		mv.push_back(7);
		sv.push_back(4);
		mv.push_back(4);
		sv.push_back(0);
		mv.push_back(0);
		sv.push_back(10);
		mv.push_back(10);

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}
}