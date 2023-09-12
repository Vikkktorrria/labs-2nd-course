#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Functions.h"
using namespace std;

int menu()
{
	cout << "1 - Ввод матрицы по строкам" << endl;
	cout << "2 - Ввод матрицы по столбцам" << endl;
	cout << "3 - Заполнить матрицу случайными значениями" << endl;
	cout << "4 - Вывод массива на экран" << endl;
	cout << "5 - Сумма и произведение элементов в заданной строке и столбце" << endl;
	cout << "6 - Сумма и произведение главной и побочной диагонали" << endl;
	cout << "7 - Поиск максимального и минимального элемента в заданной строке или столбце" << endl;
	cout << "8 - Поиск максимального и минимальногоэлемента на главной и побочной диагоналях" << endl;
	cout << "9 - Подсчёт элементов главной и побочной диагоналей" << endl;
	cout << "10 - Подсчёт элементов верхнего и нижнего треугольника" << endl;
	cout << "11 - Удаление заданной строки" << endl;
	cout << "12 - Добавление заданной строки" << endl;
	cout << "13 - Удаление заданного столбца" << endl;
	cout << "14 - Добавление заданного столбца" << endl;
	cout << "15 - Сортировка выбранной строки и столбца" << endl;
	cout << "16 - Сортировка всего массива" << endl;
	cout << "17 - Умножение матрицы на вектор, на саму себя" << endl;
	cout << "18 - Преобразование матрицы - умножение (деление) строки на число" << endl;
	cout << "19 - Транспонирование матрицы" << endl;
	cout << "20 - Преобразование в одномерный массив и обратно" << endl;
	cout << "21 - Выход" << endl;
	cout << "Выберите действие: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}
bool Rows(int i, int j, int a) { return i == a; } //строчки
bool Cols(int i, int j, int a) { return j == a; } //колонки
bool MainD(int i, int j, int N) { return i == j; } //главная диагональ
bool PobD(int i, int j, int N) { return i + j == N - 1; } //побочная диагональ
bool UpTriangle(int i, int j, int N) { return i < j; } //верхний треугольник относительно главной диагонали
bool DownTriagle(int i, int j, int N) { return i > j; } //нижний треугольник относительно главной диагонали
bool pol(int k) { return k > 0; }   //положительное
bool otr(int k) { return k < 0; }   //отрицательное
bool nul(int k) { return k == 0; } //нулевые

void GetDArray(int** arr, int N, int M) //ввод матрицы по строкам
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}
void GetStDArray(int** arr, int N, int M) //ввод матрицы по столбцам
{
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
			cin >> arr[i][j];
}
void RndDArray(int** arr, int N, int M, int a, int b) //генерация случайных значений
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = a + rand() % (b - a + 1);
}
void PrntArray(int** arr, int N, int M) //вывод массива на экран
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(6) << arr[i][j] << "[" << i << "]" << "[" << j << "]";
		}
		cout << endl;
	}
}
int* OdnArray(int** arr, int N, int M) //преобразование матрицы в одномерный массив
{
	int* newArr = new int[N * M];
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			newArr[x] = arr[i][j];
			x++;
		}
	}
	return newArr;

	//int* newArr = new int[N * M]; //объявление нового  одномерного массива
//for (int i = 0; i < N; i++)
//    for (int j = 0; j < M; j++)
//        newArr[i * M + j] = arr[i][j];
}
int** TwoArray(int* newArr, int N, int M) //преобразование одномерного массива в матрицу
{

	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = newArr[x];
			x++;
		}
	}
	return arr;

	/*int** arr = new int* [N];*/
	/*for (int i = 0; i < N; i++)
		arr[i] = new int[M];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = newArr[i * M + j];*/
}
int SumArray(int** arr, int N, int M, bool(*fun) (int, int, int), int a) //сумма в строке или столбце
{
	int Sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, a))
			{
				Sum = Sum + arr[i][j];
			}
		}
	}
	return Sum;
}
int SumDiagonArray(int** arr, int N, int M, bool(*fun) (int, int, int)) //сумма на диагоналях
{
	int Sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, N))
			{
				Sum = Sum + arr[i][j];
			}
		}
	}
	return Sum;
}
int PrArray(int** arr, int N, int M, bool(*fun) (int, int, int), int a) //произведение в строке или столбце
{
	int Pr = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, a))
			{
				Pr = Pr * arr[i][j];
			}
		}
	}
	return Pr;
}
int PrDiagonArray(int** arr, int N, int M, bool(*fun) (int, int, int)) //произведение на диагоналях
{
	int Pr = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, N))
			{
				Pr = Pr * arr[i][j];
			}
		}
	}
	return Pr;
}
//int Max(int** arr, int N, int M)//для поиска максимального элемента всей матрицы
//{
//	int max = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (max < arr[i][j])
//			{
//				
//				max = arr[i][j];
//			}
//		}
//	}
//	return max;
//}
int CountArray(int** arr, int N, int M, bool(*fun1) (int, int, int), bool(*fun2) (int))//кол-во элементов с заданной характеристикой
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun1)(i, j, N)) //проверяем где находятся элементы
			{
				if ((*fun2)(arr[i][j]))
				{
					count = count + 1;
				}
			}
		}
	}
	return count;
}
void DelRows(int** arr, int N, int M, int k) //удаление строки
{
	for (int i = k; i < N - 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}
	delete[] arr[N - 1];
	N--;
}
void DelCols(int** arr, int N, int M, int k) //удаление столбца
{
	for (int j = k; j < M - 1; j++)
	{
		for (int i = 0; i < N; i++)
		{
			arr[i][j] = arr[i][j + 1];
		}
	}
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			arr[i][M - 1] = 0;
		}
	}
}
void PutRows(int** arr, int N, int M, int k)//вставить строку
{
	int* newArr = new int[M];
	cout << "Введите " << M << " элемента(ов) для вставки: " << endl;
	for (int i = 0; i < M; i++)
	{
		cin >> newArr[i];
	}
	for (int i = N - 1; i >= k; i--)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i + 1][j] = arr[i][j];
		}
	}
	for (int j = 0; j < M; j++)
	{
		arr[k][j] = newArr[j]; //добавляем строку
	}
}
void PutCols(int** arr, int N, int M, int k)//вставить столбец
{
	int* newArr = new int[N];
	cout << "Введите " << N << " элементов для вставки: " << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> newArr[i];
	}
	for (int j = M - 1; j >= k; j--)
	{
		for (int i = 0; i < N; i++)
		{
			arr[i][j + 1] = arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		arr[i][k] = newArr[i]; //добавляем столбец
	}
}
void SortRows(int** arr, int N, int M, int k) //сортировка заданной строки
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < M - 1; i++)
			if (arr[k][i] < arr[k][i + 1])
			{
				int temp = arr[k][i];
				arr[k][i] = arr[k][i + 1];
				arr[k][i + 1] = temp;
				flag = true;
			}
	}
}
void SortCols(int** arr, int N, int M, int k)//сортировка заданного столбца
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < N - 1; i++)
			if (arr[i][k] < arr[i + 1][k])
			{
				int temp = arr[i][k];
				arr[i][k] = arr[i + 1][k];
				arr[i + 1][k] = temp;
				flag = true;
			}
	}
}
void bubbleSortAll(int** arr, int N, int M) //сортировка всего массива
{
	int SIZE = N * M;
	int* arrone = new int[SIZE];
	int k = 0;
	for (int i = 0; i < N; i++) //преобразуем матрицу в одномерный массив
	{
		for (int j = 0; j < M; j++)
		{
			arrone[k] = arr[i][j];
			k++;
		}
	}
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < SIZE - 1; i++)
			if (arrone[i] < arrone[i + 1])
			{
				int temp = arrone[i];
				arrone[i] = arrone[i + 1];
				arrone[i + 1] = temp;
				flag = true;
			}

	}
	k = 0;
	for (int i = 0; i < N; i++) //преобразуем матрицу обратно в двумерный массив
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = arrone[k];
			k++;
		}
	}
	delete[] arrone;
}
void Vector(int** arr, int N, int M) //умножение матрицы на вектор
{
	int SIZE = M;
	int* newArr = new int[SIZE];
	int size = N;
	int* arrone = new int[size];
	cout << "Введите " << M << " элементов вектора: ";
	for (int i = 0; i < M; i++)
		cin >> newArr[i];
	for (int i = 0; i < N; i++)
	{
		int x = 0;
		for (int j = 0; j < M; j++)
		{
			x += arr[i][j] * newArr[j];
		}
		arrone[i] = x;
	}
	cout << "Матрица, умноженная на вектор: ";
	for (int i = 0; i < N; i++) {
		cout << arrone[i] << "[" << i << "]" << '\t';
	}
	cout << endl;
	delete[] newArr;
	delete[] arrone;
}
void Matrix(int** arr, int N, int M) //умножение матрицы на саму себя
{
	int** newArr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		newArr[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			newArr[i][j] = 0;
			for (int k = 0; k < M; k++)
				newArr[i][j] += arr[i][k] * arr[k][j];
		}
	cout << "Матрица, умноженная на саму себя: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(6) << newArr[i][j] << "[" << i << "]" << "[" << j << "]";
		}
		cout << endl;
	}
	delete[] newArr;
}
void RowsUmn(int** arr, int N, int M, int indRow, int k) //умножение строки на число
{
	for (int j = 0; j < M; j++)
		arr[indRow][j] *= k;
}
void RowsDelen(int** arr, int N, int M, int indRow, int k) //деление строки на число
{
	for (int j = 0; j < M; j++)
		arr[indRow][j] /= k;
}
void transposition(int** arr, int N, int M) //транспонирование матрицы
{
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < M; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
}

struct two_index {
public:
    int index1;
    int index2;
};

two_index MaxArray(int** arr, int N, int M) //макс элемент в матрице
{
	two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int max = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < arr[i][j])
			{
				ind.index1 = i;
				ind.index2 = j;
				max = arr[i][j];
			}
		}
	}
	return ind;
}
two_index MinArray(int** arr, int N, int M) //мин элемент в матрице
{
	two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int min = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (min > arr[i][j])
			{
				ind.index1 = i;
				ind.index2 = j;
				min = arr[i][j];
			}
		}
	}
	return ind;
}
two_index MaxIndex(int** arr, int N, int M, bool(*fun) (int, int, int), int b) //макс элемент в заданной строке или столбце
{
    two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int max = arr[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((*fun)(i, j, b))
            {
                if (max < arr[i][j])
                {
                    ind.index1 = i;
                    ind.index2 = j;
                    max = arr[i][j];
                }
            }
            
        }
    }
    return ind;
}

two_index MinIndex(int** arr, int N, int M, bool(*fun) (int, int, int), int b) //мин элемент в заданной строке или столбце
{
	two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int min = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, b))
			{
				if (min > arr[i][j])
				{
					ind.index1 = i;
					ind.index2 = j;
					min = arr[i][j];
				}
			}

		}
	}
	return ind;
}
two_index MaxIndex(int** arr, int N, int M, bool(*fun) (int, int, int)) // максимум для главной и побочной
{
	two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int max = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, N))
			{
				if (max < arr[i][j])
				{
					ind.index1 = i;
					ind.index2 = j;
					max = arr[i][j];
				}
			}

		}
	}
	return ind;
}
two_index MinIndex(int** arr, int N, int M, bool(*fun) (int, int, int)) // минимум для главной и побочной
{
	two_index ind;
	ind.index1 = 0;
	ind.index2 = 0;
	int min = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun)(i, j, N))
			{
				if (min > arr[i][j])
				{
					ind.index1 = i;
					ind.index2 = j;
					min = arr[i][j];
				}
			}

		}
	}
	return ind;
}