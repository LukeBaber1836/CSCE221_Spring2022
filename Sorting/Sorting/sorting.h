#pragma once
#include <functional> // std::less
#include <iterator>

// This is C++ magic which will allows our function
// to default to using a < b if the comparator arg
// is unspecified. It uses defines std::less<T>
// for the iterator's value_type.
//
// For example: if you have a vector<float>, the 
// iterator's value type will be float. std::less 
// will select the < for sorting floats as the 
// default comparator.

namespace sort {
	template<typename RandomIter>
	using less_for_iter = std::less<typename std::iterator_traits<RandomIter>::value_type>;

	/* Efficiently swap two items - use this to implement your sorts */
	template<typename T>
	void swap(T &a, T &b) noexcept {

	    T temp = std::move(a);
	    // Swap positions of 'a' and 'b'
	    a = std::move(b);
	    b = std::move(temp);
    }

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void bubble(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {
		using _it = std::iterator_traits<RandomIter>;

        for (RandomIter i = begin; i < end; ++i) {
            for (RandomIter j = begin; j < i; ++j) {
                if (comp(*i, *j) == true) {
                    swap(*i, *j);
                }
            }
        }
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void insertion(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {

        for (RandomIter i = begin; i < end; i++) {
            for (RandomIter j = i; j > begin; j--) {
                if (comp(*j, *(j - 1)) == true) {
                    swap(*j, *(j - 1));
                }
                else{ break;}
            }
        }
	}

	template<typename RandomIter, typename Comparator = less_for_iter<RandomIter>>
	void selection(RandomIter begin, RandomIter end, Comparator comp = Comparator{}) {

        for (RandomIter i = begin; i < end; i++) {
            RandomIter smallest = i;
            for (RandomIter j = i + 1; j < end; j++) {
                if (comp(*j, *smallest) == true) {
                    smallest = j;
                }
            }
            swap(*i, *smallest);
        }
	}
}
