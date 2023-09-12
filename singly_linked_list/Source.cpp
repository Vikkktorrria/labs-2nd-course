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
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> value;
			head = addHead(head, value);

		}break;
		case 2:
		{
			int value;
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> value;
			head = addTail(head, value);

		}break;
		case 3:
		{
			if (isEmpty(head))
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				cout << "������:" << endl;
				outofList(head);
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
				int pos;
				cout << "������� �������, �� ������� ������ �������� �������: ";
				cin >> pos;
				cout << "\n�� ������� �������� �� ������� " << pos << endl;
				outofList(head);
				int value;
				cout << "������� ��������, ������� ������ ��������: ";
				cin >> value;
				bool check = insertPos(head, pos, value);
				if (check == 0 && pos != 1)
				{
					cout << "\n����� ������� ��� ��� ������ ����!\n";
				}
				else if (check == 0 && pos == 1)
				{
					head = addHead(head, value);
					cout << "\n����� ������� �������� �� ������� " << pos << endl;
					outofList(head);
				}
				else
				{
					cout << "\n����� ������� �������� �� ������� " << pos << endl;
					outofList(head);
				}
			}

			
		}break;
		case 5:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������ �� ��������:\n";
				outofList(head);
				head = removeHead(head);
				cout << "\n����� �������� �������� �� ������:\n";
				outofList(head);
			}	
		}
		break;
		case 6:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������ �� ��������:\n";
				outofList(head);
				removeTail(head);
				cout << "\n����� �������� �������� �� �����\n";
				outofList(head);
			}
			
		}break;
		case 7:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������ �� ��������:\n";
				outofList(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				Node* p = findPos(head, pos);
				remove(head, p);
				cout << "\n������ ����� ��������:\n";
				outofList(head);
			}

		}break;
		case 8:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������:\n";
				outofList(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				cout << "��������� ��������� ����: " << findPos(head, pos) << endl;
			}

		}break;
		case 9:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������:\n";
				outofList(head);
				int value;
				cout << "\n������� ��������: ";
				cin >> value;
				cout << "��������� ��������� ����: " << findData(head, value) << endl;
			}
			
		}break;
		case 10:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
				cout << "������ �� ����!" << endl;
		}break;
		case 11:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������:\n";
				outofList(head);
				int pos;
				cout << "\n������� �������: ";
				cin >> pos;
				cout << "��������� ��������: " << retrieve(head, pos) << endl;
			}

		}break;

		case 12:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "���������� ��������� ������ �����: " << countNode(head) << endl;
			}
			
		}break;
		case 13:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				int value, N;
				cout << "������� ���-�� ���������, ������� ������ �������� �� ������ ������: ";
				cin >> N;
				cout << "������� ��������, ������� ������ ��������: ";
				for (int i = 1; i <= N; i++)
				{
					cin >> value;
					newHead = addHead(newHead, value);
				}
				cout << "\n������ ������:\n";
				outofList(head);
				cout << "����� ������:\n";
				outofList(newHead);
				cout << "������� ���� �������:\n";
				/*������ ������� ����������*/
				list_merging(head, newHead);
				outofList(head);

				//������ ������� ����������
				/* list_concat(head, newHead);
				outofList(head);*/
			}

		}break;
		case 14:
		{
			if (isEmpty(head))
				cout << "������ ����!" << endl;
			else
			{
				cout << "������:\n";
				outofList(head);
				curr = to_head(head);
				cout << "\n������ ������� ������ �� ���������: " << show_data(curr);

				curr = to_tail(head);
				cout << "\n��������� ������� ������ �� ���������: " << show_data(curr);

				to_pos(head, curr, 2);
				cout << "\n������ ������� ������ �� ���������: " << show_data(curr);

				curr = to_next(curr);
				cout << "\n��������� (����� ��������) ������� ������ �� ���������: " << show_data(curr) << endl;
			}
			

		}break;
		case 15:
		{
			cout << "������ ������.\n";
			clear(head);
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

