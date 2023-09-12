#include <iostream>
#include <fstream>
#include <conio.h>
#include "Functions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int SIZE=0, top = -1;

	int* arr = new int[SIZE];
	while (true)
	{
		switch (menu())
		{
		case 1: 
		{
			
			int value;
			cout << "Введите значение: ";
			cin >> value;
				Push(arr, top, SIZE, value);

		}
		break;
		case 2: 
		{
			if (!IsEmpty(arr, top))
			{
				cout << "СТЕК: " << endl;
				Stack_out(arr, top);
			}
			else 
			{ 
				cout << "Стек пуст!" << endl;
			}

		}break;
		case 3:
		{

			if (IsEmpty(arr, top))
			{
				cout << "Стек пуст!" << endl;

			}
			else
			{
				cout << "Стек до удаления: " << endl;
				Stack_out(arr, top);
				cout << "\nЗначение удаляемого элемента: " << Pop(arr, top, SIZE) << endl;
				cout << "\nСтек после удаления: " << endl;
				Stack_out(arr, top);
			}	

		}
		break;
		case 4:
		{
			if (!IsEmpty(arr, top))
			{
				cout << "Значение верхнего элемента стека: " << Peek(arr, top) << endl;

			}
			else
			{
				cout << "Стек пуст!" << endl;
			}
			
		}break;
		case 5:
		{
			if (!IsEmpty(arr, top))
			{
				cout << "Стек не пуст." << endl;

			}
			else
			{
				cout << "Стек пуст." << endl;
			}
		}
		break;
		case 6:
		{
			Clear(arr, top, SIZE);
			cout << "Стек очищен." << endl;
		}
		break;
		case 7:
		{
			if (IsEmpty(arr, top))
			{
				cout << "Стек пуст. Количество элементов стека: 0" << endl;

			}
			else
			{
				cout << "Количество элементов стека: " << Count(arr, top) << endl;
			}
		
		}
		break;
		case 0: return 0;
		default:"Введите правильно!";
		}
		cout << endl;
		puts("Нажмите любую кнопку для продолжения");
		_getch();
		system("cls");
	}
	

	cout << endl;
	delete[] arr; 
	system("pause");
	return 0;
	
}