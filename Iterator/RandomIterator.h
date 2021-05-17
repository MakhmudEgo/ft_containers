//
// Created by Mahmud Jego on 5/7/21.
//

#pragma once

namespace ft {
	template<class T>
	class RandomIterator {
	public:

		RandomIterator(T *i) : _i(i) {}

		RandomIterator(const RandomIterator<T> &i) : _i(i._i) {}

		RandomIterator(std::__1::__wrap_iter<T *> i) : _i(&(*i)) {}

	protected:
		T *_i;
	};

	template<class T>
	class VectorIterator : public RandomIterator<T> {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef VectorIterator iterator_type;


		VectorIterator(T *i) : RandomIterator<T>(i) {}

		VectorIterator(const RandomIterator<T> &i) : RandomIterator<T>(i) {}

		VectorIterator(std::__1::__wrap_iter<T *> i) : RandomIterator<T>(i) {}

		reference operator*() { return *this->_i; }

		// ***** post inc ***** //
		iterator_type operator++(int) {
			return iterator_type(this->_i++);
		}

		// ***** pre inc ***** //
		iterator_type &operator++() {
			++this->_i;
			return *this;
		}

		// ***** post inc ***** //
		iterator_type operator--(int) {
			return iterator_type(this->_i--);
		}

		// ***** post dec ***** //
		iterator_type &operator--() {
			--this->_i;
			return *this;
		}

		// ***** [] ***** //
		reference operator[](int n) { return this->_i[n]; }


		// ***** + && - ***** //
		iterator_type operator+(int n) { return iterator_type(this->_i + n); }

		iterator_type operator-(int n) { return iterator_type(this->_i - n); }

		difference_type operator+(const iterator_type &other) { return this->_i + other._i; }

		difference_type operator-(const iterator_type &other) { return this->_i - other._i; }

		// ***** += && -= ***** //
		iterator_type operator+=(int n) { return this->_i += n; }

		iterator_type operator-=(int n) { return this->_i -= n; }

		// ***** > && < ***** //
		bool operator>(const iterator_type &other) { return this->_i > other._i; }

		bool operator<(const iterator_type &other) { return this->_i < other._i; }

		// ***** >= && <= ***** //
		bool operator>=(const iterator_type &other) { return this->_i >= other._i; }

		bool operator<=(const iterator_type &other) { return this->_i <= other._i; }

		// ***** == && != ***** //
		bool operator==(const VectorIterator<T> &other) {
			return this->_i == other._i;
		}

		bool operator!=(const iterator_type &other) { return this->_i != other._i; }

		// ***** utils ***** //
		iterator_type base() { return *this; }
	};

	template<class T>
	class ConstVectorIterator : public VectorIterator<T> {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T &const_reference;

		ConstVectorIterator(T *i) : VectorIterator<T>(i) {}

		ConstVectorIterator(std::__1::__wrap_iter<T *> i) : VectorIterator<T>(i) {}

		ConstVectorIterator(const RandomIterator<T> &i) : VectorIterator<T>(i) {}

		const_reference operator*() { return *this->_i; }

		const_reference operator[](int n) const { return this->_i[n]; }

	};

	template<class T>
	class ReverseVectorIterator : public RandomIterator<T> {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef ReverseVectorIterator iterator_type;


		ReverseVectorIterator(T *i) : RandomIterator<T>(i) {}

		ReverseVectorIterator(const RandomIterator<T> &i) : RandomIterator<T>(i) {}

		ReverseVectorIterator(std::__1::__wrap_iter<T *> i) : RandomIterator<T>(i) {}

		reference operator*() { return *this->_i; }

		// ***** post inc ***** //
		iterator_type operator++(int) {
			return iterator_type(this->_i--);
		}

		// ***** pre inc ***** //
		iterator_type &operator++() {
			--this->_i;
			return *this;
		}

		// ***** post inc ***** //
		iterator_type operator--(int) {
			return iterator_type(this->_i++);
		}

		// ***** post dec ***** //
		iterator_type &operator--() {
			++this->_i;
			return *this;
		}

		// ***** [] ***** //
		reference operator[](int n) { return this->_i[-n]; }


		// ***** + && - ***** //
		iterator_type operator+(int n) { return iterator_type(this->_i - n); }

		iterator_type operator-(int n) { return iterator_type(this->_i + n); }

		difference_type operator+(const iterator_type &other) { return this->_i - other._i; }

		difference_type operator-(const iterator_type &other) { return this->_i + other._i; }

		// ***** += && -= ***** //
		iterator_type operator+=(int n) { return this->_i -= n; }

		iterator_type operator-=(int n) { return this->_i += n; }

		// ***** > && < ***** //
		bool operator>(const iterator_type &other) { return this->_i < other._i; }

		bool operator<(const iterator_type &other) { return this->_i > other._i; }

		// ***** >= && <= ***** //
		bool operator>=(const iterator_type &other) { return this->_i <= other._i; }

		bool operator<=(const iterator_type &other) { return this->_i >= other._i; }

		// ***** == && != ***** //
		bool operator==(const ReverseVectorIterator<T> &other) {
			return this->_i == other._i;
		}

		bool operator!=(const iterator_type &other) { return this->_i != other._i; }

		// ***** utils ***** //
		iterator_type base() { return *this; }
	};

	template<class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T> {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T &const_reference;

		ConstReverseVectorIterator(T *i) : ReverseVectorIterator<T>(i) {}

		ConstReverseVectorIterator(std::__1::__wrap_iter<T *> i) : ReverseVectorIterator<T>(i) {}

		ConstReverseVectorIterator(const RandomIterator<T> &i) : ReverseVectorIterator<T>(i) {}

		const_reference operator*() { return *this->_i; }

		const_reference operator[](int n) const { return this->_i[n]; }

	};

}