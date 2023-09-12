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
	cout << "������� ���������� ��������� ����: ";
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
					cout << "������� " << i + 1 << "-� ������� ������: ";
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

				click_check = true;
			}
			else
			{
				cout << "��� ��� ��������!\n";
			}
		}
		break;
		case 2: 
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "���: " << endl;
				dek_out(arr, SIZE, head, tail);
			}
			else 
			{ 
				cout << "��� ����!" << endl;
			}

		}break;
		case 3:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "��� ����!" << endl;

			}
			else
			{
				cout << "��� �� ��������: " << endl;
				dek_out(arr, SIZE, head, tail);
				cout << "\n�������� ���������� ��������: " << popHead(arr, head, tail, SIZE) << endl;
				cout << "\n��� ����� ��������: " << endl;
				dek_out(arr, SIZE, head, tail);
			}	

		}
		break;
		case 4:
		{

			if (isEmpty(arr, head, tail))
			{
				cout << "��� ����!" << endl;

			}
			else
			{
				cout << "��� �� ��������: " << endl;
				dek_out(arr, SIZE, head, tail);
				cout << "\n�������� ���������� ��������: " << popTail(arr, head, tail, SIZE) << endl;
				cout << "\n��� ����� ��������: " << endl;
				dek_out(arr, SIZE, head, tail);
			}

		}
		break;
		case 5:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "�������� ������� �������� ����: " << peekHead(arr, head, tail) << endl;

			}
			else
			{
				cout << "��� ����!" << endl;
			}

		}break;
		case 6:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "�������� ���������� �������� ����: " << peekTail(arr, head, tail) << endl;

			}
			else
			{
				cout << "��� ����!" << endl;
			}

		}break;
		case 7:
		{
			if (!isEmpty(arr, head, tail))
			{
				cout << "��� �� ����." << endl;

			}
			else
			{
				cout << "��� ����." << endl;
			}
		}
		break;
		case 8:
		{
			clear(arr, head, tail, SIZE);
			cout << "��� ������." << endl;
			click_check = false;
		}
		break;
		case 9:
		{
			if (isEmpty(arr, head, tail))
			{
				cout << "��� ����. ���������� ��������� ����: 0" << endl;

			}
			else
			{
				cout << "���������� ��������� ����: " << count(arr, head, tail) << endl;
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