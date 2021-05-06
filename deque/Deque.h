//
// Created by Mahmud Jego on 5/6/21.
//

#pragma once

namespace ft {
	template<
			class T,
			class Allocator = std::allocator<T>
	> class deque {
	public:
		explicit deque( const Allocator& alloc = Allocator() ) {

		}
		explicit deque( size_t count,
						const T& value = T(),
						const Allocator& alloc = Allocator()) {

		}
		template< class InputIt >
		deque( InputIt first, InputIt last,
			   const Allocator& alloc = Allocator() ) {

		}
	private:
		T value_type;
		Allocator allocator_type;
		size_t size_type;
		std::ptrdiff_t difference_type;
		typename Allocator::reference reference;
		typename Allocator::const_reference const_reference;
		typename Allocator::pointer pointer;
		typename Allocator::const_pointer const_pointer;
//		iterator
//		const_iterator
//		reverse_iterator
//		const_reverse_iterator
	};
}