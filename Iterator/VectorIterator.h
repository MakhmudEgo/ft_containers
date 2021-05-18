//
// Created by Mahmud Jego on 5/7/21.
//

#pragma once

#include "Iterator.h"

namespace ft {

	template<class T>
	class VectorIterator : public Iterator<T> {
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef VectorIterator	iterator_type;


		VectorIterator( T *i )
				: Iterator< T >( i ) {}
		VectorIterator( const Iterator< T > &i )
				: Iterator< T >( i ) {}
		VectorIterator( std::__1::__wrap_iter< T* > i )
				: Iterator< T >( i ) {}

		reference		operator*() { return *this->_i; }
		const_reference	operator*() const { return *this->_i; }

		// ***** post inc ***** //
		iterator_type	operator++( int ) { return  this->_i++; }

		// ***** pre inc ***** //
		iterator_type&	operator++() { ++this->_i; return *this; }

		// ***** post dec ***** //
		iterator_type	operator--( int ) { return this->_i--; }

		// ***** post dec ***** //
		iterator_type&	operator--() { --this->_i; return *this; }

		// ***** [] ***** //
		reference		operator[]( int n ) { return this->_i[ n ]; }

		// ***** -> ***** //
//		pointer operator->() { return this; }

		// ***** + && - ***** //
		iterator_type	operator+( int n ) { return this->_i + n; }
		iterator_type	operator-( int n ) { return this->_i - n; }
		difference_type	operator+( const iterator_type &other ) { return this->_i + other._i; }
		difference_type	operator-( const iterator_type &other ) { return this->_i - other._i; }

		// ***** += && -= ***** //
		iterator_type	operator+=( int n ) { return this->_i += n; }
		iterator_type	operator-=( int n ) { return this->_i -= n; }

		// ***** > && < ***** //
		bool			operator>( const iterator_type &other ) { return this->_i > other._i; }
		bool			operator<( const iterator_type &other ) { return this->_i < other._i; }

		// ***** >= && <= ***** //
		bool			operator>=( const iterator_type &other ) { return this->_i >= other._i; }
		bool			operator<=( const iterator_type &other ) { return this->_i <= other._i; }

		// ***** == && != ***** //
		bool			operator==( const VectorIterator< T > &other ) { return this->_i == other._i; }
		bool			operator!=(const iterator_type &other) { return this->_i != other._i; }

		// ***** utils ***** //
		iterator_type	base() { return *this; }
	};

	template< class T >
	class ConstVectorIterator : public VectorIterator< T > {
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

		ConstVectorIterator( T *i )
				: VectorIterator< T >( i ) {}
		ConstVectorIterator( std::__1::__wrap_iter<T *> i )
				: VectorIterator< T >( i ) {}
		ConstVectorIterator( const Iterator< T > &other )
				: VectorIterator< T >( other ) {}

		const_reference	operator*() { return *this->_i; }
		const_reference	operator[]( int n ) const { return this->_i[ n ]; }
	};

	template<class T>
	class ReverseVectorIterator : public Iterator<T> {
	public:
		typedef T						value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef T*						pointer;
		typedef T&						reference;
		typedef const T&				const_reference;
		typedef ReverseVectorIterator	iterator_type;


		ReverseVectorIterator( T  *i )
				: Iterator<T>( i ) {}
		ReverseVectorIterator( const Iterator< T > &i )
				: Iterator< T >( i ) {}
		ReverseVectorIterator( std ::__1::__wrap_iter< T* > i )
				: Iterator< T >( i ) {}

		reference		operator*() { return *this->_i; }
		const_reference	operator*() const{ return *this->_i; }

		// ***** post inc ***** //
		iterator_type	operator++( int ) { return this->_i--; }

		// ***** pre inc ***** //
		iterator_type&	operator++() { --this->_i; return *this; }

		// ***** post inc ***** //
		iterator_type	operator--( int ) { return this->_i++; }

		// ***** post dec ***** //
		iterator_type&	operator--() { ++this->_i; return *this; }

		// ***** [] ***** //
		reference		operator[]( int n ) { return this->_i[ -n ]; }

		// ***** + && - ***** //
		iterator_type	operator+( int n ) { return this->_i - n; }

		iterator_type	operator-( int n ) { return this->_i + n; }

		difference_type	operator+( const iterator_type &other ) { return this->_i - other._i; }

		difference_type	operator-( const iterator_type &other ) { return this->_i + other._i; }

		// ***** += && -= ***** //
		iterator_type	operator+=( int n ) { return this->_i -= n; }
		iterator_type	operator-=( int n ) { return this->_i += n; }

		// ***** > && < ***** //
		bool			operator>( const iterator_type &other ) { return this->_i < other._i; }
		bool			operator<( const iterator_type &other ) { return this->_i > other._i; }

		// ***** >= && <= ***** //
		bool			operator>=( const iterator_type &other ) { return this->_i <= other._i; }
		bool			operator<=( const iterator_type &other ) { return this->_i >= other._i; }

		// ***** == && != ***** //
		bool			operator==( const ReverseVectorIterator< T > &other ) { return this->_i == other._i; }
		bool			operator!=( const iterator_type &other ) { return this->_i != other._i; }

		// ***** utils ***** //
		iterator_type	base() { return *this; }
	};

	template<class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T> {
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

		ConstReverseVectorIterator( T* i )
				: ReverseVectorIterator< T >( i ) {}
		ConstReverseVectorIterator( std::__1::__wrap_iter< T* > i )
				: ReverseVectorIterator< T >( i ) {}
		ConstReverseVectorIterator( const Iterator< T > &i )
				: ReverseVectorIterator< T >( i ) {}

		const_reference	operator*() { return *this->_i; }
		const_reference	operator[]( int n ) const { return this->_i[ n ]; }
	};

}