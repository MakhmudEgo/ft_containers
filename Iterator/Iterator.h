//
// Created by Mahmud Jego on 5/7/21.
//

#pragma once

template<class T>
class Iterator {
public:
	typedef T				value_type;
	typedef std::ptrdiff_t	difference_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef const T&		const_reference;


	Iterator(T* i) : _i( i ) {}
	Iterator( std::__1::__wrap_iter<T*> i) : _i( &( *i ) ) {}

	reference operator*() { return *_i; }
	const_reference operator*() const { return *_i; }

protected:
	T* _i;
};

template<class T>
class RandomAccess : public Iterator<T> {
public:
	typedef T				value_type;
	typedef std::ptrdiff_t	difference_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef const T&		const_reference;
	typedef RandomAccess	iterator_type;


	RandomAccess( T* i ) : Iterator< T >( i ) {}
	RandomAccess( std::__1::__wrap_iter< T* > i) : Iterator< T >( i ) {}

	// ***** post inc ***** //
	iterator_type operator++( int ) {
		return iterator_type( this->_i++ );
	}

	// ***** pre inc ***** //
	iterator_type& operator++() {
		++this->_i;
		return *this;
	}

	// ***** post inc ***** //
	iterator_type operator--( int ) {
		return iterator_type( this->_i-- );
	}

	// ***** post dec ***** //
	iterator_type& operator--() {
		--this->_i;
		return *this;
	}

	// ***** [] ***** //
	reference operator[]( int n ) { return this->_i[ n ]; }
	const_reference operator[]( int n ) const { return this->_i[ n ]; }

	// ***** + && - ***** //
	iterator_type operator+( int n ) { return iterator_type(this->_i + n); }
	iterator_type operator-( int n ) { return iterator_type(this->_i - n); }

	difference_type operator+( const iterator_type& other ) { return this->_i + other._i; }
	difference_type operator-( const iterator_type& other ) { return this->_i - other._i; }

	// ***** += && -= ***** //
	iterator_type operator+=( int n ) { return this->_i += n; }
	iterator_type operator-=( int n ) { return this->_i -= n; }

	// ***** > && < ***** //
	bool operator>( const iterator_type& other ) { return this->_i > other._i; }
	bool operator<( const iterator_type& other ) { return this->_i < other._i; }

	// ***** >= && <= ***** //
	bool operator>=( const iterator_type& other ) { return this->_i >= other._i; }
	bool operator<=( const iterator_type& other ) { return this->_i <= other._i; }

	// ***** == && != ***** //
	bool operator==( const RandomAccess<T>& other ) {
		return this->_i == other._i;
	}
	bool operator!=( const iterator_type& other ) { return this->_i != other._i; }

	// ***** utils ***** //
	iterator_type base() { return *this; }
};