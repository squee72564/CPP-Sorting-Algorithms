#include <iostream>
#include <random>
#include <iterator>
#include "SortingAlgorithms.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& rhs);

template <typename T>
void shuffleVector(std::vector<T>& v);

int main () {

	std::vector<int> intVec = {6,5,4,3,2,1,0};
	std::vector<float> floatVec = {19.23f,18.523f,17.23f,15.44f,23.2f,41.00001f,41.000099999999999999999f};
	
	selectionSort(intVec);
	selectionSort(floatVec);
	std::cout << intVec << "\n";
	std::cout << floatVec << "\n";
	
	shuffleVector(intVec);
	shuffleVector(floatVec);

	selectionSort(intVec, std::greater<decltype(intVec)::value_type>());
	std::cout << intVec << "\n";

	return 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& rhs)
{
	std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T>(os, " "));
	return os;
}

template <typename T>
void shuffleVector(std::vector<T>& v)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
}