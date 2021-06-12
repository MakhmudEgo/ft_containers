//
// Created by Makhmud Ego on 10.06.2021.
//

#pragma once

namespace ft {
	template<
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T> >
	> class map {
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
//		iterator
//		const_iterator
//		reverse_iterator
//		const_reverse_iterator
	private:
		enum NodeColor {
			BLACK,
			RED
		};
		struct Node {
			std::pair<const Key, T>		*_data;
			NodeColor					_color;
			struct Node					*_left;
			struct Node					*_right;
			struct Node					*_parent;
		}
	public:
		//
	private:
		Node		*_root;
		Allocator	_alloc;
		size_type	_sz;
	};
}