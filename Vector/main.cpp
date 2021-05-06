//
// Created by Mahmud Jego on 5/6/21.
//

#include <iostream>
#include "Vector.h"
#include <vector>
#include "overloadNewAndDelete.h"

int main() {
	ft::vector<int> hello(5, 1234);
//	hello.clear();
	hello.resize(10, 1);
	hello.resize(3);
	hello.resize(10, 12);
	hello.reserve(1);
//	hello.reserve(15);
	std::cout << hello.size() << std::endl;
	std::cout << hello.capacity() << std::endl;
	for (size_t i = 0; i < hello.size(); ++i) {
		std::cout << hello[i] << ' ';
	}
//	std::allocator<int> al;
//	al.()

	ft::vector<bool> gg;

	gg.hello();
	return 0;

}