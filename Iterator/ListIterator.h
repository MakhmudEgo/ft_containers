//
// Created by Mahmud Jego on 5/17/21.
//

#pragma once

#include "Iterator.h"
//#include "List.h"
namespace ft {

	template< class T, class Node >
	class ListIterator : public Iterator< Node > {
	public:
		friend class list<T>;
		typedef					T value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		ListIterator( Node *node )
				: Iterator< Node >( node ) {}
		ListIterator( const ListIterator< T, Node > &other )
				: Iterator< Node >( other ) {}
		ListIterator( const Iterator< Node > &other )
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


		bool			operator==( const ListIterator< T, Node > &other ) { return this->_i->_data == other._i->_data; }
		bool			operator!=(const ListIterator &other) { return this->_i->_data != other._i->_data; }
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
				: ListIterator<T, Node>( node ) {}
		ConstListIterator( const ConstListIterator< T, Node > &other )
				: ListIterator<T, Node>(other) {}
		ConstListIterator( const Iterator< Node > &other )
				: ListIterator<T, Node>(other) {}

		const_reference	operator*() const { return *this->_i->_data; }
	};

	//  ****************** Reverse ******************  //

	template< class T, class Node >
	class ReverseListIterator : public Iterator< Node > {
	public:
		friend class list<T>;
		typedef					T value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		ReverseListIterator( Node *node )
				: Iterator< Node >( node ) {}
		ReverseListIterator( const ReverseListIterator< T, Node > &other )
				: Iterator< Node >( other ) {}
		ReverseListIterator( const Iterator< Node > &other )
				: Iterator< Node >( other ) {}

		reference		operator*() { return *this->_i->_data; }
		const_reference	operator*() const { return *this->_i->_data; }

		// ***** post inc ***** //
		ReverseListIterator	operator++( int ) {
			ReverseListIterator< T, Node > res( this->_i );
			this->_i = this->_i->prev;
			return res;
		}

		// ***** pre inc ***** //
		ReverseListIterator&	operator++() {
			this->_i = this->_i->prev;
			return *this;
		}

		// ***** post dec ***** //
		ReverseListIterator	operator--( int ) {
			ReverseListIterator< T, Node > res( this->_i );
			this->_i = this->_i->next;
			return res;
		}

		// ***** pre dec ***** //
		ReverseListIterator	&operator--() {
			this->_i = this->_i->next;
			return *this;
		}

		bool			operator==( const ReverseListIterator< T, Node > &other ) { return this->_i->_data == other._i->_data; }
		bool			operator!=(const ReverseListIterator &other) { return this->_i->_data != other._i->_data; }
	};

	template< class T, class Node >
	class ConstReverseListIterator : public ReverseListIterator< T, Node > {
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

		ConstReverseListIterator( Node *node )
				: ReverseListIterator<T, Node>( node ) {}
		ConstReverseListIterator( const ConstReverseListIterator< T, Node > &other )
				: ReverseListIterator<T, Node>(other) {}
		ConstReverseListIterator( const Iterator< Node > &other )
				: ReverseListIterator<T, Node>(other) {}

		const_reference	operator*() const { return *this->_i->_data; }
	};
}
