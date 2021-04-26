//Объявление функций и глобальных переменных #pragma once
#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack1
{
    T *arr;
    int size;

public:
    Stack1();
    Stack1(int count); // конструктор инициализации
    Stack1(const Stack1& other);  // конструктор копирования
    Stack1(Stack1&& other); // конструктор перемещения
    ~Stack1(); // деструктор
    
    //Обязательные функции-члены
    int GetSize() const; // вернуть длину стека
    void Push(const T& element); // функции вставки и удаления элемента
    T Pop(); // удалить элемент из стека
    T Peek(); // просмотреть элементы стека

    Stack1 &operator=(const Stack1& other); // оператор присваивания копий
    Stack1 &operator=(Stack1&& other); // оператор присваивания перемещения
    void printArray(); // вывод массива

};



