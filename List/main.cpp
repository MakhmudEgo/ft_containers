//
// Created by Mahmud Jego on 5/15/21.
//

#include <list>
#include "List.h"
#include <numeric>

int main() {
/*	ft::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.clear();
	l.push_back(3);
	l.push_front(77);
//	l.pop_back();
//	l.pop_front();
	l.push_back(3);
	std::cout << "sz: " << l.size() << std::endl;
	std::cout << "f value: " << l.front() << std::endl;
	std::cout << "b value: " << l.back() << std::endl;
	std::cout << "max: " << l.max_size() << std::endl;*/

	ft::list<std::string> list;
	list.push_back("hello1");
	list.push_back("hello2");
	list.push_back("hello3");
	list.push_back("hello4");
	list.push_back("hello5");
	ft::list<std::string>::iterator it = list.begin();
//	++it;
//	ft::list<std::string>::iterator it1 = it;
	*it = "346";
	std::cout << *it;
//	std::list<int>::
//	for (int i = 0; i < 5; ++i, ++it1) {
//		std::cout << *it1 << ' ';
//	}

}
