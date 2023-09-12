#include<iostream>
#include<iomanip>
#include<conio.h>
#include"functions.h"
using namespace std;
struct Node
{
	int data;
	Node* next;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Node* head = NULL;
	Node* newHead = NULL;
	Node* curr = NULL;

	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			int value;
			cout << "Введите значение, которое хотите добавить: ";
			cin >> value;
			head = addHead(head, value);

		}break;
		case 2:
		{
			int value;
			cout << "Введите значение, которое хотите добавить: ";
			cin >> value;
			head = addTail(head, value);

		}break;
		case 3:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "СПИСОК:" << endl;
				outofList(head);
			}
		}break;
		case 4:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				int pos;
				cout << "Введите позицию, на которую хотите добавить элемент: ";
				cin >> pos;
				cout << "\nДо вставки элемента на позицию " << pos << endl;
				outofList(head);
				int value;
				cout << "Введите значение, которое хотите добавить: ";
				cin >> value;
				bool check = insertPos(head, pos, value);
				if (check == 0 && pos != 1)
				{
					cout << "\nТакой позиции нет или список пуст!\n";
				}
				else if (check == 0 && pos == 1)
				{
					head = addHead(head, value);
					cout << "\nПосле вставки элемента на позицию " << pos << endl;
					outofList(head);
				}
				else
				{
					cout << "\nПосле вставки элемента на позицию " << pos << endl;
					outofList(head);
				}
			}

			
		}break;
		case 5:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список до удаления:\n";
				outofList(head);
				head = removeHead(head);
				cout << "\nПосле удаления элемента из начала:\n";
				outofList(head);
			}	
		}
		break;
		case 6:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список до удаления:\n";
				outofList(head);
				removeTail(head);
				cout << "\nПосле удаления элемента из конца\n";
				outofList(head);
			}
			
		}break;
		case 7:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список до удаления:\n";
				outofList(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				Node* p = findPos(head, pos);
				remove(head, p);
				cout << "\nСписок после удаления:\n";
				outofList(head);
			}

		}break;
		case 8:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список:\n";
				outofList(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				cout << "Найденный указатель узла: " << findPos(head, pos) << endl;
			}

		}break;
		case 9:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список:\n";
				outofList(head);
				int value;
				cout << "\nВведите значение: ";
				cin >> value;
				cout << "Найденный указатель узла: " << findData(head, value) << endl;
			}
			
		}break;
		case 10:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
				cout << "Список не пуст!" << endl;
		}break;
		case 11:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Список:\n";
				outofList(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				cout << "Найденное значение: " << retrieve(head, pos) << endl;
			}

		}break;

		case 12:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "Количество элементов списка равно: " << countNode(head) << endl;
			}
			
		}break;
		case 13:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				int value, N;
				cout << "Введите кол-во элементов, которые хотите добавить во второй список: ";
				cin >> N;
				cout << "Введите значения, которое хотите добавить: ";
				for (int i = 1; i <= N; i++)
				{
					cin >> value;
					newHead = addHead(newHead, value);
				}
				cout << "\nСтарый список:\n";
				outofList(head);
				cout << "Новый список:\n";
				outofList(newHead);
				cout << "Слияние двух списков:\n";
				/*Первый вариант реализации*/
				list_merging(head, newHead);
				outofList(head);

				//ВТОРОЙ вариант реализации
				/* list_concat(head, newHead);
				outofList(head);*/
			}

		}break;
		case 14:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "СПИСОК:\n";
				outofList(head);
				curr = to_head(head);
				cout << "\nПервый элемент списка по итератору: " << show_data(curr);

				curr = to_tail(head);
				cout << "\nПоследний элемент списка по итератору: " << show_data(curr);

				to_pos(head, curr, 2);
				cout << "\nВторой элемент списка по итератору: " << show_data(curr);

				curr = to_next(curr);
				cout << "\nСледующий (после текущего) элемент списка по итератору: " << show_data(curr) << endl;
			}
			

		}break;
		case 15:
		{
			cout << "Список очищен.\n";
			clear(head);
		}break;
		case 0: return 0;
		default:"Введите правильно!";
		}
		cout << endl;
		puts("Нажмите любую кнопку для продолжения");
		_getch();
		system("cls");
	}


	system("pause");
	return 0;
}

