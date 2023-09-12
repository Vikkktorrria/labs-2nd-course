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
			cout << "������� ��������: ";
			cin >> value;
				Push(arr, top, SIZE, value);

		}
		break;
		case 2: 
		{
			if (!IsEmpty(arr, top))
			{
				cout << "����: " << endl;
				Stack_out(arr, top);
			}
			else 
			{ 
				cout << "���� ����!" << endl;
			}

		}break;
		case 3:
		{

			if (IsEmpty(arr, top))
			{
				cout << "���� ����!" << endl;

			}
			else
			{
				cout << "���� �� ��������: " << endl;
				Stack_out(arr, top);
				cout << "\n�������� ���������� ��������: " << Pop(arr, top, SIZE) << endl;
				cout << "\n���� ����� ��������: " << endl;
				Stack_out(arr, top);
			}	

		}
		break;
		case 4:
		{
			if (!IsEmpty(arr, top))
			{
				cout << "�������� �������� �������� �����: " << Peek(arr, top) << endl;

			}
			else
			{
				cout << "���� ����!" << endl;
			}
			
		}break;
		case 5:
		{
			if (!IsEmpty(arr, top))
			{
				cout << "���� �� ����." << endl;

			}
			else
			{
				cout << "���� ����." << endl;
			}
		}
		break;
		case 6:
		{
			Clear(arr, top, SIZE);
			cout << "���� ������." << endl;
		}
		break;
		case 7:
		{
			if (IsEmpty(arr, top))
			{
				cout << "���� ����. ���������� ��������� �����: 0" << endl;

			}
			else
			{
				cout << "���������� ��������� �����: " << Count(arr, top) << endl;
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