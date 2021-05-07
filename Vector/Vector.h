//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

#include <memory>
#include "Iterator.h"

/*template<class T>
class LegacyRandomAccessIterator{
public:
	LegacyRandomAccessIterator( T* i ) : _i(i) {}
	LegacyRandomAccessIterator( std::__1::__wrap_iter<T*> i) : _i( &( *i ) ) {}
	void hello() {

	}
	T& operator*() { return *_i; }
	const T& operator*() const { return *_i; }

	T& operator++(int) {
		_i++;
		return *_i;
	}
	T& operator++() {
		_i++;
		return *_i;
	}
*//*	const T& operator++(int) {
		_i++;
		return _i;
	}*//*

private:
	T* _i;
};*/
namespace ft {
	template<
			class T,
			class Allocator = std::allocator<T>
	>
	class vector {
	public:
		// ***** iter ***** //
		typedef LegacyRandomAccessIterator<T> iterator;
		typedef const LegacyRandomAccessIterator<T> const_iterator;

		iterator begin() { return _pVector; }
		const_iterator begin() const { return _pVector; }

		iterator end() { return _pVector + _sz; }
		const_iterator end() const { return _pVector + _sz; }






		explicit vector( const Allocator &alloc = Allocator() )
				: _pVector( 0x0 ), _alloc( alloc ), _sz( 0 ), _cp( 0 ) {}

		explicit vector( size_t count,
				  const T &value = T(),
				  const Allocator &alloc = Allocator() )
				  : _alloc( alloc ), _sz( 0 ), _cp(0) {
			reserve(count);
			_sz = count;
			for (size_t i = 0; i < count; ++i) {
				_alloc.construct(_pVector + i, value);
			}
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

		size_t size() const {
			return _sz;
		}

		size_t capacity() const {
			return _cp;
		}

		void resize( size_t count, T value = T() ) {
			if (count > _cp) {
				size_t tmp = _cp;
				while (tmp < count) {
					tmp *= 2;
				}
				reserve(tmp);
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
			_alloc.deallocate(_pVector, _cp);
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
		T *_pVector;
		Allocator _alloc;
		size_t _sz;
		size_t _cp;
	};

	template<class Allocator>
	class vector<bool, Allocator> {
	public:
		void hello() const {
			std::cout << "this is vector<bool>" << std::endl;
		}
	};
}