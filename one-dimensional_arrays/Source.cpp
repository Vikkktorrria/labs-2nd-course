#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	string path = "data.txt"; //файл, в который запишем данные

	int SIZE;
	cout << "Введите размер массива: ";
	cin >> SIZE;
	/*float *arr = new float[SIZE];*/
	int *arr = new int[SIZE+1];
	int a, b;
	cout << "Задайте начальное и конечное значение диапазона: " << endl;
	cin >> a >> b;
	RndArray(arr, SIZE, a, b);




	cout << endl <<  "Вывод всего массива: " << endl;
	PrntArray(arr, SIZE);

	int A, B;
	cout << endl << "Задайте значения диапазона индексов: ";
	cin >> A >> B;
	int Sum = SumArray(arr, SIZE, inter, A, B);
	cout << "Сумма элементов в заданном диапазоне: " << Sum << endl;
	int Pr = PrArray(arr, SIZE, inter, A, B);
	cout << "Произведение элементов в заданном диапазоне: " << Pr << endl;



	cout << endl << "Введите индекс элемента, который хотите удалить: ";
	int k;
	cin >> k;
	Del(arr, SIZE, k);
	cout << "Вывод всего массива после удаления: " << endl;
	PrntArray(arr, SIZE);



	int MinIndex = minIndex(arr, SIZE);
	cout << endl << "Минимальное значение в массиве: " << arr[MinIndex] << endl;
	cout << "Индекс минимального значения в массиве: " << MinIndex << endl << endl;

	int MaxIndex = maxIndex(arr, SIZE);
	cout << "Максимальное значение в массиве: " << arr[MaxIndex] << endl;
	cout << "Индекс масимального значения в массиве: " << MaxIndex << endl << endl;

	cout << endl << "Сортировка пузырьком: ";
	BubbleSort(arr, SIZE);
	cout << endl << "Вывод всего массива после сортировки: " << endl;
	PrntArray(arr, SIZE);

	cout << endl << "Сортировка выбором: ";
	ChoiceSort(arr, SIZE);
	cout << endl << "Вывод всего массива после сортировки: " << endl;
	PrntArray(arr, SIZE);

	cout << endl << "Сортировка вставками: ";
	insertionSort(arr, SIZE);
	cout << endl << "Вывод всего массива после сортировки: " << endl;
	PrntArray(arr, SIZE);


	int key;
	cout << endl << "Введите ключ(элемент) для поиска: ";
	cin >> key;
	int mid = bisearch(key, arr, 0, SIZE - 1);
	cout << "Индекс заданного ключа: " << mid << endl << endl;



	cout << "Положительных элементов: " << multy(arr, SIZE, pol) << endl;
	cout << "Отрицательных элементов: " << multy(arr, SIZE, otr) << endl;
	cout << "Нулевых элементов: " << multy(arr, SIZE, nul) << endl;
	cout << "Введите детилель m: ";
	int m;
	cin >> m;
	cout << "Элементов, кратных m: " << multy(arr, SIZE, modm, m) << endl << endl;



	
	ofstream fout; //запись данных в текстовый файл
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			fout << arr[i] << "[" << i << "]" << endl;
		}
	}

	ifstream fin; //вывод данных из текстового файла
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Данные из текстового файла: " << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();


	ofstream binfout; //ввод в бинарный файл
	binfout.open("binaryData.bin", ios::binary);
	if (!binfout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			binfout << arr[i] << "[" << i << "]" << endl;
		}
	}

	ifstream binfin; //вывод из бинарного файла
	binfin.open("binaryData.bin", ios::binary);
	if (!binfin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Данные из бинарного файла: " << endl;
		char ch;
		while (binfin.get(ch))
		{
			cout << ch;
		}
	}
	binfin.close();

	int q;
	int value;
	cout << endl << "Введите индекс для вставки: ";
	cin >> q;
	cout << "Введите значение для вставки: ";
	cin >> value;
	Put(arr, SIZE + 1, q, value);
	cout << endl << "Вывод всего массива после вставки: " << endl;
	PrntArray(arr, SIZE + 1);



	
	   	 
	cout << endl;
	delete[] arr; 
	system("pause");
	return 0;
	
}