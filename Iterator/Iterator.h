//
// Created by Mahmud Jego on 5/18/21.
//

#pragma once

namespace ft {
	template<class T>
	class Iterator {
	public:

		Iterator(T *i) : _i(i) {}
		Iterator(const Iterator<T> &other) : _i(other._i) {}
		Iterator(std::__1::__wrap_iter<T *> i) : _i(&(*i)) {}
		Iterator<T> operator=(const Iterator<T>& other) {
			if (this != &other) {
				this->_i = other._i;
			}
			return *this;
		}
		virtual ~Iterator() {}

	protected:
		T *_i;
	};
}