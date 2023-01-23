#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <vector>
#include <list>
#include <array>
#include <utility>
#include <algorithm>
#include <iterator>

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

template <typename T, std::size_t N, typename Comparison = std::less<T>>
void selectionSort(std::array<T, N>& arr, Comparison comparison = Comparison() )
{
	selectionSort(arr.begin(), arr.end(), comparison);
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

template <typename T, std::size_t N, typename Comparison = std::less<T>>
void bubbleSort(std::array<T, N>& arr, Comparison comparison = Comparison() )
{
	bubbleSort(std::begin(arr), std::end(arr), comparison);
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

		while (lead != first && comparison(*lead, *follow))
		{
			std::iter_swap(lead, follow);
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

template <typename T, std::size_t N, typename Comparison = std::less<T>>
void insertionSort(std::array<T, N>& arr, Comparison comparison = Comparison() )
{
	insertionSort(arr.begin(), arr.end(), comparison);
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

template <typename iterator, typename Comparison>
void merge(iterator first, iterator mid, iterator last, Comparison& comparison)
{
	std::vector<typename std::iterator_traits<iterator>::value_type> temp;
	temp.reserve(std::distance(first,last));

	iterator left = first;
	iterator right = mid;

	while (left != mid && right != last)
	{
		if (comparison(*right, *left))
		{
			temp.emplace_back(*right++);
		}
		else
		{
			temp.emplace_back(*left++);
		}
	}

	temp.insert(temp.end(), left, mid);
	temp.insert(temp.end(), right, last);

	std::move(temp.begin(), temp.end(), first);
}

template <typename iterator, typename Comparison = std::less<typename iterator::value_type>>
void mergeSort(iterator first, iterator last, Comparison comparison = Comparison())
{
	int size = std::distance(first, last);
	
	if (size <= 1)
	{
		return;
	}

	auto mid = std::next(first, size / 2);

	mergeSort(first, mid, comparison);
	mergeSort(mid, last, comparison);
	
	merge(first, mid, last, comparison);
}

template <typename T, typename Comparison = std::less<T>>
void mergeSort(std::vector<T>& vec, Comparison comparison = Comparison() )
{
	mergeSort(vec.begin(), vec.end(), comparison);
}

template <typename T, std::size_t N, typename Comparison = std::less<T>>
void mergeSort(std::array<T, N>& arr, Comparison comparison = Comparison() )
{
	mergeSort(arr.begin(), arr.end(), comparison);
}

template <typename T, typename Comparison = std::less<T>>
void mergeSort(std::list<T>& list, Comparison comparison = Comparison() )
{
	mergeSort(list.begin(), list.end(), comparison);
}

/*
 * Heap Sort
 * Big O = 
 * */

#endif