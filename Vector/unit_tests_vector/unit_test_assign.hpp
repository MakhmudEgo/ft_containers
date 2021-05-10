//
// Created by Mahmud Jego on 5/10/21.
//

#pragma once

#include <vector>
#include "Vector.h"
#include "sstream"
#include "func_for_unit_test.hpp"
#include "test_runner.h"

void unit_test_assign() {
	{
		std::vector<int> sv;
		ft::vector<int> mv;

		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << "size: " << sv.size() << std::endl;
		mvRes << "size: " << mv.size() << std::endl;
		svRes << "capacity: " << sv.capacity() << std::endl;
		mvRes << "capacity: " << mv.capacity() << std::endl;

		sv.assign(4, 13);
		mv.assign(4, 13);

		svRes << "size: " << sv.size() << std::endl;
		mvRes << "size: " << mv.size() << std::endl;
		svRes << "capacity: " << sv.capacity() << std::endl;
		mvRes << "capacity: " << mv.capacity() << std::endl;

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(13);
		ft::vector<int> mv(13);

		std::stringstream svRes;
		std::stringstream mvRes;

		svRes << "size: " << sv.size() << std::endl;
		mvRes << "size: " << mv.size() << std::endl;
		svRes << "capacity: " << sv.capacity() << std::endl;
		mvRes << "capacity: " << mv.capacity() << std::endl;

		sv.assign(4, 13);
		mv.assign(4, 13);

		svRes << "size: " << sv.size() << std::endl;
		mvRes << "size: " << mv.size() << std::endl;
		svRes << "capacity: " << sv.capacity() << std::endl;
		mvRes << "capacity: " << mv.capacity() << std::endl;

		PrintV(sv, svRes);
		PrintV(mv, mvRes);

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}

	{
		std::vector<int> sv(13);
		ft::vector<int> mv(13);

		std::stringstream svRes;
		std::stringstream mvRes;
		UNIT_SIZE_INIT_SS

		sv.resize(6, 12);
		mv.resize(6, 12);
		UNIT_SIZE_INIT_SS

		sv.assign(2, 13);
		mv.assign(2, 13);

		UNIT_SIZE_INIT_SS

		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		sv.assign(0,0);
		mv.assign(0,0);

		PrintV(sv, svRes);
		PrintV(mv, mvRes);
		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}