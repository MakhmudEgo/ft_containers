//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

#include <vector>
#include "Vector.h"
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

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}

