#include <iostream>
#include <fstream>
#include <conio.h> 
#include <string>

using namespace std;

struct two_index {
public:
	int index1;
	int index2;
};

#include "Functions.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	int ROWS, COLS, a, b;
	cout << "Введите количество строк: ";
	cin >> ROWS;
	cout << "Введите количество столбцов: ";
	cin >> COLS;
	int** arr = new int* [ROWS+10];
	for (int i = 0; i < ROWS+10; i++)
	{
		arr[i] = new int[COLS+10];
	}
	int* newArr = new int[ROWS];
	cout << endl;


	while (true)
	{
		switch (menu())
		{
		case 1: GetDArray(arr, ROWS, COLS); break;
		case 2: GetStDArray(arr, ROWS, COLS); break;
		case 3:
		{
			cout << "Введите диапазов значений для генерации случайных чисел: ";
			cin >> a >> b;
			RndDArray(arr, ROWS, COLS, a, b);
		}
		break;
		case 4: PrntArray(arr, ROWS, COLS); break;
		case 5:
		{
			PrntArray(arr, ROWS, COLS);
			int q;
			cout << "Введите строку, в которой хотите посчитать сумму и произведние элементов: ";
			cin >> q;
			int sum1 = SumArray(arr, ROWS, COLS, Rows, q);
			int pr1 = PrArray(arr, ROWS, COLS, Rows, q);
			cout << "Сумма равна: " << sum1 << endl;
			cout << "Произведение равно: " << pr1 << endl;

			int p;
			cout << "Введите столбец, в котором хотите посчитать сумму и произведение элементов: ";
			cin >> p;
			int sum2 = SumArray(arr, ROWS, COLS, Cols, p);
			int pr2 = PrArray(arr, ROWS, COLS, Cols, p);
			cout << "Сумма равна: " << sum2 << endl;
			cout << "Произведение равно: " << pr2 << endl;
		}
		break;
		case 6:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "Извините! Введённая матрица не является квадратной!" << endl;
			}
			else
			{
				int MainSum1 = SumDiagonArray(arr, ROWS, COLS, MainD);
				int MainSum2 = PrDiagonArray(arr, ROWS, COLS, MainD);
				cout << "Сумма элементов главной диагонали: " << MainSum1 << endl;
				cout << "Произведение элементов главной диагонали: " << MainSum2 << endl;
				int PobSum1 = SumDiagonArray(arr, ROWS, COLS, PobD);
				int PobSum2 = PrDiagonArray(arr, ROWS, COLS, PobD);
				cout << "Сумма элементов побочной диагонали: " << PobSum1 << endl;
				cout << "Произведение элементов побочной диагонали: " << PobSum2 << endl;

			}
		}
		break;
		case 7:
		{
			PrntArray(arr, ROWS, COLS);
			two_index MaxArrayIndex = MaxArray(arr, ROWS, COLS);
			two_index MinArrayIndex = MinArray(arr, ROWS, COLS);
			cout << "Индексы максимального элемента матрицы: " << MaxArrayIndex.index1 << ' ' << MaxArrayIndex.index2 << endl;
			cout << "Максимальный элемент матрицы: " << arr[MaxArrayIndex.index1][MaxArrayIndex.index2] << endl;
			cout << "Индексы минимального элемента матрицы: " << MinArrayIndex.index1 << ' ' << MinArrayIndex.index2 << endl;
			cout << "Минимальный элемент матрицы: " << arr[MinArrayIndex.index1][MinArrayIndex.index2] << endl;
			int q;
			cout << "\nВведите строку, в которой хотите найти максимальный и минимальный элемент: ";
			cin >> q;
			two_index MaxRowIndex = MaxIndex(arr, ROWS, COLS, Rows, q);
			two_index MinRowIndex = MinIndex(arr, ROWS, COLS, Rows, q);
			cout << "Индексы максимального элемента: " << MaxRowIndex.index1 << ' ' << MaxRowIndex.index2 << endl; 
			cout << "Максимальный элемент: " << arr[MaxRowIndex.index1][MaxRowIndex.index2] << endl;
			cout << "Индексы минимального элемента: " << MinRowIndex.index1 << ' ' << MinRowIndex.index2 << endl;
			cout << "Минимальный элемент: " << arr[MinRowIndex.index1][MinRowIndex.index2] << endl;
			int p;
			cout << "\nВведите столбец, в котором хотите найти максимальный и минимальный элемент: ";
			cin >> p;
			two_index MaxColIndex = MaxIndex(arr, ROWS, COLS, Cols, p);
			two_index MinColIndex = MinIndex(arr, ROWS, COLS, Cols, p);
			cout << "Индексы максимального элемента: " << MaxColIndex.index1 << ' ' << MaxColIndex.index2 << endl;
			cout << "Максимальный элемент: " << arr[MaxColIndex.index1][MaxColIndex.index2] << endl;
			cout << "Индексы минимального элемента: " << MinRowIndex.index1 << ' ' << MinColIndex.index2 << endl;
			cout << "Минимальный элемент: " << arr[MinColIndex.index1][MinColIndex.index2] << endl;

		}
		break;
		case 8:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "Извините! Введённая матрица не является квадратной!" << endl;
			}
			else
			{
				cout << endl;
				two_index MaxMainDinex = MaxIndex(arr, ROWS, COLS, MainD);
				two_index MinMainDinex = MinIndex(arr, ROWS, COLS, MainD);
				cout << "Индексы максимального элемента главной диагонали: " << MaxMainDinex.index1 << ' ' << MaxMainDinex.index2 << endl;
				cout << "Максимальный элемент главной диагонали: " << arr[MaxMainDinex.index1][MaxMainDinex.index2] << endl;
				cout << "Индексы минимального элемента главной диагонали: " << MinMainDinex.index1 << ' ' << MinMainDinex.index2 << endl;
				cout << "Минимальный элемент главной диагонали: " << arr[MinMainDinex.index1][MinMainDinex.index2] << endl;
				cout << endl;
				two_index MaxPobDindex = MaxIndex(arr, ROWS, COLS, PobD);
				two_index MinPobDindex = MinIndex(arr, ROWS, COLS, PobD);
				cout << "Индексы максимального элемента побочной диагонали: " << MaxPobDindex.index1 << ' ' << MaxPobDindex.index2 << endl;
				cout << "Максимальный элемент побочной диагонали: " << arr[MaxPobDindex.index1][MaxPobDindex.index2] << endl;
				cout << "Индексы минимального элемента побочной диагонали: " << MinPobDindex.index1 << ' ' << MinPobDindex.index2 << endl;
				cout << "Минимальный элемент побочной диагонали: " << arr[MinPobDindex.index1][MinPobDindex.index2] << endl;
			}
		}
		break;
		case 9:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "Извините! Введённая матрица не является квадратной!" << endl;
			}
			else
			{
				cout << endl;
				int count_main1 = CountArray(arr, ROWS, COLS, MainD, pol);
				cout << "Положительных элементов главной диагонали: " << count_main1 << endl;
				int count_main2 = CountArray(arr, ROWS, COLS, MainD, otr);
				cout << "Отрицательных элементов главной диагонали: " << count_main2 << endl;
				int count_main3 = CountArray(arr, ROWS, COLS, MainD, nul);
				cout << "Нулевых элементов главной диагонали: " << count_main3 << endl;
				cout << endl;
				int count_pob1 = CountArray(arr, ROWS, COLS, PobD, pol);
				cout << "Положительных элементов побочной диагонали: " << count_pob1 << endl;
				int count_pob2 = CountArray(arr, ROWS, COLS, PobD, otr);
				cout << "Отрицательных элементов побочной диагонали: " << count_pob2 << endl;
				int count_pob3 = CountArray(arr, ROWS, COLS, PobD, nul);
				cout << "Нулевых элементов побочной диагонали: " << count_pob3 << endl;
			}
		}
		break;
		case 10:
		{
			if (ROWS != COLS)
			{
				cout << "Извините! Введённая матрица не является квадратной!" << endl;
			}
			else
			{
				PrntArray(arr, ROWS, COLS);
				cout << endl;
				int count_up_triangle1 = CountArray(arr, ROWS, COLS, UpTriangle, pol);
				cout << "Положительных элементов верхнего треугольника: " << count_up_triangle1 << endl;
				int count_up_triangle2 = CountArray(arr, ROWS, COLS, UpTriangle, otr);
				cout << "Отрицательных элементов верхнего треугольника: " << count_up_triangle2 << endl;
				int count_up_triangle3 = CountArray(arr, ROWS, COLS, UpTriangle, nul);
				cout << "Нулевых элементов верхнего треугольника: " << count_up_triangle3 << endl;
				cout << endl;
				int count_down_triangle1 = CountArray(arr, ROWS, COLS, DownTriagle, pol);
				cout << "Положительных элементов нижнего треугольника: " << count_down_triangle1 << endl;
				int count_down_triangle2 = CountArray(arr, ROWS, COLS, DownTriagle, otr);
				cout << "Отрицательных элементов нижнего треугольника: " << count_down_triangle2 << endl;
				int count_down_triangle3 = CountArray(arr, ROWS, COLS, DownTriagle, nul);
				cout << "Нулевых элементов нижнего треугольника: " << count_down_triangle3 << endl;
			}
		}
		break;
		case 11:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "Введите номер строки, которую хотите удалить: ";
			cin >> k;
			DelRows(arr, ROWS, COLS, k);
			ROWS = ROWS - 1;
			cout << "Матрица после удаление: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 12:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "Введите номер строки, в которую хотите добавить: ";
			cin >> k;
			PutRows(arr, ROWS, COLS, k);
			ROWS = ROWS + 1;
			cout << "Матрица после вставки: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 13:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "Введите номер столбца, который хотите удалить: ";
			cin >> k;
			DelCols(arr, ROWS, COLS, k);
	/*		COLS = COLS - 1;*/
			cout << "Матрица после удаление: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 14:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "Введите номер столбца, в который хотите добавить: ";
			cin >> k;
			PutCols(arr, ROWS, COLS, k);
			COLS = COLS + 1;
			cout << "Матрица после вставки: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 15:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "Введите номер строки, которую хотите отсортировать: ";
			cin >> k;
			SortRows(arr, ROWS, COLS, k);
			cout << "Матрица после сортировки: " << endl;
			PrntArray(arr, ROWS, COLS);

			int q;
			cout << "Введите номер столбца, который хотите отсортировать: ";
			cin >> q;
			SortCols(arr, ROWS, COLS, q);
			cout << "Матрица после сортировки: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 16:
		{
			cout << "Массив до сортировки: " << endl;
			PrntArray(arr, ROWS, COLS);
			bubbleSortAll(arr, ROWS, COLS);
			cout << "Массив после сортировки: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 17:
		{
			Vector(arr, ROWS, COLS);
			Matrix(arr, ROWS, COLS);
		}
		break;
		case 18:
		{

			PrntArray(arr, ROWS, COLS);

			int indRow1, k1;
			int indRow2, k2;
			cout << "Введите индекс строки, которая будет умножена на число: ";
			cin >> indRow1;
			cout << "Введите число: ";
			cin >> k1;
			RowsUmn(arr, ROWS, COLS, indRow1, k1);
			cout << "Матрица после умножения: " << endl;
			PrntArray(arr, ROWS, COLS);

			cout << "Введите индекс строки, которая будет поделена на число: ";
			cin >> indRow2;
			cout << "Введите число: ";
			cin >> k2;
			RowsDelen(arr, ROWS, COLS, indRow2, k2);
			cout << "Матрица после деления: " << endl;
			PrntArray(arr, ROWS, COLS);
			
		}
		break;
		case 19:
		{

			cout << "Матртица до транспонирования: " << endl;
			PrntArray(arr, ROWS, COLS);

			transposition(arr, ROWS, COLS);
			cout << "Матртица после транспонирования: " << endl;
			PrntArray(arr, ROWS, COLS);

		}
		break;
		case 20:
		{
			cout << "Преобразование в вектор: " << endl;
			newArr = OdnArray(arr, ROWS, COLS);
			for (int i = 0; i < ROWS * COLS; i++)
			{
				cout << newArr[i] << '\t';
			}
			cout << endl;
			cout << "Преобразование в матрицу: " << endl;
			arr = TwoArray(newArr, ROWS, COLS);
			PrntArray(arr, ROWS, COLS);

		}
		break;
		case 21: return 0;
		default:"Введите правильно!";
		}
		cout << endl;
		puts("Нажмите любую кнопку для продолжения");
		_getch();
		system("cls");
	}



	for (int i = 0; i < ROWS; i++)//удаляем массив, очищаем память
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = NULL;
	cout << endl;
	system("pause");
	return 0;
}