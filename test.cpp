#include <iostream>
#include <random>
#include <string>

#include "SortingAlgorithms.h"

void testIntContainers();

void testFloatContainers();

void testCharContainers();

void testStringContainers();

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
	testIntContainers();
	testFloatContainers();
	testCharContainers();
	testStringContainers();

	return 0;
}

void testIntContainers()
{
	std::vector<int> intVec = {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};
	std::array<int, 15> intArr = {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};
	std::list<int> intList = {6,5,4,3,2,1,0,7,8,9,10,11,12,13,14};


	std::cout << "[ INT VEC <]\n";
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


	std::cout << "\n[ INT ARR <]\n";
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

	std::cout << "\n[ INT LIST >]\n";
	selectionSort(intList, std::greater<int>());
	std::cout << intList << "\n";
	shuffle(intList);

	bubbleSort(intList, std::greater<int>());
	std::cout << intList << "\n";
	shuffle(intList);

	insertionSort(intList, std::greater<int>());
	std::cout << intList << "\n";
	shuffle(intList);

	mergeSort(intList, std::greater<int>());
	std::cout << intList << "\n";
	shuffle(intList);
}

void testFloatContainers()
{
	std::vector<float> floatVec = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.00009f};
	std::array<float, 7> floatArr = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.00009f};;
	std::list<float> floatList = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.00009f};

	std::cout << "\n[ FLOAT VEC <]\n";
	selectionSort(floatVec);
	std::cout << floatVec << "\n";
	shuffle(floatVec);

	bubbleSort(floatVec);
	std::cout << floatVec << "\n";
	shuffle(floatVec);

	insertionSort(floatVec);
	std::cout << floatVec << "\n";
	shuffle(floatVec);

	mergeSort(floatVec);
	std::cout << floatVec << "\n";
	shuffle(floatVec);


	std::cout << "\n[ FLOAT ARR <]\n";
	selectionSort(floatArr);
	std::cout << floatArr << "\n";
	shuffle(floatArr);

	bubbleSort(floatArr);
	std::cout << floatArr << "\n";
	shuffle(floatArr);

	insertionSort(floatArr);
	std::cout << floatArr << "\n";
	shuffle(floatArr);

	mergeSort(floatArr);
	std::cout << floatArr << "\n";
	shuffle(floatArr);


	std::cout << "\n[ FLOAT LIST >]\n";
	selectionSort(floatList, std::greater<float>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	bubbleSort(floatList, std::greater<float>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	insertionSort(floatList, std::greater<float>());
	std::cout << floatList << "\n";
	shuffle(floatList);

	mergeSort(floatList, std::greater<float>());
	std::cout << floatList << "\n";
	shuffle(floatList);
}

void testCharContainers()
{
	std::vector<char> charVec = {'f','s','r','u','o','a','b','d','c','x','z','u','y','t','j','k','m','n','e'};
	std::array<char, 19> charArr = {'f','s','r','u','o','a','b','d','c','x','z','u','y','t','j','k','m','n','e'};
	std::list<char> charList = {'f','s','r','u','o','a','b','d','c','x','z','u','y','t','j','k','m','n','e'};

	std::cout << "\n[ CHAR VEC <]\n";
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

	std::cout << "\n[ CHAR ARR <]\n";
	selectionSort(charArr);
	std::cout << charArr << "\n";
	shuffle(charArr);

	bubbleSort(charArr);
	std::cout << charArr << "\n";
	shuffle(charArr);

	insertionSort(charArr);
	std::cout << charArr << "\n";
	shuffle(charArr);

	mergeSort(charArr);
	std::cout << charArr << "\n";
	shuffle(charArr);

	std::cout << "\n[ CHAR LIST >]\n";
	selectionSort(charList, std::greater<char>());
	std::cout << charList << "\n";
	shuffle(charList);

	bubbleSort(charList, std::greater<char>());
	std::cout << charList << "\n";
	shuffle(charList);

	insertionSort(charList, std::greater<char>());
	std::cout << charList << "\n";
	shuffle(charList);

	mergeSort(charList, std::greater<char>());
	std::cout << charList << "\n";
	shuffle(charList);
}

void testStringContainers()
{
	std::vector<std::string> stringVec = {"zaa", "zab", "zba", "zbc", "cef", "abc", "def"};
	std::array<std::string, 7> stringArr = {"zaa", "zab", "zba", "zbc", "cef", "abc", "def"};
	std::list<std::string> stringList = {"zaa", "zab", "zba", "zbc", "cef", "abc", "def"};

	std::cout << "\n[ STR VEC <]\n";
	selectionSort(stringVec);
	std::cout << stringVec << "\n";
	shuffle(stringVec);

	bubbleSort(stringVec);
	std::cout << stringVec << "\n";
	shuffle(stringVec);

	insertionSort(stringVec);
	std::cout << stringVec << "\n";
	shuffle(stringVec);

	mergeSort(stringVec);
	std::cout << stringVec << "\n";
	shuffle(stringVec);

	
	std::cout << "\n[ STR ARR <]\n";
	selectionSort(stringArr);
	std::cout << stringArr << "\n";
	shuffle(stringArr);

	bubbleSort(stringArr);
	std::cout << stringArr << "\n";
	shuffle(stringArr);

	insertionSort(stringArr);
	std::cout << stringArr << "\n";
	shuffle(stringArr);

	mergeSort(stringArr);
	std::cout << stringArr << "\n";
	shuffle(stringArr);


	std::cout << "\n[ STR LIST >]\n";
	selectionSort(stringList, std::greater<std::string>());
	std::cout << stringList << "\n";
	shuffle(stringList);

	bubbleSort(stringList, std::greater<std::string>());
	std::cout << stringList << "\n";
	shuffle(stringList);

	insertionSort(stringList, std::greater<std::string>());
	std::cout << stringList << "\n";
	shuffle(stringList);

	mergeSort(stringList, std::greater<std::string>());
	std::cout << stringList << "\n";
	shuffle(stringList);
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