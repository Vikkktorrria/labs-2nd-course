#include<iostream>
#include<iomanip>
#include<conio.h>
#include"Functions.h"
using namespace std;
struct Node
{
	int data;
	Node* next;
};

int main(){
	setlocale(LC_ALL, "Rus");
	Node* head = NULL;
	Node* tail = NULL;
	Node* newHead = NULL;
	Node* newTail = NULL;
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
			addHead(head, tail, value);

		}break;
		case 2:
		{
			int value;
			cout << "Введите значение, которое хотите добавить: ";
			cin >> value;
			addTail(head, tail, value);

		}break;
		case 3:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "СПИСОК С НАЧАЛА:" << endl;
				outListHead(head);
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
				cout << "СПИСОК С КОНЦА:" << endl;
				outListTail(tail);
			}
		}break;
		case 5:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Перед удалением элемента из начала:" << endl;
				outListHead(head);
				head = removeHead(head);
				cout << "\nПосле удаления элемента из начала:\n";
				outListHead(head);
			}

		}
		break;
		case 6:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Перед удалением элемента из конца:" << endl;
				outListHead(head);
				tail = removeTail(tail);
				cout << "\nПосле удаления элемента из конца:\n";
				outListHead(head);
			}

		}break;
		case 7:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список до удаления:\n";
				outListHead(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				Node* p = findPosHead(head, pos);
				remove(head, tail, p);
				cout << "\nСписок после удаления:\n";
				outListHead(head);
			}


		}break;
	
		case 8:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список не пуст!" << endl;
			}
		}break;
		case 9:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список:\n";
				outListHead(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				cout << "Найденный указатель узла: " << findPosHead(head, pos) << endl;
				cout << "Найденное значение узла: " << show_data(findPosHead(head, pos)) << endl;
			}

		}break;
		case 10:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список:\n";
				outListTail(tail);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				cout << "Найденный указатель узла: " << findPosTail(tail, pos) << endl;
				cout << "Найденное значение узла: " << show_data(findPosTail(tail, pos)) << endl;
			}

		}break;
		case 11:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список:\n";
				outListHead(head);
				int value;
				cout << "\nВведите значение: ";
				cin >> value;
				cout << "Найденный указатель узла: " << findDataHead(head, value) << endl;
				cout << "Найденное значение узла: " << show_data(findDataHead(head, value)) << endl;
			}
			
		}break;
		case 12:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Список:\n";
				outListTail(tail);
				int value;
				cout << "\nВведите значение: ";
				cin >> value;
				cout << "Найденный указатель узла: " << findDataTail(tail, value) << endl;
				cout << "Найденное значение узла: " << show_data(findDataTail(tail, value)) << endl;
			}
			
		}break;
		case 13:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "Количество элементов списка равно: " << countElemHead(head) << endl;
			}

		}break;
		case 14:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "СПИСОК:\n";
				outListHead(head);
				int pos;
				cout << "\nВведите позицию: ";
				cin >> pos;
				cout << "Найненное значение: " << retrieve(head, pos) << endl;

			}

		}break;
		case 15:
		{
			if (isEmpty(head))
				cout << "Список пуст!" << endl;
			else
			{
				cout << "СПИСОК:\n";
				outListHead(head);
				curr = to_head(head);
				cout << "\nПервый элемент списка по итератору: " << show_data(curr);

				curr = to_tail(tail);
				cout << "\nПоследний элемент списка по итератору: " << show_data(curr);

				to_pos(head, curr, 3);
				cout << "\nТретий элемент списка по итератору: " << show_data(curr);

				curr = to_next(curr);
				cout << "\nСледующий (после текущего) элемент списка по итератору: " << show_data(curr);
				
				curr = to_prev(curr);
				cout << "\nПредыдущий (перед текущим) элемент списка по итератору: " << show_data(curr) << endl;
			}
		}break;
		case 16:
		{
			if (isEmpty(head))
			{
				cout << "Список пуст!" << endl;
			}
			else
			{
				int value, N;
				cout << "Введите кол-во элементов, которые хотите добавить во второй список: ";
				cin >> N;
				cout << "Введите значения, которое хотите добавить: ";
				for (int i = 1; i <= N; i++)
				{
					cin >> value;
					addHead(newHead, newTail, value);
				}
				cout << "\nПервый список:\n";
				outListHead(head);
				cout << "Второй список:\n";
				outListHead(newHead);
				cout << "Сцепление двух списков:\n";
				//первый способ реализации
				/*list_merging(head, tail, newHead, newTail);
				outListHead(head);*/

				//второй способ реализации
				list_concat(head, tail, newHead, newTail);
				outListHead(head);
			}

		}break;
		case 17:
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
				outListHead(head);
				int value;
				cout << "\nВведите значение, которое хотите добавить: ";
				cin >> value;
				bool check = insertPos(head, tail, pos, value);
				if (check == 0 && pos != 1)
				{
					cout << "\nТакой позиции нет или список пуст!\n";
				}
				else if (check == 0 && pos == 1)
				{
					addHead(head, tail, value);
					cout << "\nПосле вставки элемента на позицию " << pos << endl;
					outListHead(head);
				}
				else
				{
					cout << "\nПосле вставки элемента на позицию " << pos << endl;
					outListHead(head);
				}
			}


		}break;
		case 18:
		{
			clearFromHead(head);
			cout << "Список очищен.\n";

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

