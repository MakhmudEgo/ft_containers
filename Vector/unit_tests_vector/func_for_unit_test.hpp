//
// Created by Mahmud Jego on 5/8/21.
//

#pragma once

template<typename T>
std::ostream& PrintV(T& v, std::ostream& os) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i) {
			os << ' ';
		}
		os << "index - " << i << ": " << v[i];
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