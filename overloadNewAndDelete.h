//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

void *operator new(size_t n) throw(std::bad_alloc) {
	std::cout << "\033[1;33m" << "size : " << n << "\033[0m" << std::endl;
	return malloc(n);
}
void operator delete(void* ptr) throw() {
	std::cout << "\033[1;33m" << "bye bye" << "\033[0m" << std::endl;//
	free(ptr);
}
