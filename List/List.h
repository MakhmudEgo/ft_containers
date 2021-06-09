//
// Created by Mahmud Jego on 5/15/21.
//

#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>
#include <limits>

template< bool B, class T = void >
struct enable_if { };

template< class T >
struct enable_if< true, T > {
	typedef T type;
};

namespace ft {
	template< class T, class Node >
	class ListIterator;
	template< class T, class Node >
	class ConstListIterator;

	template<
			class T,
			class Allocator = std::allocator <T>
	>
	class list {
	private:
		struct Node {
			T*			_data;
			struct Node	*next;
			struct Node	*prev;

			Node()
					: _data( 0x0 ),
					  next( 0x0 ),
					  prev( 0x0 ) {}
			Node( T		*data,
				  Node	*next = 0x0,
				  Node	*prev = 0x0 )
					: _data( data ),
					  next( next ),
					  prev( prev ) {}
		};

	public:
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef ListIterator<T, Node>				iterator;
		typedef ConstListIterator<T, Node>			const_iterator;
//		typedef ... reverse_iterator
//		typedef ... const_reverse_iterator

		// ******************************	Member functions	****************************** //

		list()
				: _l_front( new Node( _alloc.allocate( 1 ) ) ),
				  _l_back( _l_front ),
				  _sz( 0 ) {
			_l_front->next = _l_back;
			_l_back->prev = _l_front;
		}

		explicit list( const Allocator& alloc )
				: _alloc( alloc ),
				  _l_front( new Node(_alloc.allocate( 1 ) ) ),
				  _l_back( _l_front ),
				  _sz( 0 ) {
			_l_front->next = _l_back;
			_l_back->prev = _l_front;
		}

		explicit list( size_type		count,
					   const T&			value = T(),
					   const Allocator&	alloc = Allocator() )
				: _alloc( alloc ),
				  _l_front( new Node( _alloc.allocate( 1 ) ) ),
				  _l_back( _l_front ),
				  _sz( 0 ) {
			_l_front->next = _l_back;
			_l_back->prev = _l_front;
			for ( size_type i = 0; i < count; ++i ) {
				push_back( value );
			}
		}

		template< class InputIt >
		list( InputIt			first,
			  InputIt			last,
			 const Allocator&	alloc = Allocator() )
			 : _alloc(alloc),
			  _l_front( new Node(_alloc.allocate( 1 ) ) ),
			  _l_back( _l_front ),
			  _sz( 0 ) {
			_l_front->next = _l_back;
			_l_back->prev = _l_front;
			for ( ; first != last; ++first) {
				push_back(*first);
			}
		}

		virtual ~list() {
			clear();
			_alloc.destroy( _l_front->_data );
			_alloc.deallocate( _l_front->_data, 1 );
			delete _l_front;
		}

		list( const list& other ) {
			operator=(other);
		}

		list& operator=( const list& other ) {
			if (this != other) {
				this->clear();
				list::iterator it = other.begin();
				for (; it != end() ; ++it) {
					push_back(*it);
				}
			}
			return *this;
		}

		void assign( size_type count, const T& value ) {
			clear();
			for ( size_type i = 0; i < count; ++i ) {
				push_back( value );
			}
		}
		template< class InputIt >
		typename enable_if< !std::is_integral< InputIt >::value, void >::type
		assign( InputIt first, InputIt last ) {
			clear();
			for ( ; first != last; ++first) {
				push_back(*first);
			}
		}

		allocator_type get_allocator() const {
			return _alloc;
		}

		// ******************************	Member functions	****************************** //


		// ******************************	Element access		****************************** //

		reference		front() { return *_l_front->next->_data; }
		const_reference	front() const { return *_l_front->next->_data; }
		reference		back() { return *_l_back->prev->_data; };
		const_reference	back() const { return *_l_back->prev->_data; };

		// ******************************	Element access		****************************** //


		// ******************************		Iterators		****************************** //

		iterator 		begin() { return ( _l_front->next ); }
		const_iterator	begin() const { return ( _l_front->next ); }
		iterator		end() { return ( _l_back ); }
		const_iterator	end() const { return ( _l_back ); }

		// ******************************		Iterators		****************************** //


		// ******************************		Capacity		****************************** //

		bool		empty() const { return !_sz; }
		size_type	size() const {return _sz; }
		size_type	max_size() const { return ULONG_LONG_MAX / sizeof( Node ); }

		// ******************************		Capacity		****************************** //


		// ******************************		Modifiers		****************************** //

		void		clear() {
			if ( _sz ) {
				Node *clr = _l_front->next;
				while ( clr != _l_back ) {
					_alloc.destroy( clr->_data );
					_alloc.deallocate( clr->_data, 1 );
					Node *tmp = clr;
					clr = clr->next;
					delete tmp;
				}
				_l_front->next = _l_back;
				_l_back->prev = _l_front;
				_sz = 0;
			}
		}
		iterator	insert( iterator pos, const T& value ) {
			Node *newNode = new Node(_alloc.allocate(1));
			_alloc.construct(newNode->_data, value);
			push_prev(pos._i, newNode);
			return newNode;
		}
		void		insert( iterator pos, size_type count, const T& value ) {
			for ( size_type i = 0; i < count; ++i) {
				Node *newNode = new Node(_alloc.allocate(1));
				_alloc.construct(newNode->_data, value);
				push_prev(pos._i, newNode);
				pos._i = newNode;
			}
		}
		template< class InputIt >
		typename enable_if< !std::is_integral< InputIt >::value, void >::type
		insert( iterator pos, InputIt first, InputIt last ) {
			for ( ; first != last; ++first) {
				insert(pos, *first);
			}
		}
		iterator	erase( iterator pos ) {
			Node *tmp = pos._i;
			Node *res = pos._i->next;
			pos._i->prev->next = res;
			res->prev = pos._i->prev;
			_alloc.destroy(tmp->_data);
			_alloc.deallocate(tmp->_data, 1);
			--_sz;
			delete tmp;
			return res;
		}
		iterator	erase( iterator first, iterator last ) {
			while ( first != last ) {
				Node *tmp = first._i->next;
				erase(first);
				first = tmp;
			}
			return first;
		}
		void		push_back( const T& value ) {
			Node *_new_node = new Node;

			_new_node->_data = _alloc.allocate( 1 );
			_alloc.construct( _new_node->_data, value );
			_new_node->next = _l_back;
			_new_node->prev = _l_back->prev;

			if ( !_sz ) {
				_l_front->next = _new_node;
			} else {
				_l_back->prev->next = _new_node;
			}
			_l_back->prev = _new_node;
			++_sz;
		}
		void		pop_back() {
			if ( _sz ) {
				Node *tmp = _l_back->prev;

				_l_back->prev->prev->next = _l_back;
				_alloc.destroy( _l_back->prev->_data );
				_alloc.deallocate( _l_back->prev->_data, 1 );
				_l_back->prev = _l_back->prev->prev;
				delete tmp;
				--_sz;
			}
		}
		void		push_front( const T& value ) {
			Node *_new_node = new Node;

			_new_node->_data = _alloc.allocate( 1 );
			_alloc.construct( _new_node->_data, value );
			_new_node->next = _l_front->next;
			_new_node->prev = _l_front;

			if ( !_sz ) {
				_l_back->prev = _new_node;
			} else {
				_l_front->next->prev = _new_node;
			}
			_l_front->next = _new_node;
			++_sz;
		}
		void		pop_front() {
			if ( _sz ) {
				Node *tmp = _l_front->next;

				_l_front->next->next->prev = _l_front;
				_alloc.destroy( _l_front->next->_data );
				_alloc.deallocate( _l_front->next->_data, 1 );
				_l_front->next = _l_front->next->next;
				delete tmp;
				--_sz;
			}
		}
		void		resize( size_type count, T value = T() ) {
			if ( count < _sz) {
				Node *tmp = _l_front->next;
				for (size_type i = 0; i < count; ++i, tmp = tmp->next);
				erase(iterator(tmp), end());
				return;
			}
			for (size_type i = _sz; i < count; ++i) {
				push_back(value);
			}
		}

		void		swap( list& other ) {
			myswap(this->_alloc, other._alloc);
			myswap(this->_l_front, other._l_front);
			myswap(this->_l_back, other._l_back);
			myswap(this->_sz, other._sz);
		}

		// ******************************		Modifiers		****************************** //


		// ******************************		Operations		****************************** //

		void	merge( list& other ) { this->merge(other, comp_merge); }
		template <class Compare>
		void	merge( list& other, Compare comp ) {
			other._l_front = other._l_front->next;
			Node *thisTmp = this->_l_front->next;

			while ( thisTmp != _l_back ) {
				if (comp(*thisTmp->_data, *other._l_front->_data)
					&& other._l_front != other._l_back) {
					Node *otherTmp = other._l_front->next;
					push_prev(thisTmp, other._l_front);
					other._l_front = otherTmp;
				} else {
					thisTmp = thisTmp->next;
				}
			}
			thisTmp = _l_back->prev;
			while ( other._l_front != other._l_back ) {
				Node *otherTmp = other._l_front->next;
				push_next(thisTmp, other._l_front);
				thisTmp = other._l_front;
				other._l_front = otherTmp;
			}
			clearWithoutFree(other);
		}

		void splice( const_iterator pos, list& other ) {
			if ( other._sz ) {
				Node *posNode = pos._i;
				posNode->prev->next = other._l_front->next;
				other._l_front->next->prev = posNode->prev;
				other._l_back->prev->next = posNode;
				posNode->prev = other._l_back->prev;
				this->_sz += other._sz;
				clearWithoutFree(other);
			}
		}

		void splice( const_iterator pos, list& other, const_iterator it ) {
			if ( other._sz ) {
				Node *moveNode = it._i;
				moveNode->prev->next = moveNode->next;
				moveNode->prev = moveNode->prev;

				push_prev(pos._i, moveNode);

				--other._sz;
			}
		}

//		void splice( const_iterator pos, list& other,
//					 const_iterator first, const_iterator last);
		// ******************************		Operations		****************************** //

	private:
		Allocator	_alloc;
		Node		*_l_front;
		Node		*_l_back;
		size_type	_sz;

		void push_prev(Node *currentNode, Node *pushNode) {
			currentNode->prev->next = pushNode;
			pushNode->prev = currentNode->prev;
			pushNode->next = currentNode;
			currentNode->prev = pushNode;
			++_sz;
		}

		void push_next(Node *currentNode, Node *pushNode) {
			currentNode->next->prev = pushNode;
			pushNode->prev = currentNode;
			pushNode->next = currentNode->next;
			currentNode->next = pushNode;
			++_sz;
		}

		static bool comp_merge(T a, T b) { return (a > b); }

		static void clearWithoutFree( list& l ) {
			l._sz = 0;
			l._l_front->next = l._l_back;
			l._l_back->prev = l._l_front;
		}

		template<typename U>
		void		myswap(U& a, U& b) {
			U tmp = a;
			a = b;
			b = tmp;
		}
	};

}

// ******************************		Non-member functions		****************************** //

template< class T, class Alloc >
void swap( ft::list<T,Alloc>& lhs,
		   ft::list<T,Alloc>& rhs ) {
	lhs.swap(rhs);
}
#include "ListIterator.h"
