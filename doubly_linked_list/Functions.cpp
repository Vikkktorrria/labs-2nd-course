#include<iostream>
#include<iomanip>
using namespace std;
#include "Functions.h"
int menu()
{
	cout << "1 - Добавить элемент в начало списка" << endl;
	cout << "2 - Добавить элемент в конец списка" << endl;
	cout << "3 - Вывести список с головы" << endl;
	cout << "4 - Вывести список с хвоста" << endl;
	cout << "5 - Удалить элемент из начала списка" << endl;
	cout << "6 - Удалить элемент из конца списка" << endl;
	cout << "7 - Удаление указанного узла из списка" << endl;
	cout << "8 - Проверка на пустоту" << endl;
	cout << "9 - Поиск указателя узла по позиции с начала" << endl;
	cout << "10 - Поиск указателя узла по позиции с конца" << endl;
	cout << "11 - Поиск указателя узла по значению с начала" << endl;
	cout << "12 - Поиск указателя узла по значению с конца" << endl;
	cout << "13 - Подсчет количества элементов списка" << endl;
	cout << "14 - Вернуть значение поля данных  из указанного узла" << endl;
	cout << "15 - Операции с итераторами" << endl;
	cout << "16 - Сцепление списков" << endl;
	cout << "17 - Добавить элемент в указанную позицию" << endl;
	cout << "18 - Очистить список" << endl;
	cout << "0 - Выход" << endl;
	cout << "Выберите действие: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
void addHead(Node*& head, Node*& tail, int val) 
{
	if (head == NULL)
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else
	{
		Node* temp = new Node;
		temp->next = head;
		temp->prev = NULL;
		temp->data = val;
		head->prev = temp;
		head = temp;
	}
}
void addTail(Node*& head, Node*& tail, int val) 
{
	if (head == NULL)
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else {
		Node* temp = new Node;  
		temp->data = val; 
		temp->next = NULL;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}
void outListHead(Node* head) 
{
	Node* temp = new Node;
	temp = head;
	while (temp != NULL) 
	{
		cout << ' ' << temp->data << '\t';
		temp = temp->next;
	}
	cout << endl;
}
void outListTail(Node* tail)
{
	Node* temp = new Node;
	temp = tail;
	while (temp != NULL)
	{
		cout << ' ' << temp->data << '\t';
		temp = temp->prev;
	}
	cout << endl;
}
Node* removeHead(Node* head)
{
	if (head == NULL)
	{
		return 0;
	}
	Node* temp = head;
	head = temp->next;
	head->prev = NULL;
	delete temp;
	return head;
}
Node* removeTail(Node* tail)
{
	if (tail == NULL)
	{
		return 0;
	}
	Node* temp = tail;
	tail = temp->prev;
	tail->next = NULL;
	delete temp;
	return tail;
}
void remove(Node*& head, Node*& tail, Node* p)
{
	if (head == p)//проверка на принадлежность узла к концам списка
	{ 
		head = removeHead(head); 
		return;
	}
	if (tail == p)
	{ 
		tail = removeTail(tail); 
		return;
	}
	if (p) 	//если p существует
	{
		p->prev->next = p->next;//изменяем указатель next левого соседа p->prev удаляемого узла  
		p->next->prev = p->prev;//изменяем указатель prev правого соседа p->next удаляемого узла 
		delete p; //удаляем узел
	}
}
void clearFromHead(Node*& head)
{
	while (head)
	{
		Node* next = head->next;
		delete head;
		head = next;
	}

}
void clearFromTail(Node*& tail)
{
	while (tail)
	{
		Node* prev = tail->prev;
		delete tail;
		tail = prev;
	}
}
Node* findDataHead(Node* head, int value)
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
Node* findPosHead(Node* head, int pos)
{
	Node* temp = head;
	while (temp != NULL && pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	return temp;
}
Node* findDataTail(Node* tail, int value)
{
	Node* temp = tail;
	while (temp != NULL)
	{
		if (temp->data == value)
			return temp;
		temp = temp->prev;
	}
	return NULL;
}
Node* findPosTail(Node* tail, int pos)
{
	Node* temp = tail;
	while (temp != NULL && pos > 1)
	{
		temp = temp->prev;
		pos--;
	}
	return temp;
}
bool isEmpty(Node* p)
{
	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool insertPos(Node*& head, Node*& tail, int pos, int value)
{
	Node* p = findPosHead(head, pos - 1); //поиск предыдущего узла
	if (pos == 1)
		return false;
	else if (p == NULL)
		return false;
	else
	{
		Node* temp = new Node;
		temp->next = p->next;
		temp->prev = p->prev;
		temp->data = value;
		p->next = temp;
		return true;
	}
}
int countElemHead(Node*& head)
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
int countElemTail(Node* tail)
{
	Node* temp = tail;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->prev;
	}
	return count;
}
int retrieve(Node* head, int pos)
{
	Node* p = head;
	p = findPosHead(head, pos);
	if (p != NULL)
		return p->data;
	else
		return NULL;
}



//=======ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ=====
void list_merging(Node*& head, Node*& tail, Node*& newHead, Node*& newTail)
{
	Node* result_list_head = head;
	Node* result_list_tail = tail;
	while (newHead->next != NULL)
	{
		addTail(result_list_head, result_list_tail, newHead->data);
		newHead = newHead->next;
	}
	addTail(result_list_head, result_list_tail, newHead->data);
	//return result_list_head;
}
Node* list_concat(Node*& head, Node*& tail, Node*& newHead, Node*& newTail)
{
	Node* tempHead = head;
	Node* NewTempHead = newHead;
	Node* tempTail = tail;
	Node* NewTempTail = newTail;

	tempTail->next = newHead;
	NewTempHead->prev = tail;
	return 	tempHead;
}


//ИТЕРАТОРЫ
Node* to_head(Node* head) { return head; }
Node* to_tail(Node* tail) { return tail; }
bool check_tail(Node* tail)
{
	Node* temp = tail;
	if (temp->next == NULL)
		return true;
	else
		return false;
}
int show_data(Node* curr) { return curr->data; }
bool to_pos(Node* head, Node*& curr, int pos)
{
	if (pos == 1)
	{
		return false; //функция to_head
	}
	Node* p = findPosHead(head, pos); //поиск узла
	if (p == NULL)
	{
		return false;
	}
	curr = p;
	return true;
}
Node* to_next(Node* curr) { return curr->next; }
Node* to_prev(Node* curr) { return curr->prev; }