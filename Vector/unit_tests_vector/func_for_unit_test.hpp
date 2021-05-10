//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

#include <iostream>

#define UNIT_SIZE_INIT_SS \
	svRes << "size: " << sv.size() << std::endl \
	<< "capacity: " << sv.capacity() << std::endl; \
	mvRes << "size: " << mv.size() << std::endl \
	<< "capacity: " << mv.capacity() << std::endl;

template<typename T>
std::ostream& PrintV(T& v, std::ostream& os) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i) {
			os << "; ";
		}
		os << "v[" << i << "] = " << v[i];
	}
	os << std::endl;
	return os;
}

template<typename T, typename U>
void InitVector(T& v, U value, const bool dyn) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = dyn ? value++ : value;
	}
}