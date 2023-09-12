#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string path = "data.txt"; //����, � ������� ������� ������

	int SIZE;
	cout << "������� ������ �������: ";
	cin >> SIZE;
	/*float *arr = new float[SIZE];*/
	int *arr = new int[SIZE+1];
	int a, b;
	cout << "������� ��������� � �������� �������� ���������: " << endl;
	cin >> a >> b;
	RndArray(arr, SIZE, a, b);




	cout << endl <<  "����� ����� �������: " << endl;
	PrntArray(arr, SIZE);

	int A, B;
	cout << endl << "������� �������� ��������� ��������: ";
	cin >> A >> B;
	int Sum = SumArray(arr, SIZE, inter, A, B);
	cout << "����� ��������� � �������� ���������: " << Sum << endl;
	int Pr = PrArray(arr, SIZE, inter, A, B);
	cout << "������������ ��������� � �������� ���������: " << Pr << endl;



	cout << endl << "������� ������ ��������, ������� ������ �������: ";
	int k;
	cin >> k;
	Del(arr, SIZE, k);
	cout << "����� ����� ������� ����� ��������: " << endl;
	PrntArray(arr, SIZE);



	int MinIndex = minIndex(arr, SIZE);
	cout << endl << "����������� �������� � �������: " << arr[MinIndex] << endl;
	cout << "������ ������������ �������� � �������: " << MinIndex << endl << endl;

	int MaxIndex = maxIndex(arr, SIZE);
	cout << "������������ �������� � �������: " << arr[MaxIndex] << endl;
	cout << "������ ������������ �������� � �������: " << MaxIndex << endl << endl;

	cout << endl << "���������� ���������: ";
	BubbleSort(arr, SIZE);
	cout << endl << "����� ����� ������� ����� ����������: " << endl;
	PrntArray(arr, SIZE);

	cout << endl << "���������� �������: ";
	ChoiceSort(arr, SIZE);
	cout << endl << "����� ����� ������� ����� ����������: " << endl;
	PrntArray(arr, SIZE);

	cout << endl << "���������� ���������: ";
	insertionSort(arr, SIZE);
	cout << endl << "����� ����� ������� ����� ����������: " << endl;
	PrntArray(arr, SIZE);


	int key;
	cout << endl << "������� ����(�������) ��� ������: ";
	cin >> key;
	int mid = bisearch(key, arr, 0, SIZE - 1);
	cout << "������ ��������� �����: " << mid << endl << endl;



	cout << "������������� ���������: " << multy(arr, SIZE, pol) << endl;
	cout << "������������� ���������: " << multy(arr, SIZE, otr) << endl;
	cout << "������� ���������: " << multy(arr, SIZE, nul) << endl;
	cout << "������� �������� m: ";
	int m;
	cin >> m;
	cout << "���������, ������� m: " << multy(arr, SIZE, modm, m) << endl << endl;



	
	ofstream fout; //������ ������ � ��������� ����
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			fout << arr[i] << "[" << i << "]" << endl;
		}
	}

	ifstream fin; //����� ������ �� ���������� �����
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "������ �� ���������� �����: " << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();


	ofstream binfout; //���� � �������� ����
	binfout.open("binaryData.bin", ios::binary);
	if (!binfout.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			binfout << arr[i] << "[" << i << "]" << endl;
		}
	}

	ifstream binfin; //����� �� ��������� �����
	binfin.open("binaryData.bin", ios::binary);
	if (!binfin.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "������ �� ��������� �����: " << endl;
		char ch;
		while (binfin.get(ch))
		{
			cout << ch;
		}
	}
	binfin.close();

	int q;
	int value;
	cout << endl << "������� ������ ��� �������: ";
	cin >> q;
	cout << "������� �������� ��� �������: ";
	cin >> value;
	Put(arr, SIZE + 1, q, value);
	cout << endl << "����� ����� ������� ����� �������: " << endl;
	PrntArray(arr, SIZE + 1);



	
	   	 
	cout << endl;
	delete[] arr; 
	system("pause");
	return 0;
	
}