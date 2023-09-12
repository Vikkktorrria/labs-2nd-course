#include <iostream>
#include <fstream>
#include <conio.h>
#include "Functions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int SIZE=10, head = 0, tail = 0;
	bool click_check = false;
	cout << "Введите количество элементов дека: ";
	cin >> SIZE;
	int* arr = new int[SIZE];
	while (true)
	{
		switch (menu())
		{
		case 1: 
		{
			if (click_check==false)
			{
				int value;
				for (int i = 0; i < SIZE/2; i++)
				{
					cout << "Введите " << i+1 << "-й элемент головы: ";
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

				/*cout << "Введите элемент, который хотите добавить в голову: ";
				cin >> value;
				pushHead(arr, head, tail, value);
				int value1;
				cout << "Введите элемент, который хотите добавить в хвост: ";
				cin >> value1;
				pushTail(arr, head, tail, value);*/
				/*int value;
				cout << "Введите количество элементов, которое хотите добавить: ";
				cin >> SIZE;
				cout << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << "Введите элемент № " << i+1 << ": ";
					cin >> value;
					еnqueue(arr, head, tail, value);
				}*/
				click_check = true;
			}
			else
			{
				cout << "Массив уже заполнен!\n";
			}

		}
		break;
		case 2: 
		{
			/*if (!isEmpty(arr, head, tail))
			{*/
				cout << "ОЧЕРЕДЬ: " << endl;
				queue_out(arr, SIZE, head, tail);
		/*	}
			else 
			{ 
				cout << "Очередь пуста!" << endl;
			}*/

		}break;
		case 3:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "Очередь пуста!" << endl;

			}
			else
			{
				cout << "Очередь до удаления: " << endl;
				queue_out(arr, SIZE, head, tail);
				cout << "\nЗначение удаляемого элемента: " << popHead(arr, head, tail, SIZE) << endl;
				cout << "\nОчередь после удаления: " << endl;
				queue_out(arr, SIZE, head, tail);
			}	

		}
		break;
		case 4:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "Очередь пуста!" << endl;

			}
			else
			{
				cout << "Очередь до удаления: " << endl;
				queue_out(arr, SIZE, head, tail);
				cout << "\nЗначение удаляемого элемента: " << popTail(arr, head, tail, SIZE) << endl;
				cout << "\nОчередь после удаления: " << endl;
				queue_out(arr, SIZE, head, tail);
			}

		}
		break;
		case 5:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Значение первого элемента очереди: " << peekHead(arr, head, tail) << endl;

			}
			else
			{
				cout << "Очередь пуста!" << endl;
			}

		}break;
		case 6:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Значение последнего элемента очереди: " << peekTail(arr, head, tail) << endl;

			}
			else
			{
				cout << "Очередь пуста!" << endl;
			}

		}break;
		case 7:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "Очередь не пуста." << endl;

			}
			else
			{
				cout << "Очередь пуста." << endl;
			}
		}
		break;
		case 8:
		{
			clear(arr, SIZE, head, tail);
			cout << "Очередь очищена." << endl;
			click_check = false;
		}
		break;
		case 9:
		{
			if (isEmpty(arr, head, tail))
			{
				cout << "Очередь пуста. Количество элементов очереди: 0" << endl;

			}
			else
			{
				cout << "Количество элементов очереди: " << count(arr, SIZE, head) << endl;
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