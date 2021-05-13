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

		svRes << "iter: " << sIt[0] << std::endl;
		mvRes << "iter: " << mIt[0] << std::endl;

		svRes << "iter: " << *(--sIt) << std::endl;
		mvRes << "iter: " << *(--mIt) << std::endl;
		sIt--; sIt--; sIt--;
		mIt--; mIt--; mIt--;

		svRes << "iter: " << sIt[2] << " " << sIt[12] << " " << sIt[-2] << std::endl;
		mvRes << "iter: " << mIt[2] << " " << mIt[12] << " " << mIt[-2] << std::endl;
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
	{
		std::vector<int> sv(150);
		ft::vector<int> mv(150);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		InitVector(sv, 23, true);
		InitVector(mv, 23, true);

		sIt = sIt + 4;
		mIt = mIt + 4;

		svRes << "iter: " << sIt[0] << std::endl;
		mvRes << "iter: " << mIt[0] << std::endl;

		svRes << "iter: " << *(--sIt) << std::endl;
		mvRes << "iter: " << *(--mIt) << std::endl;
		sIt--; sIt--; sIt--;
		mIt--; mIt--; mIt--;
		svRes << "iter: " << *sIt << std::endl;
		mvRes << "iter: " << *mIt << std::endl;

		sIt = sIt + 8;
		mIt = mIt + 8;
		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		svRes << "iter: " << sIt[2] << " " << sIt[12] << " " << sIt[-2] << std::endl;
		mvRes << "iter: " << mIt[2] << " " << mIt[12] << " " << mIt[-2] << std::endl;
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		sIt = sIt + 10;
		mIt = mIt + 10;

		svRes << "iter: " << *sIt++ << std::endl;
		mvRes << "iter: " << *mIt++ << std::endl;

		sIt = sIt - 5;
		mIt = mIt - 5;

		svRes << "iter: " << *sIt << std::endl;
		mvRes << "iter: " << *mIt << std::endl;
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();

		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		sIt += 10;
		mIt += 10;

		svRes << "iter: " << *sIt++ << std::endl;
		mvRes << "iter: " << *mIt++ << std::endl;

		sIt -= 5;
		mIt -= 5;

		svRes << "iter: " << *sIt << std::endl;
		mvRes << "iter: " << *mIt << std::endl;
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();
		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		std::vector<int>::iterator sIt1 = sIt + 5;
		ft::vector<int>::iterator mIt1 = mIt + 5;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		svRes << "<: " << (sIt < sIt1) << std::endl;
		mvRes << "<: " << (mIt < mIt1) << std::endl;
		svRes << ">: " << (sIt > sIt1) << std::endl;
		mvRes << ">: " << (mIt > mIt1) << std::endl;

		svRes << "<: " << (sIt < sIt) << std::endl;
		mvRes << "<: " << (mIt < mIt) << std::endl;
		svRes << ">: " << (sIt > sIt) << std::endl;
		mvRes << ">: " << (mIt > mIt) << std::endl;
		sIt++; sIt++; sIt++; sIt++; sIt++;
		mIt++; mIt++; mIt++; mIt++; mIt++;
		svRes << "<: " << (sIt <= sIt1) << std::endl;
		mvRes << "<: " << (mIt <= mIt1) << std::endl;
		svRes << ">: " << (sIt >= sIt1) << std::endl;
		mvRes << ">: " << (mIt >= mIt1) << std::endl;

		svRes << "<: " << (sIt <= sIt) << std::endl;
		mvRes << "<: " << (mIt <= mIt) << std::endl;
		svRes << ">: " << (sIt >= sIt) << std::endl;
		mvRes << ">: " << (mIt >= mIt) << std::endl;

		sIt[2] = 1000000;
		mIt[2] = 1000000;

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();
		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		std::vector<int>::iterator sIt1 = sIt + 5;
		ft::vector<int>::iterator mIt1 = mIt + 5;

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		svRes << "==: " << (sIt == sIt) << std::endl;
		mvRes << "==: " << (mIt == mIt) << std::endl;
		svRes << "==: " << (sIt == sIt) << std::endl;
		mvRes << "==: " << (mIt == mIt) << std::endl;

		svRes << "!=: " << (sIt != sIt) << std::endl;
		mvRes << "!=: " << (mIt != mIt) << std::endl;
		svRes << "!=: " << (sIt != sIt) << std::endl;
		mvRes << "!=: " << (mIt != mIt) << std::endl;
		sIt++; sIt++; sIt++; sIt++; sIt++;
		mIt++; mIt++; mIt++; mIt++; mIt++;

		sIt[2] = 1000000;
		mIt[2] = 1000000;
		svRes << "!=: " << (sIt != sIt1) << std::endl;
		mvRes << "!=: " << (mIt != mIt1) << std::endl;
		svRes << "!=: " << (sIt != sIt1) << std::endl;
		mvRes << "!=: " << (mIt != mIt1) << std::endl;

		svRes << "==: " << (sIt == sIt1) << std::endl;
		mvRes << "==: " << (mIt == mIt1) << std::endl;
		svRes << "==: " << (sIt == sIt1) << std::endl;
		mvRes << "==: " << (mIt == mIt1) << std::endl;

		sIt++; sIt++; sIt++; sIt++; sIt++;
		mIt++; mIt++; mIt++; mIt++; mIt++;

		svRes << "!=: " << (sIt != sIt1) << std::endl;
		mvRes << "!=: " << (mIt != mIt1) << std::endl;
		svRes << "!=: " << (sIt != sIt1) << std::endl;
		mvRes << "!=: " << (mIt != mIt1) << std::endl;

		svRes << "==: " << (sIt == sIt1) << std::endl;
		mvRes << "==: " << (mIt == mIt1) << std::endl;
		svRes << "==: " << (sIt == sIt1) << std::endl;
		mvRes << "==: " << (mIt == mIt1) << std::endl;


		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		std::vector<int>::iterator sIt = sv.begin();
		ft::vector<int>::iterator mIt = mv.begin();
		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		std::vector<int>::iterator sIt1 = sv.begin();
		ft::vector<int>::iterator mIt1 = mv.begin();

		svRes << std::boolalpha;
		mvRes << std::boolalpha;

		svRes << *sIt << std::endl;
		mvRes << *mIt << std::endl;
		svRes << "==:d " << (++sIt == sIt) << std::endl;
		mvRes << "==:d " << (++mIt == mIt) << std::endl;

		svRes << "==:d " << (++sIt == ++sIt) << std::endl;
		mvRes << "==:d " << (++mIt == ++mIt) << std::endl;
		svRes << "==:d " << (++sIt == ++sIt) << std::endl;
		mvRes << "==:d " << (++mIt == ++mIt) << std::endl;


		svRes << "==:d " << *sIt << std::endl;
		mvRes << "==:d " << *mIt << std::endl;

		svRes << "==:d " << (++sIt == ++sIt1) << std::endl;
		mvRes << "==:d " << (++mIt == ++mIt1) << std::endl;

		++sIt;
		++mIt;

		std::cout << "value: " << *sIt << std::endl;
		std::cout << "value: " << *mIt << std::endl;


		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(123);
		ft::vector<int> mv(123);

		std::stringstream svRes;
		std::stringstream mvRes;
		__unused std::vector<int>::iterator sIt = sv.begin();
		__unused ft::vector<int>::iterator mIt = mv.begin();
		InitVector(sv, 11, true);
		InitVector(mv, 11, true);

		std::vector<int>::const_iterator sIt1 = sv.begin();
		ft::vector<int>::const_iterator mIt1 = mv.begin();
		sIt1++;
		mIt1++;

		svRes << "iter: " << *sIt1++ << std::endl;
		mvRes << "iter: " << *mIt1++ << std::endl;

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}

