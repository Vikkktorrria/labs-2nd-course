#include<iostream>
#include<iomanip>
#include<cassert>
#include"Functions.h"
using namespace std;

int menu()
{
	cout << "1 - �������� ������� � ������ ������" << endl;
	cout << "2 - �������� ������� � ����� ������" << endl;
	cout << "3 - ������� ������" << endl;
	cout << "4 - ������� � ��������� �������" << endl;
	cout << "5 - ������� ������� �� ������ ������" << endl;
	cout << "6 - ������� ������� �� ����� ������" << endl;
	cout << "7 - ������� ���� � �������� �������" << endl;
	cout << "8 - ����� ��������� ���� �� �������" << endl;
	cout << "9 - ����� ��������� ���� �� ��������" << endl;
	cout << "10 - �������� �� �������" << endl;
	cout << "11 - ���������� �������� ���� ������ �� ���������� ����" << endl;
	cout << "12 - ������� ���������� ���������" << endl;
	cout << "13 - ������� ���� �������" << endl;
	cout << "14 - �������� � �����������" << endl;
	cout << "15 - �������� ������" << endl;
	cout << "0 - �����" << endl;
	cout << "�������� ��������: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}

struct  Node {

	int data;   //�������������� ����
	Node* next; //�������� ����

};
Node* addHead(Node*& head, int value)
{
	Node* temp = new Node;  //����� ���� � ���������� �������
	temp->next = head;
	temp->data = value;
	head = temp;
	temp = to_tail(head);
	temp->next = head;
	return head;
}
Node* addTail(Node*& head, int value)
{
	if (head == NULL)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = NULL;
		head = temp;
	}
	else 
	{
		Node* newElem = new Node;  //����� ������� ������
		newElem->data = value; //������ ������
		newElem->next = NULL;
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		} // ����� ����� ������
		temp->next = newElem;  // ������������ ������ ��������
	}
	return head;
}
void outofList(Node* head)
{
	Node* temp = new Node;
	temp = head;
	do
	{
		cout << temp << ' ' << temp->data << '\t';
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}
Node* findData(Node* head, int value)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == value)
			return temp;
		temp = temp->next;
	}
	return NULL;
}
Node* findPos(Node* head, int pos)
{
	Node* temp = head;
	while (temp != NULL && pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	return temp;
}
int retrieve(Node* head, int pos)
{
	Node* temp = head;
	/*pos--;*/
	while (temp != NULL && pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	if (temp != NULL)
		return temp->data;
	else
		return NULL;
}
bool insertPos(Node* head, int pos, int value) 
{
	Node* p = findPos(head, pos - 1); //����� ����������� ����
	if (pos == 1)
		return false;
	else if (p == NULL) 
		return false;
	else
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = p->next;
		p->next = temp;
		return true;
	}
}
Node* removeHead(Node* head) 
{
	if (head == NULL) 
		return 0;
	Node* temp = head;   //��������� ���������� ����
 //������ ������ - ���  ��������� �� ��������� ���� �� ����������  
	head = temp->next;
	delete temp;        //������� ����
	return head;           //���������� ����� ������ ������
}
int removeTail(Node* head)
{
	if (head == NULL)
		return 0;
	else {
		Node* temp = head;
		Node* node_for_remove = NULL;
		while ((temp->next)->next != NULL)
		{
			temp = temp->next;
		} // ����� ����� ������
		node_for_remove = temp->next;
		temp->next = NULL;
		delete node_for_remove;  // �������� ������
	}
	return 1;
}
void remove(Node*& head, Node*& p) 
{
	if (head == p)
	{
		head = removeHead(head);
	}
	Node* temp = head;
	while (temp->next && temp->next != p)
	{
		temp = temp->next;
	}
	if (temp->next) 
	{
		temp->next = temp->next->next;
		delete p;
	}
}
void clear(Node*& head)
{
	while (head)
	{
		Node* next = head->next;
		delete head;
		head = next;
	}
}
bool isEmpty(Node* head)
{
	if (head == NULL)
		return true;
	else
		return false;
}
int countNode(Node* head) 
{
	Node* temp = head;
	int count = 0;
	while (temp != NULL) 
	{
		count++;
		temp = temp->next;
	}
	return count;
}


//=======�������������� �������=====
Node* list_merging(Node* head, Node* newHead)
{
	Node* result_list;
	result_list = head;
	while (newHead->next != NULL)
	{
		addTail(result_list, newHead->data);
		newHead = newHead->next;
	}
	addTail(result_list, newHead->data);
	return result_list;
}
Node* list_concat(Node* head, Node* NewHead)
{
	Node* temp = head;
	Node* NewTemp = NewHead;

	/*while (temp->next != NULL)
	{
		temp = temp->next;
	} */// ����� ����� ������� ������

	temp = to_tail(head); // �������� ������ ����� while
	temp->next = NewHead;
	return temp;
}
//==================================================================


//���������
Node* to_head(Node* head) { return head; }
Node* to_tail(Node* head)
{
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}
bool check_tail(Node* head)
{
	Node* temp = head;
	if (temp->next == NULL)
	{
		return true;
	}
}
int show_data(Node* curr) { return curr->data; }
bool to_pos(Node* head, Node*& curr, int pos)
{
	if (pos==1)
	{
		return false; //������� to_head
	}
	Node* p = findPos(head, pos); //����� ����
	if (p==NULL)
	{
		return false;
	}
	curr = p;
	return true;
}
Node* to_next(Node* curr) {	return curr->next; }

