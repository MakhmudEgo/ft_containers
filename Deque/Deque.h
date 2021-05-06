//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once
#include <memory>

namespace ft {
	template<
			class T,
			class Allocator = std::allocator<T>
	> class deque {
	public:
		explicit deque( const Allocator& alloc = Allocator() )
				: value_type(0x0), allocator_type(alloc), size_type(0), sz_pPtr(0) {}

		explicit deque( size_t count,
				  const T& value = T(),
				  const Allocator& alloc = Allocator() ) {

		}
		template< class InputIt >
		deque( InputIt first, InputIt last,
			   const Allocator& alloc = Allocator() ) {
		}
		deque( const deque& other ) {

		}
//		iterator
//		const_iterator
//		reverse_iterator
//		const_reverse_iterator
//		std::ptrdiff_t difference_type;

	private:
		T** value_type;
		Allocator allocator_type;
		std::allocator<T*> allocPtr;
		size_t size_type;
		size_t sz_pPtr;




/*		typename Allocator::reference reference;
		typename Allocator::const_reference const_reference;
		typename Allocator::pointer pointer;
		typename Allocator::const_pointer const_pointer;*/
	};
}


/*value_type = allocPtr.allocate(8);
			value_type[3] = allocator_type.allocate(8);
			value_type[4] = allocator_type.allocate(8);
			std::uninitialized_fill(value_type[3], value_type[3] + (sizeof(T) * 8), T());*/