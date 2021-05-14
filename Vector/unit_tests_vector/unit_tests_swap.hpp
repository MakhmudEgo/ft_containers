//
// Created by Mahmud Jego on 5/12/21.
//

#pragma once
#include <iostream>
#include <ostream>

#include <vector>
#include "Vector.h"
#include "sstream"
#include "test_runner.h"
#include "func_for_unit_test.hpp"

void unit_tests_swap() {
	{
		std::vector<int> sv(4, 4), sv1(13, 13);
		std::vector<int> mv(4, 4), mv1(13, 13);
		std::stringstream svRes;
		std::stringstream mvRes;

		SIZE_PRINT_V(sv, mv)
		SIZE_PRINT_V(sv1, mv1)

		sv.swap(sv1);
		mv.swap(mv1);

		SIZE_PRINT_V(sv, mv)
		SIZE_PRINT_V(sv1, mv1)

		ASSERT_EQUAL(svRes.str(), mvRes.str());
	}
}
