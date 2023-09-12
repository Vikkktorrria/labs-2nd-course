#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Functions.h"
using namespace std;

int menu()
{
	cout << "1 - ���� ������� �� �������" << endl;
	cout << "2 - ���� ������� �� ��������" << endl;
	cout << "3 - ��������� ������� ���������� ����������" << endl;
	cout << "4 - ����� ������� �� �����" << endl;
	cout << "5 - ����� � ������������ ��������� � �������� ������ � �������" << endl;
	cout << "6 - ����� � ������������ ������� � �������� ���������" << endl;
	cout << "7 - ����� ������������� � ������������ �������� � �������� ������ ��� �������" << endl;
	cout << "8 - ����� ������������� � �������������������� �� ������� � �������� ����������" << endl;
	cout << "9 - ������� ��������� ������� � �������� ����������" << endl;
	cout << "10 - ������� ��������� �������� � ������� ������������" << endl;
	cout << "11 - �������� �������� ������" << endl;
	cout << "12 - ���������� �������� ������" << endl;
	cout << "13 - �������� ��������� �������" << endl;
	cout << "14 - ���������� ��������� �������" << endl;
	cout << "15 - ���������� ��������� ������ � �������" << endl;
	cout << "16 - ���������� ����� �������" << endl;
	cout << "17 - ��������� ������� �� ������, �� ���� ����" << endl;
	cout << "18 - �������������� ������� - ��������� (�������) ������ �� �����" << endl;
	cout << "19 - ���������������� �������" << endl;
	cout << "20 - �������������� � ���������� ������ � �������" << endl;
	cout << "21 - �����" << endl;
	cout << "�������� ��������: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}
bool Rows(int i, int j, int a) { return i == a; } //�������
bool Cols(int i, int j, int a) { return j == a; } //�������
bool MainD(int i, int j, int N) { return i == j; } //������� ���������
bool PobD(int i, int j, int N) { return i + j == N - 1; } //�������� ���������
bool UpTriangle(int i, int j, int N) { return i < j; } //������� ����������� ������������ ������� ���������
bool DownTriagle(int i, int j, int N) { return i > j; } //������ ����������� ������������ ������� ���������
bool pol(int k) { return k > 0; }   //�������������
bool otr(int k) { return k < 0; }   //�������������
bool nul(int k) { return k == 0; } //�������

void GetDArray(int** arr, int N, int M) //���� ������� �� �������
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}
void GetStDArray(int** arr, int N, int M) //���� ������� �� ��������
{
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
			cin >> arr[i][j];
}
void RndDArray(int** arr, int N, int M, int a, int b) //��������� ��������� ��������
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = a + rand() % (b - a + 1);
}
void PrntArray(int** arr, int N, int M) //����� ������� �� �����
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
int* OdnArray(int** arr, int N, int M) //�������������� ������� � ���������� ������
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

	//int* newArr = new int[N * M]; //���������� ������  ����������� �������
//for (int i = 0; i < N; i++)
//    for (int j = 0; j < M; j++)
//        newArr[i * M + j] = arr[i][j];
}
int** TwoArray(int* newArr, int N, int M) //�������������� ����������� ������� � �������
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
int SumArray(int** arr, int N, int M, bool(*fun) (int, int, int), int a) //����� � ������ ��� �������
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
int SumDiagonArray(int** arr, int N, int M, bool(*fun) (int, int, int)) //����� �� ����������
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
int PrArray(int** arr, int N, int M, bool(*fun) (int, int, int), int a) //������������ � ������ ��� �������
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
int PrDiagonArray(int** arr, int N, int M, bool(*fun) (int, int, int)) //������������ �� ����������
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
//int Max(int** arr, int N, int M)//��� ������ ������������� �������� ���� �������
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
int CountArray(int** arr, int N, int M, bool(*fun1) (int, int, int), bool(*fun2) (int))//���-�� ��������� � �������� ���������������
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((*fun1)(i, j, N)) //��������� ��� ��������� ��������
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
void DelRows(int** arr, int N, int M, int k) //�������� ������
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
void DelCols(int** arr, int N, int M, int k) //�������� �������
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
void PutRows(int** arr, int N, int M, int k)//�������� ������
{
	int* newArr = new int[M];
	cout << "������� " << M << " ��������(��) ��� �������: " << endl;
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
		arr[k][j] = newArr[j]; //��������� ������
	}
}
void PutCols(int** arr, int N, int M, int k)//�������� �������
{
	int* newArr = new int[N];
	cout << "������� " << N << " ��������� ��� �������: " << endl;
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
		arr[i][k] = newArr[i]; //��������� �������
	}
}
void SortRows(int** arr, int N, int M, int k) //���������� �������� ������
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
void SortCols(int** arr, int N, int M, int k)//���������� ��������� �������
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
void bubbleSortAll(int** arr, int N, int M) //���������� ����� �������
{
	int SIZE = N * M;
	int* arrone = new int[SIZE];
	int k = 0;
	for (int i = 0; i < N; i++) //����������� ������� � ���������� ������
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
	for (int i = 0; i < N; i++) //����������� ������� ������� � ��������� ������
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = arrone[k];
			k++;
		}
	}
	delete[] arrone;
}
void Vector(int** arr, int N, int M) //��������� ������� �� ������
{
	int SIZE = M;
	int* newArr = new int[SIZE];
	int size = N;
	int* arrone = new int[size];
	cout << "������� " << M << " ��������� �������: ";
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
	cout << "�������, ���������� �� ������: ";
	for (int i = 0; i < N; i++) {
		cout << arrone[i] << "[" << i << "]" << '\t';
	}
	cout << endl;
	delete[] newArr;
	delete[] arrone;
}
void Matrix(int** arr, int N, int M) //��������� ������� �� ���� ����
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
	cout << "�������, ���������� �� ���� ����: " << endl;
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
void RowsUmn(int** arr, int N, int M, int indRow, int k) //��������� ������ �� �����
{
	for (int j = 0; j < M; j++)
		arr[indRow][j] *= k;
}
void RowsDelen(int** arr, int N, int M, int indRow, int k) //������� ������ �� �����
{
	for (int j = 0; j < M; j++)
		arr[indRow][j] /= k;
}
void transposition(int** arr, int N, int M) //���������������� �������
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

two_index MaxArray(int** arr, int N, int M) //���� ������� � �������
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
two_index MinArray(int** arr, int N, int M) //��� ������� � �������
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
two_index MaxIndex(int** arr, int N, int M, bool(*fun) (int, int, int), int b) //���� ������� � �������� ������ ��� �������
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

two_index MinIndex(int** arr, int N, int M, bool(*fun) (int, int, int), int b) //��� ������� � �������� ������ ��� �������
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
two_index MaxIndex(int** arr, int N, int M, bool(*fun) (int, int, int)) // �������� ��� ������� � ��������
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
two_index MinIndex(int** arr, int N, int M, bool(*fun) (int, int, int)) // ������� ��� ������� � ��������
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