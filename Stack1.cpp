#include "Stack1.h"
// конструктор инициализации
template<typename T>
Stack1<T>::Stack1()
{
	this->size=0;
	this->arr=nullptr;
}
// конструктор копирования
template<typename T>
Stack1<T>::Stack1(const Stack1& other)
{
	arr = new int[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
	  arr[i] = other.arr[i];
}
// конструктор перемещения
template<typename T>
Stack1<T>::Stack1(Stack1&& other)
{
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}
// деструктор
template<typename T>
Stack1<T>::~Stack1()
{
	delete[] arr;
}
// вернуть длину стека
template<typename T>
int Stack1<T>::GetSize() const
{
	return size;
}
// функции вставки и удаления элемента
// вставить элемент
template<typename T>
void Stack1<T>::Push(const T& element) 
{
int* arr1 = new int[size + 1];

	for (int before = 0; before < size; ++before) arr1[before] = arr[before];

	arr1[size] = element;

	for (int after = size; after < size; ++after) arr1[after + 1] = arr[after];

	delete[] arr;
	arr = arr1;
	++size;
}
// удалить элемент
template <typename T>
T Stack1<T>::Pop()
{
	if (size > 0)
	{
		--size;
		int* arr1 = new int[size];
		for (int i = 0; i < size; ++i)
			arr1[i] = arr[i];

		delete[] arr;
		arr = arr1;
     return arr[size];
	}
	else 
	{
		cout << "element not found";
		arr = 0;
		return arr[size];
    }
	
}
// просмотреть элементы стека
template<typename T>
T Stack1<T>::Peek() 
{	
    return arr[size - 1];
}
// оператор присваивания копий
template<typename T>
Stack1<T>&Stack1<T>::operator=(const Stack1& other)
{
	if (this == &other) return *this;
	delete[] arr;
	arr = new int[other.size];
	size = other.size;
	for (int i = 0; i < size; ++i)
		arr[i] = other.arr[i];
	return *this;
}
//оператор присваивания перемещения
template<typename T>
Stack1<T>&Stack1<T>::operator=(Stack1&& other)
{
	if (this == &other)  return *this;
	delete[] arr;
	arr = other.arr;
	size = other.size;
	other.arr = nullptr;
}
