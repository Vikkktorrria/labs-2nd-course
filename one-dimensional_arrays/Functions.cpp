#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

void RndArray(int* arr, int size, int a, int b) //��������� ������� ����. �������
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = a + rand() % (b - a + 1);
	}
}
void PrntArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "[" << i << "]" << endl;
	}
}
int SumArray(int* arr, int size, bool(*fun) (int, int, int), int a, int b) //����� ���� ��������� ������� 
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((*fun)(i, a, b)) //�������� ��������� ��������
		{
			sum = sum + arr[i];
		}

	}
	return sum;
}
int PrArray(int* arr, int size, bool(*fun) (int, int, int), int a, int b) //������������ ���� ��������� ������� 
{
	int pr = 1;
	for (int i = 0; i < size; i++)
	{
		if ((*fun)(i, a, b))
		{
			pr = pr * arr[i];
		}

	}
	return pr;
}
void Del(int* arr, int size, int k) //�������� �������� � �������� k
{
	for (int i = k; i < size - 1; i++) //����� �����
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;              // ���������� �������� ����������� 0      
}
void Put(int* arr, int size, int k, int value)
{
	for (int i = size - 1; i > k; i--) //����� ������ (��� �� ������)
		arr[i] = arr[i - 1];
	arr[k] = value;              // k-�� �������� ����������� ���� ��������      

}
void BubbleSort(int* arr, int size) //�� ����������� (���������)
{
	int temp; // ��������� ���������� ��� ������ ��������� �������
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				// ������ �������� �������
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void ChoiceSort(int* arr, int size) //�� �������� (� ��������� �����, ��� ��� ���������� �������)
{
	int temp; // ��������� ���������� ��� ������ ��������� �������

  // ���������� ������� ������� (����� ��� �� ��� ���������, �������� ����������� � ������� �����������)
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (arr[j] < arr[j + 1]) 
			{
				
				temp = arr[j]; // ������ �������� �������
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void LineSort(int* arr, int size)//���������� �� �����������
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[i]) 
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
void insertionSort(int* arr, int size) // ���������� ���������
{
	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
		item; // ������ ����������� ��������
	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = i - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arr[item + 1] = arr[item]; // ������������ ��������� �������
			arr[item] = temp;
			item--;
		}
	}
}
void ChetSort(int* arr, int size) //� ������ ��� �������� ������������� ��������, �������� � �������� ��������, � �� ������ � ��������, �������� � ������ ��������.
{
	
		int IndexChet = 0;
		int IndexNechet = size / 2;

		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			{
				temp[IndexChet] = arr[i];
				IndexChet++;
			}
			else {
				temp[IndexNechet] = arr[i];
				IndexNechet++;
			}
		}

		delete[] arr;
		arr = temp;
	

}
int minIndex(int* arr, int size)
{
	int min = 0;
	for (int i = 1; i < size; i++)
		if (arr[min] > arr[i])
			min = i;
	return min;
}
int maxIndex(int* arr, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
		if (arr[max] < arr[i])
			max = i;
	return max;
}
int bisearch(int key, int* arr, int low, int high)
{
	int mid = (low + high) / 2; //��������� ������ ����������� �������� �������
	if (high < low) //high �� ����� ���� ������ low
	{
		return -1;
	}
	if (arr[mid] > key) //��������� ��������� ����� � ����� �������� ���������������� ������
	{
		bisearch(key, arr, low, mid - 1);
	}
	else
	{
		if (arr[mid] < key) //��������� ��������� ����� � ������ �������� ���������������� ������
		{
			bisearch(key, arr, mid + 1, high);
		}
		else //���� ���������� �������, ���������� ������ mid ��� ���������� �����
		{
			return mid;
		}
	}
}
int  multy(int* arr, int size, bool(*fun) (int))
{
	int  p = 0;
	for (int i = 0; i < size; i++)
		if ((*fun)(arr[i])) //������������ ���-�� ��������� � �������� ���� ���������������
			p++;
	return p;
}
int  multy(int* arr, int size, bool(*fun) (int, int), int m)
{
	int  p = 0;
	for (int i = 0; i < size; i++)
		if ((*fun)(arr[i], m)) //����� �� ������� ��� �������� ��������� ������� m
			p++;
	return p;
}
bool modm(int k, int m) //������� m
{
	if (k%m == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
bool inter(int k, int a, int b) { return k >= a && k <= b; }
bool pol(int k) { return k > 0; }   //�������������
bool otr(int k) { return k < 0; }   //�������������
bool nul(int k) { return k == 0; } //�������



void FloatRndArray(float* arr, int size, int a, int b) //��������� ������� ����. �������
{
	for (int i = 0; i < size; i++)
	{
		int A = a * 10 + rand() % (b * 10 - a * 10 + 1);
		arr[i] = (float)A / 10;
	}
}
void PrntArray(float* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "[" << i << "]" << endl;
	}
}
float SumArray(float* arr, int size, bool(*fun) (int, int, int), int a, int b) //����� ���� ��������� ������� (������������)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((*fun)(i, a, b))
		{
			sum = sum + arr[i];
		}

	}
	return sum;
}
float PrArray(float* arr, int size, bool(*fun) (int, int, int), int a, int b) //������������ ���� ��������� ������� (������������)
{
	float pr = 1;
	for (int i = 0; i < size; i++)
	{
		if ((*fun)(i, a, b))
		{
			pr = pr * arr[i];
		}

	}
	return pr;
}
void Del(float* arr, int size, int k) //�������� �������� � �������� k
{
	for (int i = k; i < size - 1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = 0;              // ���������� �������� ����������� 0      
}
void Put(float* arr, int size, int k, float value)
{

	for (int i = size - 1; i > k; i--)

		arr[i] = arr[i - 1];

	arr[k] = value;              // k-�� �������� ����������� ���� ��������      

}
void ChoiceSort(float* arr, int size) //�� �������� (� ��������� �����, ��� ��� ���������� �������)
{
	float temp; // ��������� ���������� ��� ������ ��������� �������

  // ���������� ������� ������� (����� ��� �� ��� ���������, �������� � ����� ����������� � ������� �����������)
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				// ������ �������� �������
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void insertionSort(float* arr, int size) // ���������� ���������
{
	float temp; // ��������� ���������� ��� �������� �������� �������� ������������ �������
		int item; // ������ ����������� ��������
	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = i - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arr[item + 1] = arr[item]; // ������������ ��������� �������
			arr[item] = temp;
			item--;
		}
	}
}
void ChetSort(float* arr, int size) //� ������ ��� �������� ������������� ��������, �������� � �������� ��������, � �� ������ � ��������, �������� � ������ ��������.
{
	for (int i = 0, j = 0; i < (size + 1) / 2; i++, j += 2)
	{
		float Arr = arr[i];
		arr[i] = arr[j];
		arr[j] = Arr;
	}
}
int minIndex(float* arr, int size)
{
	int min = 0;
	for (int i = 1; i < size; i++)
		if (arr[min] > arr[i])
			min = i;
	return min;
}
int maxIndex(float* arr, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++)
		if (arr[max] < arr[i])
			max = i;
	return max;
}
int bisearch(int key, float* arr, int low, int high)
{
	int mid = (low + high) / 2; //��������� ������ ����������� �������� �������
	if (high < low) //high �� ����� ���� ������ low
		return -1;
	if (arr[mid] > key) //��������� ��������� ����� � ����� �������� ���������������� ������
		bisearch(key, arr, low, mid - 1);
	else
		if (arr[mid] < key) //��������� ��������� ����� � ������ �������� ���������������� ������.
			bisearch(key, arr, mid + 1, high);
		else //���� ���������� �������, ���������� ������ mid ��� ���������� �����.
			return mid;
}
//int  multy(float* arr, int size, bool(*fun) (int))
//{
//	int  p = 0;
//	for (int i = 0; i < size; i++)
//		if ((*fun)(arr[i])) //������������ ���-�� ��������� � �������� ���� ���������������
//			p++;
//	return p;
//}
//int  multy(float* arr, int size, bool(*fun) (int, int), int m)
//{
//	int  p = 0;
//	for (int i = 0; i < size; i++)
//		if ((*fun)(arr[i], m)) //����� �� ������� ��� �������� ��������� ������� m
//			p++;
//	return p;
//}

//bool Floatinter(int k, int a, int b) { return k >= a && k <= b; }
bool pol(float k) { return k > 0; }   //�������������
bool otr(float k) { return k < 0; }   //�������������
bool nul(float k) { return k == 0; } //�������