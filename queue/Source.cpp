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
	cout << "������� ���������� ��������� ����: ";
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
					cout << "������� " << i+1 << "-� ������� ������: ";
					cin >> value;
					pushHead(arr, SIZE, head, tail, value);
				}
				cout << endl;
				for (int i = 0; i < SIZE / 2; i++)
				{
					cout << "������� " << i + 1 << "-� ������� ������: ";
					cin >> value;
					pushTail(arr, SIZE, head, tail, value);
				}

				/*cout << "������� �������, ������� ������ �������� � ������: ";
				cin >> value;
				pushHead(arr, head, tail, value);
				int value1;
				cout << "������� �������, ������� ������ �������� � �����: ";
				cin >> value1;
				pushTail(arr, head, tail, value);*/
				/*int value;
				cout << "������� ���������� ���������, ������� ������ ��������: ";
				cin >> SIZE;
				cout << endl;
				for (int i = 0; i < SIZE; i++)
				{
					cout << "������� ������� � " << i+1 << ": ";
					cin >> value;
					�nqueue(arr, head, tail, value);
				}*/
				click_check = true;
			}
			else
			{
				cout << "������ ��� ��������!\n";
			}

		}
		break;
		case 2: 
		{
			/*if (!isEmpty(arr, head, tail))
			{*/
				cout << "�������: " << endl;
				queue_out(arr, SIZE, head, tail);
		/*	}
			else 
			{ 
				cout << "������� �����!" << endl;
			}*/

		}break;
		case 3:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "������� �����!" << endl;

			}
			else
			{
				cout << "������� �� ��������: " << endl;
				queue_out(arr, SIZE, head, tail);
				cout << "\n�������� ���������� ��������: " << popHead(arr, head, tail, SIZE) << endl;
				cout << "\n������� ����� ��������: " << endl;
				queue_out(arr, SIZE, head, tail);
			}	

		}
		break;
		case 4:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "������� �����!" << endl;

			}
			else
			{
				cout << "������� �� ��������: " << endl;
				queue_out(arr, SIZE, head, tail);
				cout << "\n�������� ���������� ��������: " << popTail(arr, head, tail, SIZE) << endl;
				cout << "\n������� ����� ��������: " << endl;
				queue_out(arr, SIZE, head, tail);
			}

		}
		break;
		case 5:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "�������� ������� �������� �������: " << peekHead(arr, head, tail) << endl;

			}
			else
			{
				cout << "������� �����!" << endl;
			}

		}break;
		case 6:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "�������� ���������� �������� �������: " << peekTail(arr, head, tail) << endl;

			}
			else
			{
				cout << "������� �����!" << endl;
			}

		}break;
		case 7:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "������� �� �����." << endl;

			}
			else
			{
				cout << "������� �����." << endl;
			}
		}
		break;
		case 8:
		{
			clear(arr, SIZE, head, tail);
			cout << "������� �������." << endl;
			click_check = false;
		}
		break;
		case 9:
		{
			if (isEmpty(arr, head, tail))
			{
				cout << "������� �����. ���������� ��������� �������: 0" << endl;

			}
			else
			{
				cout << "���������� ��������� �������: " << count(arr, SIZE, head) << endl;
			}
		
		}
		break;
		case 0: return 0;
		default:"������� ���������!";
		}
		cout << endl;
		puts("������� ����� ������ ��� �����������");
		_getch();
		system("cls");
	}
	

	cout << endl;
	delete[] arr; 
	system("pause");
	return 0;
	
}