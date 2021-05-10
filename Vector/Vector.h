//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

#include <memory>
#include "Iterator.h"

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
		typedef const RandomAccess<T>				const_iterator;

		// ***** Member types ***** //

		// ***** iter ***** //

		iterator begin() { return _pVector; }
		const_iterator begin() const { return _pVector; }

		iterator end() { return _pVector + _sz; }
		const_iterator end() const { return _pVector + _sz; }

		// ***** iter ***** //






		explicit vector( const Allocator &alloc = Allocator() )
				: _pVector( 0x0 ), _alloc( alloc ), _sz( 0 ), _cp( 0 ) {}

		explicit vector( size_t count,
				  const T &value = T(),
				  const Allocator &alloc = Allocator() )
				  : _alloc( alloc ), _sz( 0 ), _cp(0) {
			default_init(count, value);
		}

/*		template<class InputIt>
		vector(InputIt first, InputIt last,
		 const Allocator &alloc = Allocator()) {

		}*/

		vector(const vector &other) {
			if(_pVector != &other) {
				//
			}
		}

		void assign( size_type count, const T& value ) {
			default_init(count, value);
		}

/*		template< class InputIt >
		void assign( InputIt first, InputIt last ) {

		}*/

		size_t size() const {
			return _sz;
		}

		size_t capacity() const {
			return _cp;
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
					_alloc.construct(_pVector + i, value);
				}
			} else {
				if (count < _sz) {
					for (size_t i = count - 1; i < _sz; ++i) {
						_alloc.destroy(_pVector + i);
					}
				} else if (count != _sz) {
					for (size_t i = _sz; i < count; ++i) {
						_alloc.construct(_pVector + i, value);
					}
				}
			}
			_sz = count;
		}

		void reserve( size_t new_cap ) {
			if (new_cap <= _cp) {
				return;
			}
			T* newVector = _alloc.allocate(new_cap);
//			std::uninitialized_copy(_pVector, _pVector + _sz, newVector); // TODO:: when be iter
			{
				for (size_t i = 0; i < _sz; ++i) {
					_alloc.construct(newVector + i, _pVector[i]);
				}
			}
			for (size_t i = 0; i < _sz; ++i) {
				_alloc.destroy(_pVector + i);
			}
			if (_cp) {
				_alloc.deallocate(_pVector, _cp);
			}
			_pVector = newVector;
			_cp = new_cap;
		}

		T& operator[](size_t n) {
			return _pVector[n];
		}

		const T& operator[](size_t n) const {
			return _pVector[n];
		}


	private:
		value_type *_pVector;
		allocator_type _alloc;
		size_type _sz;
		size_t _cp;

		void default_init( size_type count, const T &value = T()) {
			reserve(count);
			_sz = count;
			for (size_t i = 0; i < count; ++i) {
				_alloc.construct(_pVector + i, value);
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