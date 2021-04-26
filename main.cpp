#include "Stack1.h"
#include "Stack2.h"
#include "Stack1.cpp"
#include "VivodArray.cpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int arr, element;
	int n,num =0;
	int n1=-1;
	int i=1;
	do
	{ 
		cout << "Menu:\n";
		cout << "1. Stack1\n";
		cout << "2. Stack2\n";
		cin >> n;
		if (n == 1)
		{
			cout << "Stack length.\n";
			cout << "Length = ";
			cin >> arr;
			Stack1<int> s;
			cout << "Add Elements:\n";
			do
			{
				cout << i << ".Element = ";
				cin >> element;
				s.Push(element);
				i++;
			} while ((s.GetSize()) < arr);
			n = 0;
			do
			{
				cout << "\nCommands:\n";
				cout << "1. Pop - delete\n";
				cout << "2. Peek - show\n";
				cout << "3. Push - insert\n";
				cout << "4. GetSize - show size\n";
				cout << "5. Return - go to Menu\n";
				cout << "6. End - exit\n";
				cin >> n;
				if (n == 1) {
					s.Pop();
					cout << endl << "Stack(pop) = ";
				}
				else if (n == 2) {
					s.Peek();
					cout << endl << "Stack(peek) = ";
				}
				else if (n == 3) {
					cout << "Element insert = ";
					cin >> n1;
					s.Push(n1);
					cout << endl << "Stack(push) = ";
				}
				else if (n == 4) {
					cout << s.GetSize();
					cout << endl << "Stack(getsize) = ";
				}
				else if (n == 5) {
					break;
				}
				else if (n == 6) {
					exit(0);
				}
				s.printArray();
			} while (n);
		}
		if (n == 2)
		{
			cout << "Stack length: ---" << endl;
			Stack2<int> s1;
			cout << "Add Elements:\n";
			do
			{
				cout << i << ".Element = ";
				cin >> element;
				s1.Push(element);
				i++;
			} while ((s1.GetSize()) < arr);
			n = 0;
			cout << "\nStack = " << s1;

			do
			{
				cout << "\nCommands:\n";
				cout << "1. Pop - delete\n";
				cout << "2. Peek - show\n";
				cout << "3. Push - insert\n";
				cout << "4. GetSize - show size\n";
				cout << "5. Return - go to Menu\n";
				cout << "6. End - exit\n";
				cin >> n;
				if (n == 1) {
					s1.Pop();
					cout << endl << "Stack(pop) = ";
				}
				else if (n == 2) {
					s1.Peek();
					cout << endl << "Stack(peek) = ";
				}
				else if (n == 3) {
					cout << "Element insert = ";
					cin >> n1;
					s1.Push(n1);
					cout << endl << "Stack(push) = ";
				}
				else if (n == 4) {
					cout << s1.GetSize();
					cout << endl << "Stack(getsize) = ";
				}
				else if (n == 5) {
					break;
				}
				else if (n == 6) {
					exit(0);
				}
			} while (n);
		}
		cout << "Do you want to continue? Y/N\n";
		cout << "1. YES\n";
		cout << "2. NO\n";
		cin >> num; i = 1;
		system("pause");
	} while (num == 1);
}
