//
// Created by Mahmud Jego on 5/6/21.
//

#include <iostream>
#include "Vector.h"
#include <algorithm>
#include <numeric>
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

	ft::vector<int>::const_iterator const_it(hello.begin());
	ft::vector<int>::iterator it(hello.begin());


	std::cout << std::endl << *const_it << " this is iter =========" << std::endl;
	std::cout << std::endl << *it << " this is iter ===========" << std::endl;

	*it++;
	*it;
	*it = 2;

	std::cout << std::endl << *const_it << " this is iter" << std::endl;
	std::cout << std::endl << *it << " this is iter" << std::endl;
//	std::allocator<int> al;
//	al.()

//	auto it = hello.begin();
	ft::vector<bool> gg;
	gg.hello();
/*
	std::vector<int> vector(4,4);

	std::iota(vector.begin(), vector.end(), 1);
	std::vector<int>::iterator it = vector.begin();

//	*it = 3;
	std::cout << *it++ << std::endl;
	std::cout << vector[0] << std::endl;
	std::cout << vector[1] << std::endl;
	std::cout << vector[2] << std::endl;
	std::cout << vector[3] << std::endl;
	std::cout << *it << std::endl;

	std::cout << "-------------" << std::endl;

	std::cout << vector[0] << std::endl;
	std::cout << vector[1] << std::endl;
	std::cout << vector[2] << std::endl;
	std::cout << vector[3] << std::endl;*/

	return 0;

}