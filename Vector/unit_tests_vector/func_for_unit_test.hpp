//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

#include <iostream>

#define UNIT_SIZE_INIT_SS(x, y) \
	svRes << "size: " << x.size() << std::endl \
	<< "capacity: " << x.capacity() << std::endl; \
	mvRes << "size: " << y.size() << std::endl \
	<< "capacity: " << y.capacity() << std::endl;

#define PRINT_V(x, y) \
	PrintV(x, svRes); \
	PrintV(y, mvRes);

#define SIZE_PRINT_V(x, y) \
	UNIT_SIZE_INIT_SS(x, y) \
	PRINT_V(x, y)

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