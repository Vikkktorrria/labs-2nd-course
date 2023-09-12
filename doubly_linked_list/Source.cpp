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
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> value;
			addHead(head, tail, value);

		}break;
		case 2:
		{
			int value;
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> value;
			addTail(head, tail, value);

		}break;
		case 3:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������ � ������:" << endl;
				outListHead(head);
			}
		}break;
		case 4:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������ � �����:" << endl;
				outListTail(tail);
			}
		}break;
		case 5:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "����� ��������� �������� �� ������:" << endl;
				outListHead(head);
				head = removeHead(head);
				cout << "\n����� �������� �������� �� ������:\n";
				outListHead(head);
			}

		}
		break;
		case 6:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "����� ��������� �������� �� �����:" << endl;
				outListHead(head);
				tail = removeTail(tail);
				cout << "\n����� �������� �������� �� �����:\n";
				outListHead(head);
			}

		}break;
		case 7:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������ �� ��������:\n";
				outListHead(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				Node* p = findPosHead(head, pos);
				remove(head, tail, p);
				cout << "\n������ ����� ��������:\n";
				outListHead(head);
			}


		}break;
	
		case 8:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������ �� ����!" << endl;
			}
		}break;
		case 9:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:\n";
				outListHead(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				cout << "��������� ��������� ����: " << findPosHead(head, pos) << endl;
				cout << "��������� �������� ����: " << show_data(findPosHead(head, pos)) << endl;
			}

		}break;
		case 10:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:\n";
				outListTail(tail);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				cout << "��������� ��������� ����: " << findPosTail(tail, pos) << endl;
				cout << "��������� �������� ����: " << show_data(findPosTail(tail, pos)) << endl;
			}

		}break;
		case 11:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:\n";
				outListHead(head);
				int value;
				cout << "\n������� ��������: ";
				cin >> value;
				cout << "��������� ��������� ����: " << findDataHead(head, value) << endl;
				cout << "��������� �������� ����: " << show_data(findDataHead(head, value)) << endl;
			}
			
		}break;
		case 12:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:\n";
				outListTail(tail);
				int value;
				cout << "\n������� ��������: ";
				cin >> value;
				cout << "��������� ��������� ����: " << findDataTail(tail, value) << endl;
				cout << "��������� �������� ����: " << show_data(findDataTail(tail, value)) << endl;
			}
			
		}break;
		case 13:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "���������� ��������� ������ �����: " << countElemHead(head) << endl;
			}

		}break;
		case 14:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:\n";
				outListHead(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				cout << "��������� ��������: " << retrieve(head, pos) << endl;

			}

		}break;
		case 15:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������:\n";
				outListHead(head);
				curr = to_head(head);
				cout << "\n������ ������� ������ �� ���������: " << show_data(curr);

				curr = to_tail(tail);
				cout << "\n��������� ������� ������ �� ���������: " << show_data(curr);

				to_pos(head, curr, 3);
				cout << "\n������ ������� ������ �� ���������: " << show_data(curr);

				curr = to_next(curr);
				cout << "\n��������� (����� ��������) ������� ������ �� ���������: " << show_data(curr);
				
				curr = to_prev(curr);
				cout << "\n���������� (����� �������) ������� ������ �� ���������: " << show_data(curr) << endl;
			}
		}break;
		case 16:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				int value, N;
				cout << "������� ���-�� ���������, ������� ������ �������� �� ������ ������: ";
				cin >> N;
				cout << "������� ��������, ������� ������ ��������: ";
				for (int i = 1; i <= N; i++)
				{
					cin >> value;
					addHead(newHead, newTail, value);
				}
				cout << "\n������ ������:\n";
				outListHead(head);
				cout << "������ ������:\n";
				outListHead(newHead);
				cout << "��������� ���� �������:\n";
				//������ ������ ����������
				/*list_merging(head, tail, newHead, newTail);
				outListHead(head);*/

				//������ ������ ����������
				list_concat(head, tail, newHead, newTail);
				outListHead(head);
			}

		}break;
		case 17:
		{

			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				int pos;
				cout << "������� �������, �� ������� ������ �������� �������: ";
				cin >> pos;
				cout << "\n�� ������� �������� �� ������� " << pos << endl;
				outListHead(head);
				int value;
				cout << "\n������� ��������, ������� ������ ��������: ";
				cin >> value;
				bool check = insertPos(head, tail, pos, value);
				if (check == 0 && pos != 1)
				{
					cout << "\n����� ������� ��� ��� ������ ����!\n";
				}
				else if (check == 0 && pos == 1)
				{
					addHead(head, tail, value);
					cout << "\n����� ������� �������� �� ������� " << pos << endl;
					outListHead(head);
				}
				else
				{
					cout << "\n����� ������� �������� �� ������� " << pos << endl;
					outListHead(head);
				}
			}


		}break;
		case 18:
		{
			clearFromHead(head);
			cout << "������ ������.\n";

		}break;
		case 0: return 0;
		default:"������� ���������!";
		}
		cout << endl;
		puts("������� ����� ������ ��� �����������");
		_getch();
		system("cls");
	}
	system("pause");
	return 0;
}

