#pragma once
#include "StackBase.h"
#include "UnidirCyclicList.h"
#include <iostream>
; using namespace std;

template <typename T>
class Stack2 : public StackBase<T>
{
private:
	UnidirCyclicList<T>* arr;
	int count;
public:
	Stack2()
	{
		this->count = 0;
		arr = new UnidirCyclicList<T>();
	}
	Stack2(const Stack2& copy)
	{
		arr = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			arr->AddBack(copy.arr->ElementAt(count - i));
	}
	Stack2(Stack2&& move)
	{
		arr = move.arr;
		count = move.count;
		move.arr = nullptr;
	}
	~Stack2()
	{
		delete arr;
	}

	Stack2& operator=(const Stack2& copy)
	{
		if (this == &copy) return *this;
		delete arr;
		arr = new UnidirCyclicList<T>();
		count = copy.count;
		for (int i = 0; i < count; ++i)
			arr->AddBack(copy.arr->ElementAt(count - i));
	}
	Stack2& operator=(Stack2&& move)
	{
		if (this == &move) return *this;
		delete arr;
		arr = move.arr;
		count = move.count;
		move.arr = nullptr;
	}
	T& operator[](int index)
	{
		if (index < 0 || index > count)
			throw exception("index was outside the array boundaries");
		return arr->ElementAt(index);
	}
	friend ostream& operator<<(ostream& stream, const Stack2& arr)
	{
		for (int i = 0; i < arr.count; ++i)
			cout << arr.arr->ElementAt(i) << " ";
		return stream;
	}

	int GetSize() override
	{
		return count;
	}
	T Pop() override
	{
		T ret = arr->ElementAt(--count);
		arr->RemoveBack();
		return ret;
	}
	void Push(const T& element) override
	{
		arr->AddFront(element);
		++count;
	}
	T Peek() override
	{
		return arr->ElementAt(count - 1);
	}
};