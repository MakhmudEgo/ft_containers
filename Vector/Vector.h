//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

#include <memory>
#include "Iterator.h"
#include <iostream>
#include <stdexcept>
#include <limits>


template<bool B, class T = void>
struct enable_if { };

template<class T>
struct enable_if<true, T> {
	typedef T type;
};

namespace ft {
	template<
			class T,
			class Allocator = std::allocator<T>
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
		typedef RandomAccess<T>						iterator;
		typedef ConstRandomAccess<T>				const_iterator;

		// *************** Member types *************** //

		// *************** iter *************** //

		iterator begin() { return _v; }
		iterator end() { return _v + _sz; }

		// *************** iter *************** //

		explicit vector( const Allocator &alloc = Allocator() )
				: _v( 0x0 ), _alloc( alloc ), _sz(0 ), _cp(0 ) {}

		explicit vector( size_t count,
				  const T &value = T(),
				  const Allocator &alloc = Allocator() )
				  : _alloc( alloc ), _sz( 0 ), _cp(0) {
			default_init(count, value);
		}

		template< typename InputIt >
		vector(InputIt first, InputIt last,
		 const Allocator &alloc = Allocator(),
		 typename enable_if<!std::is_integral<InputIt>::value>::type * = 0)
		 : _v(0x0 ), _alloc(alloc), _sz(0 ), _cp(0 ) {
			assign(first, last);
		}

		vector(const vector &other) {
			if(_v != &other) {
				//
			}
		}

		void assign( size_type count, const T& value ) { default_init( count, value ); }

		template< typename InputIt >
		typename enable_if<!std::is_integral<InputIt>::value, void>::type
		assign( InputIt first, InputIt last) {
			reserve( last - first );
			_sz = last - first;

			for (size_t i = 0; first != last; ++first, i++) {
				_alloc.construct(this->_v + i, *first);
			}
		}

		// *************** Element access *************** //

		reference at( size_type pos ) {
			if (pos >= _sz) {
				throw std::out_of_range("vector");
			}
			return _v[pos];
		}
		const_reference	at( size_type pos ) const {
			if (pos >= _sz) {
				throw std::out_of_range("vector");
			}
			return _v[pos];
		}

		reference		operator[]( size_type pos ) { return _v[pos]; }
		const_reference	operator[]( size_type pos ) const { return _v[pos]; }
		reference		front() { return *_v; }
		const_reference	front() const { return *_v; }
		reference		back() { return _v[_sz - 1]; }
		const_reference	back() const { return _v[_sz - 1]; }

		// *************** Element access *************** //


		// *************** Capacity *************** //

		bool		empty() const { return !_sz; }
		size_t		size() const { return _sz; }
		size_type	max_size() const { return ULONG_LONG_MAX / sizeof( T ); }
		void		reserve( size_type new_cap ) {
			if (new_cap <= _cp) {
				return;
			}
			T* newVector = _alloc.allocate(new_cap);
//			std::uninitialized_copy(_v, _v + _sz, newVector); // TODO:: when be iter
			{
				for (size_t i = 0; i < _sz; ++i) {
					_alloc.construct(newVector + i, _v[i]);
				}
			}
			for (size_t i = 0; i < _sz; ++i) {
				_alloc.destroy(_v + i);
			}
			if (_cp) {
				_alloc.deallocate(_v, _cp);
			}
			_v = newVector;
			_cp = new_cap;
		}
		size_type	capacity() const { return _cp; }

		// *************** Capacity *************** //


		// *************** Modifiers *************** //

		iterator erase( iterator pos ) {
			for (size_type i = 0; i < _sz; ++i) {
				if (&_v[i] == &(*pos)) {
					_alloc.destroy(_v + i);
					size_type el = i;
					for (; i < _sz - 1; ++i) {
						_alloc.construct(_v + i, _v[i + 1]);
					}
					if (el != i) {
						_alloc.destroy(_v + i);
					}
					_sz -= 1;
					return begin() + el;
				}
			}
			return pos;
		}

		iterator erase( iterator first, iterator last ) {
			for (size_type i = 0; i < _sz; ++i) {
				if (&_v[i] == &(*first)) {
					size_type el = i;
					for (; first != last; ++i, ++first) {
						_alloc.destroy(_v + i);
					}
					_sz -= i - el;
					for (; el < _sz; ++i, ++el) {
						_alloc.construct(_v + el, _v[i]);
					}
					return begin() + el;
				}
			}
			return last;
		}

		void resize( size_t count, T value = T() ) {
			if (count > _cp) {
				size_t possible_size = _cp;
				if (_cp * 2 > count) {
					while (possible_size < count) {
						possible_size *= 2;
					}
				}
				reserve(count > possible_size ? count : possible_size);
				for (size_t i = _sz; i < count; ++i) {
					_alloc.construct(_v + i, value);
				}
			} else {
				if (count < _sz) {
					for (size_t i = count - 1; i < _sz; ++i) {
						_alloc.destroy(_v + i);
					}
				} else if (count != _sz) {
					for (size_t i = _sz; i < count; ++i) {
						_alloc.construct(_v + i, value);
					}
				}
			}
			_sz = count;
		}

		void push_back( const T& value ) {
			if (_sz == _cp) {
				reserve(_cp * 2);
			}
			_v[_sz] = value;
			++_sz;
		}


		// *************** Modifiers *************** //

	private:
		value_type *_v;
		allocator_type _alloc;
		size_type _sz;
		size_t _cp;

		void default_init( size_type count, const T &value = T()) {
			reserve(count);
			_sz = count;
			for (size_t i = 0; i < count; ++i) {
				_alloc.construct(_v + i, value);
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