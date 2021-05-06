//
// Created by Mahmud Jego on 5/6/21.
//

#include <iostream>
#include <vector>
#include <deque>
#include "Deque.h"
#include "overloadNewAndDelete.h"
struct testClass {
	testClass() {
		t = 1;
	}
	int t;
};

int main() {
	ft::deque<testClass> deque;

	int *hello = new int[3];
	return 0;
}