#include <iostream>
#include <random>
#include <string>

#include "SortingAlgorithms.h"

template <typename T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& rhs);

template <typename T>
std::ostream& operator<<(std::ostream&, const std::list<T>&);

template <typename T>
void shuffle(std::vector<T>&);

template <typename T, size_t N>
void shuffle(std::array<T, N>& arr);

template <typename T>
void shuffle(std::list<T>&);

int main ()
{
	std::vector<int> intVec =    {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};
	std::array<int, 15> intArr =    {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};
	std::list<float> floatList = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.00009f};
	std::vector<char> charVec = {'f','s','r','u','o','a','b','d','c','x','z','u','y','t','j','k','m','n','e'};
	std::list<char> charList = {'f','s','r','u','o','a','b','d','c','x','z','u','y','t','j','k','m','n','e'};
	std::vector<std::string> stringVec = {"zaa", "zab", "zba", "zbc", "cef", "abc", "def"};
	std::list<std::string> stringList = {"zaa", "zab", "zba", "zbc", "cef", "abc", "def"};


	std::cout << "[ INT VEC ]\n";
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


	std::cout << "[ INT ARR ]\n";
	selectionSort(intArr);
	std::cout << intArr << "\n";
	shuffle(intArr);

	bubbleSort(intArr);
	std::cout << intArr << "\n";
	shuffle(intArr);

	insertionSort(intArr);
	std::cout << intArr << "\n";
	shuffle(intArr);

	mergeSort(intArr);
	std::cout << intArr << "\n";
	shuffle(intArr);


	std::cout << "[ FLOAT LIST ]\n";
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


	std::cout << "[ CHAR VEC ]\n";
	selectionSort(charVec);
	std::cout << charVec << "\n";
	shuffle(charVec);

	bubbleSort(charVec);
	std::cout << charVec << "\n";
	shuffle(charVec);

	insertionSort(charVec);
	std::cout << charVec << "\n";
	shuffle(charVec);

	mergeSort(charVec);
	std::cout << charVec << "\n";
	shuffle(charVec);


	std::cout << "[ CHAR LIST ]\n";
	selectionSort(charList, std::greater<decltype(floatList)::value_type>());
	std::cout << charList << "\n";
	shuffle(charList);

	bubbleSort(charList, std::greater<decltype(floatList)::value_type>());
	std::cout << charList << "\n";
	shuffle(charList);

	insertionSort(charList, std::greater<decltype(floatList)::value_type>());
	std::cout << charList << "\n";
	shuffle(charList);

	mergeSort(charList, std::greater<decltype(floatList)::value_type>());
	std::cout << charList << "\n";
	shuffle(charList);

	return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& rhs)
{
	std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T>(os, " "));
	return os;
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& rhs)
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

template <typename T, size_t N>
void shuffle(std::array<T, N>& arr)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
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

