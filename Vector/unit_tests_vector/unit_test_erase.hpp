//
// Created by Mahmud Jego on 5/11/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include <sstream>
#include "test_runner.h"
#include "func_for_unit_test.hpp"

void unit_test_erase() {
/*	{
		std::vector<int> sv(2);
		ft::vector<int> mv(2);

		std::stringstream svRes;
		std::stringstream mvRes;

		InitVector(sv, 1, true);
		InitVector(mv, 1, true);

		sv.erase(sv.begin());
		mv.erase(mv.begin());
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}*/

	{
		std::vector<int> sv(27);
		ft::vector<int> mv(27);

		std::stringstream svRes;
		std::stringstream mvRes;

		InitVector(sv, 0, true);
		InitVector(mv, 0, true);
		UNIT_SIZE_INIT_SS
		sv.erase(sv.begin() + 5);
		mv.erase(mv.begin() + 5);
		UNIT_SIZE_INIT_SS
		std::cout << *(sv.end() + 1) << std::endl;
//		sv.erase(sv.end());
//		mv.erase(mv.end());
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(10);
		ft::vector<int> mv(10);

		std::stringstream svRes;
		std::stringstream mvRes;

		UNIT_SIZE_INIT_SS

		InitVector(sv, 0, true);
		InitVector(mv, 0, true);
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		sv.erase(sv.begin());
		mv.erase(mv.begin());

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		svRes << "return value erase: " << *sv.erase(sv.begin() + 6) << std::endl;
		mvRes << "return value erase: " << *mv.erase(mv.begin() + 6) << std::endl;
		UNIT_SIZE_INIT_SS
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(10);
		ft::vector<int> mv(10);

		std::stringstream svRes;
		std::stringstream mvRes;

		UNIT_SIZE_INIT_SS

		InitVector(sv, 0, true);
		InitVector(mv, 0, true);
		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		sv.erase(sv.begin());
		mv.erase(mv.begin());

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		svRes << "return value erase: " << *sv.erase(sv.begin() + 6) << std::endl;
		mvRes << "return value erase: " << *mv.erase(mv.begin() + 6) << std::endl;
		UNIT_SIZE_INIT_SS

		svRes << "return value erase: " << *sv.erase(sv.begin()+2, sv.begin()+5) << std::endl;
		mvRes << "return value erase: " << *mv.erase(mv.begin()+2, mv.begin()+5) << std::endl;
		UNIT_SIZE_INIT_SS

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv;
		ft::vector<int> mv;

		std::stringstream svRes;
		std::stringstream mvRes;

//		sv.erase(sv.begin());
//		mv.erase(mv.begin());
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}
