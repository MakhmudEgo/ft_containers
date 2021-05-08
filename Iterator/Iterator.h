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

	// ***** post inc ***** //
	T* operator++(int) { return this->_i++; }

	// ***** pre inc ***** //
	T* operator++() { return ++this->_i; }

	// ***** post inc ***** //
	T* operator--( int ) { return this->_i--; }

	// ***** post dec ***** //
	T* operator--() { return --this->_i; }

	// ***** [] ***** //
	T& operator[](int n) { return this->_i[n]; }
	const T& operator[](int n) const { return this->_i[n]; }

	// ***** + && - ***** //
	T* operator+(int n) { return this->_i + n; }
	T* operator-(int n) { return this->_i - n; }

	// ***** += && -= ***** //
	T* operator+=(int n) { return this->_i += n; }
	T* operator-=(int n) { return this->_i -= n; }

	// ***** > && < ***** //
	bool operator>(const LegacyRandomAccessIterator& other) { return this->_i > other._i; }
	bool operator<(const LegacyRandomAccessIterator& other) { return this->_i < other._i; }

	// ***** >= && <= ***** //
	bool operator>=(const LegacyRandomAccessIterator& other) { return this->_i >= other._i; }
	bool operator<=(const LegacyRandomAccessIterator& other) { return this->_i <= other._i; }

	// ***** == && != ***** //
	bool operator==(const LegacyRandomAccessIterator& other) { return this->_i == other._i; }
	bool operator!=(const LegacyRandomAccessIterator& other) { return this->_i != other._i; }
};