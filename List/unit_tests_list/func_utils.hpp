//
// Created by Mahmud Jego on 5/28/21.
//

#pragma once

template<typename T>
std::ostream& PrintL(T& l, std::ostream& os = std::cout) {
	typename T::iterator it = l.begin();
	for (size_t i = 0; it != l.end() ; ++it, ++i) {
		if (i) {
			os << "; ";
		}
		os << "l[" << i << "] = " << *it;
	}
	os << std::endl;
	return os;
}

#define PRINT_L(x, y) \
	PrintL(x, slRes); \
	PrintL(y, mlRes);



template<typename T, typename U>
void InitList(T& l, U value, const bool dyn = true) {
	typename T::iterator it = l.begin();
	for (; it != l.end(); ++it) {
		*it = dyn ? value++ : value;
	}
}

#define INIT_LIST(x, y, z) \
	InitList(x, z); \
	InitList(y, z);

#define SIZE_LIST(x, y) \
	slRes << "size " << x.size() << std::endl; \
	mlRes << "size " << y.size() << std::endl;