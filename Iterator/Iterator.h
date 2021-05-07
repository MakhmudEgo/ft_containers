//
// Created by Mahmud Jego on 5/7/21.
//

#pragma once

template<class T>
class Iterator {
public:
	Iterator(T* i) : _i( i ) {}
	Iterator( std::__1::__wrap_iter<T*> i) : _i( &( *i ) ) {}

	T& operator*() { return *_i; }
	const T& operator*() const { return *_i; }

//	virtual T& operator++();

//protected:
	T* _i;
};

template<class T>
class LegacyRandomAccessIterator : public Iterator<T> {
public:
	LegacyRandomAccessIterator( T* i ) : Iterator<T>(i) {}
	LegacyRandomAccessIterator( std::__1::__wrap_iter<T*> i) : Iterator<T>(i) {}

	T* operator++(int) {
		T* old = this->_i++;
		return old;
	}

};