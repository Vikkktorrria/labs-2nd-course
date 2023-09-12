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
	cout << "������� ���������� �����: ";
	cin >> ROWS;
	cout << "������� ���������� ��������: ";
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
			cout << "������� �������� �������� ��� ��������� ��������� �����: ";
			cin >> a >> b;
			RndDArray(arr, ROWS, COLS, a, b);
		}
		break;
		case 4: PrntArray(arr, ROWS, COLS); break;
		case 5:
		{
			PrntArray(arr, ROWS, COLS);
			int q;
			cout << "������� ������, � ������� ������ ��������� ����� � ����������� ���������: ";
			cin >> q;
			int sum1 = SumArray(arr, ROWS, COLS, Rows, q);
			int pr1 = PrArray(arr, ROWS, COLS, Rows, q);
			cout << "����� �����: " << sum1 << endl;
			cout << "������������ �����: " << pr1 << endl;

			int p;
			cout << "������� �������, � ������� ������ ��������� ����� � ������������ ���������: ";
			cin >> p;
			int sum2 = SumArray(arr, ROWS, COLS, Cols, p);
			int pr2 = PrArray(arr, ROWS, COLS, Cols, p);
			cout << "����� �����: " << sum2 << endl;
			cout << "������������ �����: " << pr2 << endl;
		}
		break;
		case 6:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "��������! �������� ������� �� �������� ����������!" << endl;
			}
			else
			{
				int MainSum1 = SumDiagonArray(arr, ROWS, COLS, MainD);
				int MainSum2 = PrDiagonArray(arr, ROWS, COLS, MainD);
				cout << "����� ��������� ������� ���������: " << MainSum1 << endl;
				cout << "������������ ��������� ������� ���������: " << MainSum2 << endl;
				int PobSum1 = SumDiagonArray(arr, ROWS, COLS, PobD);
				int PobSum2 = PrDiagonArray(arr, ROWS, COLS, PobD);
				cout << "����� ��������� �������� ���������: " << PobSum1 << endl;
				cout << "������������ ��������� �������� ���������: " << PobSum2 << endl;

			}
		}
		break;
		case 7:
		{
			PrntArray(arr, ROWS, COLS);
			two_index MaxArrayIndex = MaxArray(arr, ROWS, COLS);
			two_index MinArrayIndex = MinArray(arr, ROWS, COLS);
			cout << "������� ������������� �������� �������: " << MaxArrayIndex.index1 << ' ' << MaxArrayIndex.index2 << endl;
			cout << "������������ ������� �������: " << arr[MaxArrayIndex.index1][MaxArrayIndex.index2] << endl;
			cout << "������� ������������ �������� �������: " << MinArrayIndex.index1 << ' ' << MinArrayIndex.index2 << endl;
			cout << "����������� ������� �������: " << arr[MinArrayIndex.index1][MinArrayIndex.index2] << endl;
			int q;
			cout << "\n������� ������, � ������� ������ ����� ������������ � ����������� �������: ";
			cin >> q;
			two_index MaxRowIndex = MaxIndex(arr, ROWS, COLS, Rows, q);
			two_index MinRowIndex = MinIndex(arr, ROWS, COLS, Rows, q);
			cout << "������� ������������� ��������: " << MaxRowIndex.index1 << ' ' << MaxRowIndex.index2 << endl; 
			cout << "������������ �������: " << arr[MaxRowIndex.index1][MaxRowIndex.index2] << endl;
			cout << "������� ������������ ��������: " << MinRowIndex.index1 << ' ' << MinRowIndex.index2 << endl;
			cout << "����������� �������: " << arr[MinRowIndex.index1][MinRowIndex.index2] << endl;
			int p;
			cout << "\n������� �������, � ������� ������ ����� ������������ � ����������� �������: ";
			cin >> p;
			two_index MaxColIndex = MaxIndex(arr, ROWS, COLS, Cols, p);
			two_index MinColIndex = MinIndex(arr, ROWS, COLS, Cols, p);
			cout << "������� ������������� ��������: " << MaxColIndex.index1 << ' ' << MaxColIndex.index2 << endl;
			cout << "������������ �������: " << arr[MaxColIndex.index1][MaxColIndex.index2] << endl;
			cout << "������� ������������ ��������: " << MinRowIndex.index1 << ' ' << MinColIndex.index2 << endl;
			cout << "����������� �������: " << arr[MinColIndex.index1][MinColIndex.index2] << endl;

		}
		break;
		case 8:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "��������! �������� ������� �� �������� ����������!" << endl;
			}
			else
			{
				cout << endl;
				two_index MaxMainDinex = MaxIndex(arr, ROWS, COLS, MainD);
				two_index MinMainDinex = MinIndex(arr, ROWS, COLS, MainD);
				cout << "������� ������������� �������� ������� ���������: " << MaxMainDinex.index1 << ' ' << MaxMainDinex.index2 << endl;
				cout << "������������ ������� ������� ���������: " << arr[MaxMainDinex.index1][MaxMainDinex.index2] << endl;
				cout << "������� ������������ �������� ������� ���������: " << MinMainDinex.index1 << ' ' << MinMainDinex.index2 << endl;
				cout << "����������� ������� ������� ���������: " << arr[MinMainDinex.index1][MinMainDinex.index2] << endl;
				cout << endl;
				two_index MaxPobDindex = MaxIndex(arr, ROWS, COLS, PobD);
				two_index MinPobDindex = MinIndex(arr, ROWS, COLS, PobD);
				cout << "������� ������������� �������� �������� ���������: " << MaxPobDindex.index1 << ' ' << MaxPobDindex.index2 << endl;
				cout << "������������ ������� �������� ���������: " << arr[MaxPobDindex.index1][MaxPobDindex.index2] << endl;
				cout << "������� ������������ �������� �������� ���������: " << MinPobDindex.index1 << ' ' << MinPobDindex.index2 << endl;
				cout << "����������� ������� �������� ���������: " << arr[MinPobDindex.index1][MinPobDindex.index2] << endl;
			}
		}
		break;
		case 9:
		{
			PrntArray(arr, ROWS, COLS);
			if (ROWS != COLS)
			{
				cout << "��������! �������� ������� �� �������� ����������!" << endl;
			}
			else
			{
				cout << endl;
				int count_main1 = CountArray(arr, ROWS, COLS, MainD, pol);
				cout << "������������� ��������� ������� ���������: " << count_main1 << endl;
				int count_main2 = CountArray(arr, ROWS, COLS, MainD, otr);
				cout << "������������� ��������� ������� ���������: " << count_main2 << endl;
				int count_main3 = CountArray(arr, ROWS, COLS, MainD, nul);
				cout << "������� ��������� ������� ���������: " << count_main3 << endl;
				cout << endl;
				int count_pob1 = CountArray(arr, ROWS, COLS, PobD, pol);
				cout << "������������� ��������� �������� ���������: " << count_pob1 << endl;
				int count_pob2 = CountArray(arr, ROWS, COLS, PobD, otr);
				cout << "������������� ��������� �������� ���������: " << count_pob2 << endl;
				int count_pob3 = CountArray(arr, ROWS, COLS, PobD, nul);
				cout << "������� ��������� �������� ���������: " << count_pob3 << endl;
			}
		}
		break;
		case 10:
		{
			if (ROWS != COLS)
			{
				cout << "��������! �������� ������� �� �������� ����������!" << endl;
			}
			else
			{
				PrntArray(arr, ROWS, COLS);
				cout << endl;
				int count_up_triangle1 = CountArray(arr, ROWS, COLS, UpTriangle, pol);
				cout << "������������� ��������� �������� ������������: " << count_up_triangle1 << endl;
				int count_up_triangle2 = CountArray(arr, ROWS, COLS, UpTriangle, otr);
				cout << "������������� ��������� �������� ������������: " << count_up_triangle2 << endl;
				int count_up_triangle3 = CountArray(arr, ROWS, COLS, UpTriangle, nul);
				cout << "������� ��������� �������� ������������: " << count_up_triangle3 << endl;
				cout << endl;
				int count_down_triangle1 = CountArray(arr, ROWS, COLS, DownTriagle, pol);
				cout << "������������� ��������� ������� ������������: " << count_down_triangle1 << endl;
				int count_down_triangle2 = CountArray(arr, ROWS, COLS, DownTriagle, otr);
				cout << "������������� ��������� ������� ������������: " << count_down_triangle2 << endl;
				int count_down_triangle3 = CountArray(arr, ROWS, COLS, DownTriagle, nul);
				cout << "������� ��������� ������� ������������: " << count_down_triangle3 << endl;
			}
		}
		break;
		case 11:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "������� ����� ������, ������� ������ �������: ";
			cin >> k;
			DelRows(arr, ROWS, COLS, k);
			ROWS = ROWS - 1;
			cout << "������� ����� ��������: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 12:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "������� ����� ������, � ������� ������ ��������: ";
			cin >> k;
			PutRows(arr, ROWS, COLS, k);
			ROWS = ROWS + 1;
			cout << "������� ����� �������: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 13:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "������� ����� �������, ������� ������ �������: ";
			cin >> k;
			DelCols(arr, ROWS, COLS, k);
	/*		COLS = COLS - 1;*/
			cout << "������� ����� ��������: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 14:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "������� ����� �������, � ������� ������ ��������: ";
			cin >> k;
			PutCols(arr, ROWS, COLS, k);
			COLS = COLS + 1;
			cout << "������� ����� �������: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 15:
		{
			PrntArray(arr, ROWS, COLS);
			int k;
			cout << "������� ����� ������, ������� ������ �������������: ";
			cin >> k;
			SortRows(arr, ROWS, COLS, k);
			cout << "������� ����� ����������: " << endl;
			PrntArray(arr, ROWS, COLS);

			int q;
			cout << "������� ����� �������, ������� ������ �������������: ";
			cin >> q;
			SortCols(arr, ROWS, COLS, q);
			cout << "������� ����� ����������: " << endl;
			PrntArray(arr, ROWS, COLS);
		}
		break;
		case 16:
		{
			cout << "������ �� ����������: " << endl;
			PrntArray(arr, ROWS, COLS);
			bubbleSortAll(arr, ROWS, COLS);
			cout << "������ ����� ����������: " << endl;
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
			cout << "������� ������ ������, ������� ����� �������� �� �����: ";
			cin >> indRow1;
			cout << "������� �����: ";
			cin >> k1;
			RowsUmn(arr, ROWS, COLS, indRow1, k1);
			cout << "������� ����� ���������: " << endl;
			PrntArray(arr, ROWS, COLS);

			cout << "������� ������ ������, ������� ����� �������� �� �����: ";
			cin >> indRow2;
			cout << "������� �����: ";
			cin >> k2;
			RowsDelen(arr, ROWS, COLS, indRow2, k2);
			cout << "������� ����� �������: " << endl;
			PrntArray(arr, ROWS, COLS);
			
		}
		break;
		case 19:
		{

			cout << "�������� �� ����������������: " << endl;
			PrntArray(arr, ROWS, COLS);

			transposition(arr, ROWS, COLS);
			cout << "�������� ����� ����������������: " << endl;
			PrntArray(arr, ROWS, COLS);

		}
		break;
		case 20:
		{
			cout << "�������������� � ������: " << endl;
			newArr = OdnArray(arr, ROWS, COLS);
			for (int i = 0; i < ROWS * COLS; i++)
			{
				cout << newArr[i] << '\t';
			}
			cout << endl;
			cout << "�������������� � �������: " << endl;
			arr = TwoArray(newArr, ROWS, COLS);
			PrntArray(arr, ROWS, COLS);

		}
		break;
		case 21: return 0;
		default:"������� ���������!";
		}
		cout << endl;
		puts("������� ����� ������ ��� �����������");
		_getch();
		system("cls");
	}



	for (int i = 0; i < ROWS; i++)//������� ������, ������� ������
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = NULL;
	cout << endl;
	system("pause");
	return 0;
}