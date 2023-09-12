#include<iostream>
#include<iomanip>
#include<cassert>
#include"Functions.h"
using namespace std;

int menu()
{
	cout << "1 - Добавить элемент в начало списка" << endl;
	cout << "2 - Добавить элемент в конец списка" << endl;
	cout << "3 - Вывести список" << endl;
	cout << "4 - Вставка в указанную позицию" << endl;
	cout << "5 - Удалить элемент из начала списка" << endl;
	cout << "6 - Удалить элемент из конца списка" << endl;
	cout << "7 - Удалить узел в заданной позиции" << endl;
	cout << "8 - Поиск указателя узла по позиции" << endl;
	cout << "9 - Поиск указателя узла по значению" << endl;
	cout << "10 - Проверка на пустоту" << endl;
	cout << "11 - Извлечение значения поля данных из указанного узла" << endl;
	cout << "12 - Подсчет количества элементов" << endl;
	cout << "13 - Слияние двух списков" << endl;
	cout << "14 - Операции с итераторами" << endl;
	cout << "15 - Очистить список" << endl;
	cout << "0 - Выход" << endl;
	cout << "Выберите действие: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}

struct  Node {

	int data;   //информационное поле
	Node* next; //адресное поле

};
Node* addHead(Node*& head, int value)
{
	Node* temp = new Node;  //новый узел – включаемый элемент
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
		Node* newElem = new Node;  //новый элемент списка
		newElem->data = value; //внести данные
		newElem->next = NULL;
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		} // Поиск конца списка
		temp->next = newElem;  // Привязывание нового элемента
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
	Node* p = findPos(head, pos - 1); //поиск предыдущего узла
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
	Node* temp = head;   //указатель удаляемого узла
 //начало списка - это  указатель на следующий узел из удаляемого  
	head = temp->next;
	delete temp;        //удаляем узел
	return head;           //возвращаем новое начало списка
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
		} // Поиск конца списка
		node_for_remove = temp->next;
		temp->next = NULL;
		delete node_for_remove;  // Удаление хвоста
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


//=======ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ=====
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
	} */// Поиск конца первого списка

	temp = to_tail(head); // итератор вместо цикла while
	temp->next = NewHead;
	return temp;
}
//==================================================================


//ИТЕРАТОРЫ
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
		return false; //функция to_head
	}
	Node* p = findPos(head, pos); //поиск узла
	if (p==NULL)
	{
		return false;
	}
	curr = p;
	return true;
}
Node* to_next(Node* curr) {	return curr->next; }

