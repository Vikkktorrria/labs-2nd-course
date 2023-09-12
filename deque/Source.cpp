#include <iostream>
#include <fstream>
#include <conio.h>
#include "Functions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int SIZE, head, tail;
	bool click_check = false;
	cout << "Введите количество элементов дека: ";
	cin >> SIZE;
	head = SIZE / 2;
	tail = SIZE / 2;
	int* arr = new int[SIZE];
	while (true)
	{
		switch (menu())
		{
		case 1: 
		{
			if (click_check == false)
			{
				int value;
				for (int i = 0; i < SIZE / 2; i++)
				{
					cout << "Введите " << i + 1 << "-й элемент головы: ";
					cin >> value;
					pushHead(arr, SIZE, head, tail, value);
				}
				cout << endl;
				for (int i = 0; i < SIZE / 2; i++)
				{
					cout << "Введите " << i + 1 << "-й элемент хвоста: ";
					cin >> value;
					pushTail(arr, SIZE, head, tail, value);
				}

				click_check = true;
			}
			else
			{
				cout << "Дек уже заполнен!\n";
			}
		}
		break;
		case 2: 
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "ДЕК: " << endl;
				dek_out(arr, SIZE, head, tail);
			}
			else 
			{ 
				cout << "Дек пуст!" << endl;
			}

		}break;
		case 3:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "Дек пуст!" << endl;

			}
			else
			{
				cout << "Дек до удаления: " << endl;
				dek_out(arr, SIZE, head, tail);
				cout << "\nЗначение удаляемого элемента: " << popHead(arr, head, tail, SIZE) << endl;
				cout << "\nДек после удаления: " << endl;
				dek_out(arr, SIZE, head, tail);
			}	

		}
		break;
		case 4:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "Дек пуст!" << endl;

			}
			else
			{
				cout << "Дек до удаления: " << endl;
				dek_out(arr, SIZE, head, tail);
				cout << "\nЗначение удаляемого элемента: " << popTail(arr, head, tail, SIZE) << endl;
				cout << "\nДек после удаления: " << endl;
				dek_out(arr, SIZE, head, tail);
			}

		}
		break;
		case 5:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Значение первого элемента дека: " << peekHead(arr, head, tail) << endl;

			}
			else
			{
				cout << "Дек пуст!" << endl;
			}

		}break;
		case 6:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Значение последнего элемента дека: " << peekTail(arr, head, tail) << endl;

			}
			else
			{
				cout << "Дек пуст!" << endl;
			}

		}break;
		case 7:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Дек не пуст." << endl;

			}
			else
			{
				cout << "Дек пуст." << endl;
			}
		}
		break;
		case 8:
		{
			clear(arr, head, tail, SIZE);
			cout << "Дек очищен." << endl;
			click_check = false;
		}
		break;
		case 9:
		{
			if (isEmpty(arr, head, tail))
			{
				cout << "Дек пуст. Количество элементов дека: 0" << endl;

			}
			else
			{
				cout << "Количество элементов дека: " << count(arr, head, tail) << endl;
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