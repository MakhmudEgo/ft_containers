//
// Created by Mahmud Jego on 5/7/21.
//
#pragma once

#include <vector>
#include "test_runner.h"
#include <sstream>
#include <iostream>


#define BaseTest(field) \
{ \
	std::stringstream ss; \
	field::vector<int> vector(4, 4); \
	for (int i = 1; i < 5; ++i) { \
		vector[i - 1] = i; \
	} \
	field::vector<int>::iterator it = vector.begin(); \
	*it++ = 44; \
	ss << *it++ << std::endl; \
	ss << vector[0] << std::endl; \
	ss << vector[1] << std::endl; \
	ss << vector[2] << std::endl; \
	ss << vector[3] << std::endl; \
	ss << *it << std::endl; \
	ss << "-------------" << std::endl; \
	ss << vector[0] << std::endl; \
	ss << vector[1] << std::endl; \
	ss << vector[2] << std::endl; \
	ss << vector[3] << std::endl; \
	return ss.str(); \
}

struct names {
	int ft;
	int std;
};

std::string test_iter(const std::string& lib) {
	__unused names t;

	if (lib == "ft") {
		BaseTest(ft);
	}
	BaseTest(std);
}

template<typename T>
std::string base_tests(T& v) {
	std::stringstream ss;
	ss << v.size();
	ss << v.capacity();
	return ss.str();
}

void unit_tests_vector() {
	{
		std::string x = test_iter("ft");
		std::string y = test_iter("std");
		ASSERT_EQUAL(x, y);
	}
	{
		std::vector<int> stdV(5, 5);
		ft::vector<int> ftV(5, 5);
		std::string x = base_tests(stdV);
		std::string y = base_tests(ftV);
		ASSERT_EQUAL(x, y);
	}
}