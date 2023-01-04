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
	if (first == last)
		return;
	
	do
	{
		iterator low = first;
		iterator current = first;
		current++;

		while (current != last)
		{
			if (comparison(*current, *low))
			{
				low = current;
			}
			current++;
		}

		std::iter_swap(first, low);
		first++;

	} while(first != last);
}

template <typename T, typename Comparison = std::less<T>>
void selectionSort(std::vector<T>& vec, Comparison comparison = Comparison() )
{
	selectionSort(vec.begin(), vec.end(), comparison);
}

template <typename T, typename Comparison = std::less<T>>
void selectionSort(std::list<T>& list, Comparison comparison = Comparison() )
{
	selectionSort(list.begin(), list.end(), comparison);
}

/*
 * bubble Sort
 * Big O = 
 * */

template <typename iterator, typename Comparison>
void bubbleSort(iterator first, iterator last, Comparison comparison)
{
	if (first == last)
		return;

	bool swapped;

	do
	{
		swapped = false;
		iterator follow = first;
		iterator lead = follow;
		lead++;

		while (lead != last)
		{
			if (comparison(*lead, *follow))
			{
				std::iter_swap(lead, follow);
				swapped = true;
			}

			follow++;
			lead++;
		}

		last--;

	} while ( first != last && swapped);
}

template <typename T, typename Comparison = std::less<T>>
void bubbleSort(std::vector<T>& vec, Comparison comparison = Comparison() )
{
	bubbleSort(vec.begin(), vec.end(), comparison);
}

template <typename T, typename Comparison = std::less<T>>
void bubbleSort(std::list<T>& list, Comparison comparison = Comparison() )
{
	bubbleSort(list.begin(), list.end(), comparison);
}


/*
 * Insertion Sort
 * Big O = 
 * */

template <typename iterator, typename Comparison>
void insertionSort(iterator first, iterator last, Comparison comparison)
{
	if (first == last)
		return;
	
	iterator i = first;
	i++;

	do
	{
		iterator lead = i;
		iterator follow = lead;
		follow--;

		while (comparison(*lead, *follow) && lead != first)
		{
			std::iter_swap(lead,follow);
			lead--;
			follow--;
		}

		i++;
	} while (i != last);
}

template <typename T, typename Comparison = std::less<T>>
void insertionSort(std::vector<T>& vec, Comparison comparison = Comparison() )
{
	insertionSort(vec.begin(), vec.end(), comparison);
}

template <typename T, typename Comparison = std::less<T>>
void insertionSort(std::list<T>& list, Comparison comparison = Comparison() )
{
	insertionSort(list.begin(), list.end(), comparison);
}

/*
 * Merge Sort
 * Big O = 
 * */


/*
 * Heap Sort
 * Big O = 
 * */

#endif