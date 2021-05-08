//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include <sstream>
#include "test_runner.h"
#include "func_for_unit_test.hpp"

void unit_test_iterator() {
	{
		std::vector<int> sv(4, 4);
		ft::vector<int> mv(4, 4);

		std::stringstream svRes;
		std::stringstream mvRes;
		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		svRes << *sIt << std::endl;
		mvRes << *mIt << std::endl;
/*		svRes << *sIt++ << std::endl;
		mvRes << *mIt++ << std::endl;*/

		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
	{
		std::vector<int> sv(15);
		ft::vector<int> mv(15);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		svRes << *sIt << std::endl;
		mvRes << *mIt << std::endl;
		svRes << *sIt++ << std::endl;
		mvRes << *mIt++ << std::endl;

		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		++sIt;
		++mIt;
		++sIt;
		++mIt;
		svRes << *sIt << std::endl;
		mvRes << *mIt << std::endl;

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(15);
		ft::vector<int> mv(15);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		sIt++; sIt++; sIt++; sIt++; sIt++; sIt++;
		mIt++; mIt++; mIt++; mIt++; mIt++; mIt++;

		svRes << "iter: " << *sIt << std::endl;
		mvRes << "iter: " << *mIt << std::endl;

		svRes << "iter: " << *(--sIt) << std::endl;
		mvRes << "iter: " << *(--mIt) << std::endl;
		sIt--; sIt--; sIt--;
		mIt--; mIt--; mIt--;

		svRes << "iter: " << *sIt << std::endl;
		mvRes << "iter: " << *mIt << std::endl;
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}

