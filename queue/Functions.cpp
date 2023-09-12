#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;

int menu()
{
	cout << "1 - Заполнить очередь" << endl;
	cout << "2 - Вывести очередь на экран" << endl;
	cout << "3 - Удалить элемент из головы" << endl;
	cout << "4 - Удалить элемент из хвоста" << endl;
	cout << "5 - Прочитать значение первого элемента очереди" << endl;
	cout << "6 - Прочитать значение последнего элемента очереди" << endl;
	cout << "7 - Проверка на пустоту" << endl;
	cout << "8 - Очистка очереди" << endl;
	cout << "9 - Вывод размера очереди" << endl;
	cout << "0 - Выход" << endl;
	cout << "Выберите действие: ";
	int i;
	cin >> i;
	cout << endl;
	return i;
}


//void еnqueue(int* arr, int SIZE, int &tail, int val) 
//{
//	arr[tail] = val;
//	if (tail == SIZE - 1) //проверка конца массива
//		tail = 0;
//	else tail++;
//
//}
void pushHead(int* arr, int SIZE, int& head, int& tail, int val)
{

	for (int i = SIZE - 1; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = val;
	head++;
	
}
void pushTail(int* arr, int SIZE, int &head, int& tail, int val)
{
	arr[head + tail] = val;
	tail++;

}
bool isEmpty(int* arr, int& head, int& tail) 
{
	if (head == 0 && tail == 0)
		return true;
	else
		return false;
}
void queue_out(int* arr, int SIZE, int head, int tail)
{
	/*while (head != tail)
	{
		cout << " " << arr[head] << " ";
		head++;
	}*/
	for (int i = 0; i < SIZE; i++)
	{
		cout << " " << arr[i] << " ";
	}
	cout << endl;
	/*cout << SIZE;*/
}
//int dequeue(int* arr, int SIZE, int& head) 
//{
//	int val = arr[head];
//	if (head == SIZE - 1)
//		head = 0;
//	else head++;
//	return val;
//
//}
int popHead(int*  arr, int& head, int& tail, int SIZE) 
{
	if (isEmpty(arr, head, tail)) 
		return -1;
	int x = arr[0];
	for (int i = 0; i < tail + head; i++)
		arr[i] = arr[i + 1];
	arr[SIZE - 1] = 0;
	head--;
	return x;
}
int popTail(int*  arr, int& head, int& tail, int SIZE) 
{
	if (isEmpty(arr, head, tail)) 
		return -1;
	int x = arr[head + tail - 1];
	arr[head + tail - 1] = 0;
	tail--;
	return x;
}
int peekHead(int* arr, int& head, int& tail) 
{
	if (isEmpty(arr, head, tail)) 
		return -1;
	return arr[0];
}

int peekTail(int*  arr, int& head, int& tail) 
{
	if (isEmpty(arr, head, tail)) 
		return -1;
	return arr[head + tail - 1];
}

int count(int*  arr, int& head, int& tail) 
{
	return head + tail;
}

void clear(int*  arr, int& head, int& tail, int SIZE)
{
	while (head != 0)
	{
		popHead(arr, head, tail, SIZE);
	}
	head = 0;
	while (tail != 0)
	{
		popTail(arr, head, tail, SIZE);
	}
	tail = 0;
}

//int peekHead(int* arr, int& head)
//{
//	if (arr[head])
//	{
//		return arr[head];
//	}
//	else return 0;
//}
//int peekTail(int* arr, int SIZE, int& tail)
//{
//	
//	if (tail == SIZE)    
//
//		return arr[tail-1];
//
//	else return 0;
//}
//void clear(int* arr, int SIZE, int& head, int& tail)
//{	
//	while (head!=SIZE)
//	{	
//			arr[head] = NULL;
//			head++;
//	}
//	head = 0;
//	tail = 0;
//
//}
//int count(int* arr, int SIZE, int head)
//{
//	int count = 0;
//	while (head != SIZE)
//	{
//		count++;
//		head++;
//	}
//	return count;
//}

