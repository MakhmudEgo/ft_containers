//
// Created by Mahmud Jego on 5/15/21.
//

#pragma once

#include <iostream>

namespace ft {
	template<
			class T,
			class Allocator = std::allocator <T>
	>
	class list {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
//		typedef ... iterator
//		typedef ... const_iterator
//		typedef ... reverse_iterator
//		typedef ... const_reverse_iterator

		// ******************************	Member functions	****************************** //

		list() : _l_front(0x0), _l_back(0x0), _sz(0) {}
		explicit list( const Allocator& alloc )
				: _l_front(0x0), _l_back(0x0), _alloc(alloc), _sz(0) {}
		explicit list( size_type count,
					   const T& value = T(),
					   const Allocator& alloc = Allocator())
				: _l_front(0x0), _l_back(0x0), _alloc(alloc), _sz(0) {
			for (size_type i = 0; i < count; ++i) {
				push_back(value);
			}
		}
		explicit list( size_type count ) {
			for (size_type i = 0; i < count; ++i) {
				push_back(T());
			}
		}
		virtual ~list() { clear(); }

		// ******************************	Member functions	****************************** //


		// ******************************	Element access		****************************** //

		reference		front() { return *_l_front->_data; }
		const_reference	front() const { return *_l_front->_data; }
		reference		back() { return *_l_back->_data; };
		const_reference	back() const { return *_l_back->_data; };

		// ******************************	Element access		****************************** //


		// ******************************		Capacity		****************************** //

		bool		empty() const { return !_sz; }
		size_type	size() const {return _sz; }
		size_type	max_size() const { return ULONG_LONG_MAX / sizeof(Node); }

		// ******************************		Capacity		****************************** //


		// ******************************		Modifiers		****************************** //

		void	clear() {
			if (_sz) {
				while (_l_front) {
					_alloc.destroy(_l_front->_data);
					_alloc.deallocate(_l_front->_data, 1);
					Node *tmp = _l_front;
					_l_front = _l_front->next;
					delete tmp;
				}
				_l_front = 0x0;
				_l_back = 0x0;
				_sz = 0;
			}
		}
		void	push_back( const T& value ) {
			Node *_new_node = new Node;
			_new_node->_data = _alloc.allocate(1);
			_alloc.construct(_new_node->_data, value);
			_new_node->next = 0x0;
			_new_node->prev = _l_back;

			if (!_sz) {
				_l_front = _new_node;
				_l_back = _new_node;
			} else {
				_l_back->next = _new_node;
				_l_back = _new_node;
			}
			++_sz;
		}
		void	pop_back() {
			if (_sz) {
				_alloc.destroy(_l_back->_data);
				_alloc.deallocate(_l_back->_data, 1);
				Node *tmp = _l_back;

				_l_back = _l_back->prev;
				if (_l_back) {
					_l_back->next = 0x0;
				} else {
					_l_front = 0x0;
				}
				delete tmp;
				--_sz;
			}
		}
		void	push_front( const T& value ) {
			Node *_new_node = new Node;
			_new_node->_data = _alloc.allocate(1);
			_alloc.construct(_new_node->_data, value);
			_new_node->next = _l_front;
			_new_node->prev = 0x0;

			if (!_sz) {
				_l_front = _new_node;
				_l_back = _new_node;
			} else {
				_l_front->prev = _new_node;
				_l_front = _new_node;
			}
			++_sz;
		}
		void	pop_front() {
			if (_sz) {
				_alloc.destroy(_l_front->_data);
				_alloc.deallocate(_l_front->_data, 1);
				Node *tmp = _l_front;

				_l_front = _l_front->prev;
				if (_l_front) {
					_l_front->next = 0x0;
				} else {
					_l_back = 0x0;
				}
				delete tmp;
				--_sz;
			}
		}

		// ******************************		Modifiers		****************************** //
	private:
		struct Node {
			T* _data;
			struct Node *next;
			struct Node *prev;
		};

		Node		*_l_front;
		Node		*_l_back;
		Allocator	_alloc;
		size_type	_sz;
	};

}
