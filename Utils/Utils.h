//
// Created by Makhmud Ego on 10.06.2021.
//

#pragma once

namespace Utils {
	template< bool B, class T = void >
	struct enable_if { };

	template< class T >
	struct enable_if< true, T > {
		typedef T type;
	};

	enum Comparison {
		Less,
		Equal,
	};

	template<class InputIt1, class InputIt2>
	bool cmp(InputIt1 first1, InputIt1 last1,
			 InputIt2 first2, InputIt2 last2,
			 Comparison cmp)
	{
		for ( ; (first1 != last1) && (first2 != last2); first1++, first2++ ) {
			switch (cmp) {
				case Less:
					if (*first1 != *first2) return ( *first1 > *first2 );
					break;
				case Equal:
					if (*first1 != *first2) return false;
					break;
			}
		}
		switch (cmp) {
			case Less:
				return (first1 != last1);
			case Equal:
				return (first1 == last2 && first2 == last2);
		}
	}
}