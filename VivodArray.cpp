#include "Stack1.h"
using namespace std;

// вывод массива
template <typename T>
void Stack1<T>::printArray()
{
	int* arr1 = new int[size];
	for (int i = 0; i < size; ++i) {
		arr1[i] = arr[i];
		cout << arr1[i] << " ";
	}
}

