//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

#include <memory>
#include "Iterator.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <iterator>

template<bool B, class T = void>
struct enable_if { };

template<class T>
struct enable_if<true, T> {
	typedef T type;
};

namespace ft {
	template<
			class T,
			class Allocator = std::allocator< T >
	>
	class vector {
	public:
		// ***** Member types ***** //

		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef RandomAccess< T >					iterator;
		typedef ConstRandomAccess< T >				const_iterator;

		// ******************************	Member types	****************************** //

		vector& operator=( const vector& other ) {
			if ( this != &other ) {
				_alloc = other._alloc;
				for ( size_type i = 0; i < _sz; ++i ) {
					_alloc.destroy( _v + i );
				}
				if ( _cp ) {
					_alloc.deallocate( _v, _cp);
				}
				reserve( other._cp );
				for ( size_type i = 0; i < other._sz; ++i ) {
					_alloc.construct( _v + i, other._v[ i ] );
				}
				_sz = other._sz;
			}
			return *this;
		}

		// ******************************	iter			****************************** //

		iterator begin() { return _v; }
		iterator end() { return _v + _sz; }

		// ******************************	iter			****************************** //

		explicit vector( const Allocator &alloc = Allocator() )
				: _v( 0x0 ), _alloc( alloc ), _sz( 0 ), _cp( 0 ) {}

		explicit vector( size_t count,
				  const T &value = T(),
				  const Allocator &alloc = Allocator() )
				  : _alloc( alloc ), _sz( 0 ), _cp( 0 ) {
			default_init( count, value );
		}

		template< typename InputIt >
		vector( InputIt first, InputIt last,
		 const Allocator &alloc = Allocator(),
		 typename enable_if<!std::is_integral<InputIt>::value>::type * = 0 )
		 : _v( 0x0 ), _alloc( alloc ), _sz( 0 ), _cp( 0 ) {
			assign( first, last );
		}

		vector( const vector &other ) {
			operator=( other );
		}

		virtual ~vector() {
			if (_cp) {
				for (size_type i = _sz; i > 0; --i) {
					_alloc.destroy( _v + i - 1 );
				}
				_alloc.deallocate( _v, _cp );
			}
		}

		void assign( size_type count, const T& value ) { default_init( count, value ); }

		template< typename InputIt >
		typename enable_if< !std::is_integral< InputIt >::value, void >::type
		assign( InputIt first, InputIt last ) {
			size_type n = std::distance(first, last);
			reserve( n );
			_sz = n;

			for ( size_t i = 0; first != last; ++first, i++ ) {
				_alloc.construct( this->_v + i, *first );
			}
		}

		// ******************************	Element access	****************************** //

		reference		at( size_type pos ) {
			if ( pos >= _sz ) {
				throw std::out_of_range( "vector" );
			}
			return _v[ pos ];
		}
		const_reference	at( size_type pos ) const {
			if ( pos >= _sz ) {
				throw std::out_of_range("vector");
			}
			return _v[ pos ];
		}

		reference		operator[]( size_type pos ) { return _v[ pos ]; }
		const_reference	operator[]( size_type pos ) const { return _v[ pos ]; }
		reference		front() { return *_v; }
		const_reference	front() const { return *_v; }
		reference		back() { return _v[ _sz - 1 ]; }
		const_reference	back() const { return _v[ _sz - 1 ]; }

		// ******************************	Element access	****************************** //


		// ******************************	Capacity		****************************** //

		bool		empty() const { return !_sz; }
		size_t		size() const { return _sz; }
		size_type	max_size() const { return ULONG_LONG_MAX / sizeof( T ); }
		void		reserve( size_type new_cap ) {
			if ( new_cap <= _cp ) { return; }

			T* newVector = _alloc.allocate( new_cap );
			for (size_type i = 0; i < _sz; ++i ) {
				_alloc.construct( newVector + i, _v[ i ] );
			}

			for (size_type i = 0; i < _sz; ++i) {
				_alloc.destroy( _v + i );
			}

			if ( _cp ) {
				_alloc.deallocate( _v, _cp );
			}
			_v = newVector;
			_cp = new_cap;
		}
		size_type	capacity() const { return _cp; }

		// ******************************	Capacity		****************************** //


		// ******************************	Modifiers		****************************** //

		iterator	erase( iterator pos ) {
			for ( size_type i = 0; i < _sz; ++i ) {
				if ( &_v[ i ] == &( *pos ) ) {
					_alloc.destroy( _v + i );
					size_type el = i;
					for ( ; i < _sz - 1; ++i ) {
						_alloc.construct( _v + i, _v[ i + 1 ] );
					}
					if ( el != i ) {
						_alloc.destroy( _v + i );
					}
					_sz -= 1;
					return begin() + el;
				}
			}
			return pos;
		}
		iterator	erase( iterator first, iterator last ) {
			for ( size_type i = 0; i < _sz; ++i ) {
				if ( &_v[ i ] == &( *first ) ) {
					size_type el = i;
					for ( ; first != last; ++i, ++first ) {
						_alloc.destroy( _v + i );
					}
					_sz -= i - el;
					for ( ; el < _sz; ++i, ++el ) {
						_alloc.construct( _v + el, _v[ i ] );
					}
					return begin() + el;
				}
			}
			return last;
		}
		void		resize( size_t count, T value = T() ) {
			if ( count > _cp ) {
				reserve( count > _cp * 2 ? count : _cp * 2 );
				for ( size_type i = _sz; i < count; ++i ) {
					_alloc.construct( _v + i, value );
				}
			} else {
				if ( count < _sz ) {
					for ( size_type i = count - 1; i < _sz; ++i ) {
						_alloc.destroy( _v + i );
					}
				} else if ( count != _sz ) {
					for ( size_t i = _sz; i < count; ++i ) {
						_alloc.construct( _v + i, value );
					}
				}
			}
			_sz = count;
		}
		void		push_back( const T& value ) {
			check_capacity();
			_v[ _sz ] = value;
			++_sz;
		}

		iterator	insert( iterator pos, const T& value ) {
			size_type i = 0;
			for ( ; i <= _sz; ++i ) {
				if ( &_v[ i ] == &( *pos ) ) {
					check_capacity();
					_alloc.construct( _v + _sz, _v[ _sz - 1 ] );
					for ( size_type j = _sz; j > i + 1; --j ) {
						_v[ j - 1 ] = _v[ j - 2 ];
					}
					_v[ i ] = value;
					++_sz;
					break;
				}
			}
			return _v + i;
		}
		void		insert( iterator pos, size_type count, const T& value ) {
			size_type i = 0;
			for ( ; i <= _sz; ++i ) {
				if ( &_v[ i ] == &( *pos ) ) {
					if ( count > _cp ) {
						reserve(count > _cp * 2 ? count : _cp * 2);
					}
					size_t n = 0;
					for (size_t j = _sz + count; j > i + count; --j) {
						_alloc.construct( _v + j - 1, _v[ j - count - 1]);
						n =  j - 1;
					}
					n ? --n : 0;
					for (; n > i + count - 1; --n) {
						_v[ n ] = _v[ n - count ];
					}
					if (n)
						for (size_t g = 0; g < count; ++g, --n) {
							_v[ n ] = value;
						}
					else
						for (size_t g = 0; g < count; ++g, ++n) {
							_v[ n ] = value;
						}
					_sz += count;
				}
			}
		}

		template< class InputIt >
		size_t my_dist(InputIt first, InputIt last) {
			size_t res = 0;
			while (first != last) {
				++res;
				++first;
			}
			return res;
		}

		template< class InputIt >
		typename enable_if< !std::is_integral< InputIt >::value, void >::type
		insert( iterator pos, InputIt first, InputIt last ) {
			size_t count = my_dist(first, last);
			size_type i = 0;
			for ( ; i <= _sz; ++i ) {
				if ( &_v[ i ] == &( *pos ) ) {
					if ( count > _cp ) {
						reserve(count > _cp * 2 ? count : _cp * 2);
					}
					size_t n = 0;
					for (size_t j = _sz + count; j > i + count; --j) {
						_alloc.construct( _v + j - 1, _v[ j - count - 1]);
						n =  j - 1;
					}
					n ? --n : 0;
					for (; n > i + count - 1; --n) {
						_v[ n ] = _v[ n - count ];
					}
					if (n)
						for (size_t g = 0; g < count; ++g, --n, ++first) {
							_v[ n ] = *first;
						}
					else
						for (size_t g = 0; g < count; ++g, ++n, ++first) {
							_v[ n ] = *first;
						}
					_sz += count;
				}
			}
		}


		// ******************************	Modifiers		****************************** //

	private:
		value_type *_v;
		allocator_type _alloc;
		size_type _sz;
		size_t _cp;

		void	default_init( size_type count, const T &value = T() ) {
			reserve( count );
			_sz = count;
			for ( size_t i = 0; i < count; ++i ) {
				_alloc.construct( _v + i, value );
			}
		}

		void	check_capacity() {
			if ( _sz == _cp ) {
				reserve( !_cp ? 1 : _cp * 2);
			}
		}
	};

	template<class Allocator>
	class vector<bool, Allocator> {
	public:
		void hello() const {
//			std::cout << "this is vector<bool>" << std::endl;
		}
	};
}