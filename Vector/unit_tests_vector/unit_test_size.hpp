//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include "sstream"

#include "func_for_unit_test.hpp"

void unit_size() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		UNIT_SIZE_INIT_SS
		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(13);
		mv.reserve(13);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		sv.reserve(13);
		mv.reserve(13);

		sv.resize(13);
		mv.resize(13);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

/*		sv.resize(16, 1998);
		mv.resize(16, 1998);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);*/

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(13);
		mv.reserve(13);

		sv.resize(16, 1998);
		mv.resize(16, 1998);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}
	{
		std::vector<int> sv(4,4);
		ft::vector<int> mv(4,4);
		std::stringstream svRes;
		std::stringstream mvRes;

		sv.reserve(13);
		mv.reserve(13);

		sv.resize(16);
		mv.resize(16);
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}

	{
		std::vector<int> sv(4,4);
		ft::vector<int> mv(4,4);
		std::stringstream svRes;
		std::stringstream mvRes;

		UNIT_SIZE_INIT_SS
		sv.resize(10);
		mv.resize(10);
		UNIT_SIZE_INIT_SS
		InitVector(sv, 3, true);
		InitVector(mv, 3, true);
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str())
	}
}
