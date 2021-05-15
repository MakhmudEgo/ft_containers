//
// Created by Mahmud Jego on 5/15/21.
//

#include <list>
#include "List.h"

int main() {
	std::cout << "hello List" << std::endl;

	ft::list<int> l(4, 5);

	l.push_back(1);
	l.push_back(2);
	l.clear();
	l.push_back(3);
	l.push_front(77);

	std::cout << "sz: " << l.size() << std::endl;
	std::cout << "f value: " << l.front() << std::endl;
	std::cout << "b value: " << l.back() << std::endl;
	std::cout << "max: " << l.max_size() << std::endl;

}
