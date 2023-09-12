#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;

int menu()
{
	cout << "1 - ��������� ���" << endl;
	cout << "2 - ������� ��� �� �����" << endl;
	cout << "3 - ������� ������� �� ������" << endl;
	cout << "4 - ������� ������� �� ������" << endl;
	cout << "5 - ��������� �������� ������� �������� ����" << endl;
	cout << "6 - ��������� �������� ���������� �������� ����" << endl;
	cout << "7 - �������� �� �������" << endl;
	cout << "8 - ������� ����" << endl;
	cout << "9 - ����� ������� ����" << endl;
	cout << "0 - �����" << endl;
	cout << "�������� ��������: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}


void pushHead(int* arr, int SIZE, int& head, int& tail, int val)
{
	if (head != 0)
	{
		head--;
		arr[head] = val;
	}
	else
		return;
}
void pushTail(int* arr, int SIZE, int& head, int& tail, int val)
{
	if (tail != SIZE)
	{
		arr[tail] = val;
		tail++;
	}
	else
		return;
}
bool isEmpty(int* arr, int& head, int& tail) 
{
	if (head == tail)
		return true;
	else
		return false;
}
void dek_out(int* arr, int SIZE, int head, int tail)
{
	for (int i = head; i < tail; i++)
	{
		cout << " " << arr[i] << " ";
	}
	cout << endl;
}
int popHead(int*  arr, int& head, int& tail, int SIZE) 
{
	int temp;
	if (head!=tail)
	{
		head++;
		temp = arr[head - 1];
		arr[head - 1] = 0;
	}
	return temp;
}
int popTail(int*  arr, int& head, int& tail, int SIZE) 
{
	int temp;
	if (head != tail)
	{
		tail--;
		temp = arr[tail];
		arr[tail] = 0;
	}
	return temp;
}
int peekHead(int* arr, int& head, int& tail) 
{
	return arr[head];
}
int peekTail(int*  arr, int& head, int& tail) 
{
	return arr[tail-1];
}
int count(int*  arr, int& head, int& tail) 
{
	int count = 0;
	for (int i = head; i < tail; i++)
	{
		count++;
	}
	return count;

}
void clear(int*  arr, int& head, int& tail, int SIZE)
{
	while (head != tail)
	{	
		/*head++;
		arr[head - 1] = 0;
		tail--;
		arr[tail] = 0;*/
		popHead(arr, head, tail, SIZE);
		popTail(arr, head, tail, SIZE);
	}
}

