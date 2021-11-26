﻿//Написать односвязный список и его функционал. + Добавить реверс
#include <iostream>

using namespace std;

//Ячейка нашего списка
struct Node
{
	int value;
	Node* nextPtr;

	Node(int _value) : value(_value), nextPtr(nullptr) {} //Конструктор
};



//Структура самого списка
struct list {
	Node* first; // указатель на первый элемент
	Node* last;  // указатель на последний элемент

	list() : first(nullptr), last(nullptr) {} //Конструктор

	//Проверка пустоты списка
	bool isEmpty() {
		return first == nullptr;
	}

	//Вставка в начало списка
	void pushTop(int _value)
	{
		Node* temp = new Node(_value);
		Node* p;
		if (isEmpty()) {
			first = temp;
			last = temp;
			return;
		}
		p = first;
		first = temp;
		first->nextPtr = p;
	}
	//Вставка в конец списка
	void pushBack(int _value) {
		Node* p = new Node(_value);
		if (isEmpty()) {
			first = p;
			last = p;
			return;
		}
		last->nextPtr = p;
		last = p;
	}
	//Вывод на экран
	void print() {
		if (isEmpty()) return;
		Node* p = first;
		while (p) {
			cout << p->value << " ";
			p = p->nextPtr;
		}
		cout << endl;
	}
	//Поиск значения
	Node* find(int _value) {
		Node* p = first;
		while (p && p->value != _value) p = p->nextPtr;
		return (p && p->value == _value) ? p : nullptr;
	}
	//Удалить первый элемент
	void removeFirst() {
		if (isEmpty()) return;
		Node* p = first;
		first = p->nextPtr;
		delete p;
	}
	//Удалить последний элемент
	int removeLast() {
		if (isEmpty()) return 0;
		int tmp(0);
		if (first == last) {
			tmp = first->value;
			removeFirst();
			return tmp;
		}
		Node* p = first;
		while (p->nextPtr != last) p = p->nextPtr;
		p->nextPtr = nullptr;
		delete last;
		last = p;
		tmp = last->value;
		return tmp;
	}
	//Удаление из списка по значению
	void remove(int _value) {
		if (isEmpty()) return;
		if (first->value == _value) {
			removeFirst();
			return;
		}
		else if (last->value == _value) {
			removeLast();
			return;
		}
		Node* slow = first;
		Node* fast = first->nextPtr;
		while (fast && fast->value != _value) {
			fast = fast->nextPtr;
			slow = slow->nextPtr;
		}
		if (!fast) {
			cout << "Not founded" << endl;
			return;
		}
		slow->nextPtr = fast->nextPtr;
		delete fast;
	}
	//Обращение к элементу списка по индексу
	Node* operator[] (const int index) {
		if (isEmpty()) return nullptr;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->nextPtr;
			if (!p) return nullptr;
		}
		return p;
	}
	int size() {
		if (isEmpty()) return 0;
		Node* p = first;

		int count(1);
		while (p->nextPtr != nullptr)
		{
			count++;
			p = p->nextPtr;
		}
		return count;
	}

	//Реверс списка
	list* reverse()
	{
		if (isEmpty()) return 0;
		Node* p = first;
		list* plist = new list();
		int tmp;
		for (int i = 0; i < size(); i++)
		{
			plist->pushTop(p->value);
			p = p->nextPtr;
		}
		return plist;
	}
};



int main() {
	list l;
	list* r;
	cout << "List is empty: " << l.isEmpty() << endl;
	l.pushBack(3);
	l.pushBack(123);
	l.pushBack(8);
	l.pushTop(555);
	l.pushTop(12);
	l.pushTop(32);
	l.print();
	cout << "Reverse list: " << l.isEmpty() << endl;
	r = l.reverse();
	r->print();
	cout << "Size of list: " << l.size() << endl;
	system("pause");
	return 0;
}