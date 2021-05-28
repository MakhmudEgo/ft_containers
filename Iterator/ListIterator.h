//
// Created by Mahmud Jego on 5/17/21.
//

#pragma once

#include "Iterator.h"

namespace ft {

	template< class T, class Node >
	class ListIterator : public Iterator< Node > {
	public:
		typedef					T value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

		ListIterator( Node *node )
				: Iterator< Node >( node ) {}
		ListIterator( const ListIterator< T, Node > &other )
				: Iterator< Node >( other ) {}

		reference		operator*() { return *this->_i->_data; }
		const_reference	operator*() const { return *this->_i->_data; }

		// ***** post inc ***** //
		ListIterator	operator++( int ) {
			ListIterator< T, Node > res( this->_i );
			this->_i = this->_i->next;
			return res;
		}

		// ***** pre inc ***** //
		ListIterator&	operator++() {
			this->_i = this->_i->next;
			return *this;
		}

		// ***** post dec ***** //
		ListIterator	operator--( int ) {
			ListIterator< T, Node > res( this->_i );
			this->_i = this->_i->prev;
			return res;
		}

		// ***** pre dec ***** //
		ListIterator	&operator--() {
			this->_i = this->_i->prev;
			return *this;
		}


		bool			operator==( const ListIterator< T, Node > &other ) { return this->_i.data == other._i.data; }
		bool			operator!=(const ListIterator &other) { return this->_i != other._i; }
	};

	template< class T, class Node >
	class ConstListIterator : public ListIterator< T, Node > {
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

		ConstListIterator( Node *node )
				: Iterator< Node >( node ) {}
		ConstListIterator( const ConstListIterator< T, Node > &other )
				: Iterator< Node >( other ) {}

		const_reference	operator*() { return *this->_i; }
	};

}