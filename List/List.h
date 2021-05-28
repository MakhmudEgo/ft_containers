//
// Created by Mahmud Jego on 5/15/21.
//

#pragma once

#include <memory>
#include "ListIterator.h"
#include <iostream>
#include <stdexcept>
#include <limits>

namespace ft {
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
		typedef ConstListIterator<T, Node>				const_iterator;
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

		/*template< class InputIt >
		list( InputIt first, InputIt last,
			  const Allocator& alloc = Allocator() );*/

		virtual ~list() {
			clear();
			_alloc.destroy( _l_front->_data );
			_alloc.deallocate( _l_front->_data, 1 );
			delete _l_front;
		}

		list ( const list& other ) {
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

		void	clear() {
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
		void	push_back( const T& value ) {
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
		void	pop_back() {
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
		void	push_front( const T& value ) {
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
		void	pop_front() {
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

		// ******************************		Modifiers		****************************** //

	private:
		Allocator	_alloc;
		Node		*_l_front;
		Node		*_l_back;
		size_type	_sz;
	};

}
