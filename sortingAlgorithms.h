#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <vector>
#include <utility>
#include <algorithm>

/*
 * Selection Sort O(n^2)
 * Sorts vector in place.
 * */
template <typename iterator, typename Comparison>
void selectionSort(iterator first, iterator last, Comparison comparison)
{
	for (iterator i = first; i != last; i++)
	{
		iterator low = i;
		for (iterator j = i+1; j != last; j++)
		{
			if (comparison(*j, *low))
			{
				low = j;
			}
		}
		std::swap(*i, *low);
	}
}

template <typename T, typename Comparison = std::less<T>>
void selectionSort(std::vector<T>& v, Comparison comparison = Comparison() )
{
	selectionSort(v.begin(), v.end(), comparison);
}


/*
 * bubble Sort
 * Big O = 
 * */

template <typename T, typename Comparison = std::less<T>>
void bubbleSort(std::vector<T>& v, Comparison comparison = Comparison())
{
	bubbleSort(v.begin(), v.end(), comparison);
}

/*
 * Insertion Sort
 * Big O = 
 * */


/*
 * Merge Sort
 * Big O = 
 * */


/*
 * Heap Sort
 * Big O = 
 * */

#endif
