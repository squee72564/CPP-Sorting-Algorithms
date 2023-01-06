#include <iostream>
#include <random>

#include "SortingAlgorithms.h"

template <typename T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);

template <typename T>
std::ostream& operator<<(std::ostream&, const std::list<T>&);

template <typename T>
void shuffle(std::vector<T>&);

template <typename T>
void shuffle(std::list<T>&);

int main ()
{

	std::vector<int> intVec =    {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};
	std::list<float> floatList = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.00009f};
	

	selectionSort(intVec);
	std::cout << intVec << "\n";
	shuffle(intVec);

	bubbleSort(intVec);
	std::cout << intVec << "\n";
	shuffle(intVec);

	insertionSort(intVec);
	std::cout << intVec << "\n";
	shuffle(intVec);

	mergeSort(intVec);
	std::cout << intVec << "\n";
	shuffle(intVec);


	selectionSort(floatList, std::greater<decltype(floatList)::value_type>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	bubbleSort(floatList, std::greater<decltype(floatList)::value_type>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	insertionSort(floatList, std::greater<decltype(floatList)::value_type>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	mergeSort(floatList, std::greater<decltype(floatList)::value_type>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& rhs)
{
	std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T>(os, " "));
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& rhs)
{
	std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T>(os, " "));
	return os;
}

template <typename T>
void shuffle(std::vector<T>& vec)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
}

template <typename T>
void shuffle(std::list<T>& list)
{
	std::vector<T> temp;
	temp.reserve(list.size());
	std::move(list.begin(), list.end(), std::back_inserter(temp)); 

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp.begin(), temp.end(), g);

	list.clear();

	std::move(temp.begin(), temp.end(), std::back_inserter(list)); 
}

