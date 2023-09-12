#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;

int menu()
{
	cout << "1 - �������� ������� � ����" << endl;
	cout << "2 - ������� ���� �� �����" << endl;
	cout << "3 - ������� ������� �������" << endl;
	cout << "4 - ��������� �������� �������� �������� �����" << endl;
	cout << "5 - �������� �� �������" << endl;
	cout << "6 - ������� �����" << endl;
	cout << "7 - ����� ������� �����" << endl;
	cout << "0 - �����" << endl;
	cout << "�������� ��������: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}

void Push(int*& arr, int &top, int SIZE, int val) 
{
	top++;
		int* arr_new = new int[top + 1];
		for (int i = 0; i < top; i++)
			arr_new[i] = arr[i];
		arr_new[top] = val;
		delete arr;
		arr = arr_new;
		SIZE++;

	
}
bool IsEmpty(int* arr, int& top) 
{
	if (top == -1)
		return true;
	else
		return false;
}
int Pop(int* arr, int& top, int SIZE)
{
	if (IsEmpty(arr, top))
		return -1;
	int value = arr[top];
	for (int i = top; i < SIZE - 1; i++)
		arr[i] = arr[i + 1];
	arr[SIZE - 1] = 0;
	top--;
	return value;
}
int Peek(int* arr, int& top)
{
	if (arr[top])
	{
		return arr[top];
	}
	else return -1;
}
void Clear(int* arr, int& top, int SIZE)
{
	while (!IsEmpty(arr, top))
		Pop(arr, top, SIZE);
}
int Count(int* arr, int top)
{
	return top + 1;
}

void Stack_out(int* arr, int top)
{
	if (arr[top] && top > -1)
	{
		while (arr[top] && top > -1)
		{
			cout << " " << arr[top] << " ";
			top--;
		}
		cout << endl;
	}
}

