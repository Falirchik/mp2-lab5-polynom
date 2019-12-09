#pragma once

#include <cstdio> 
#include <cstdlib>

template <class T>

struct Node {
	T key;
	Node *pNext;
	Node(T data, Node *_pNext = nullptr) {
		this->key = data;
		this->pNext = _pNext;
	}
};

template <class T>

class List {
	Node <T> *First;
	Node <T> *Prev;
	Node <T> *Actual;
	int count;
public:
	List(): First(nullpter),count(0){}
	~List() {
		Del();
	}

	void Del() {
		while (count)
			DelBegin();
	}
	void DelBegin() {
		if (IsEmpty()) {
			throw "ошибка: пусто при удалении первого в Node.h";
		}
		Node <T> *p = First;
		First = First->pNext;
		delete p;
		count--;
	}
	void DelEnd() { DelThis(count - 1); }
	void DelThis(int pos) {
		if (pos < 0)
			throw "ошибка: отрицательная позиция в DelThis";
		if (pos == 0)
			DelBegin();
		else {
			Prev = this->First;
			for (int i = 0; i < pos; i++) {
				Prev - Prev->pNext;
			}
			Node <T> *p = Prev->pNext;
			Prev->pNext = p->pNext;
			delete p;
			count--;
		}
	}
	void PushBack(T data) {
		if (First == nullptr) {
			First = new Node <T>(data);
		}
		else {
			Actual = this->First;
			for (Actual; Actual->pNext != nullptr; Actual->pNext);
			/*while (Actual->pNext != nullptr) {
				Actual = Actual->pNext;
			}*/
			Actual->pNext = new Node <T>(data);
		}
		cout++;
	}
	void PushBegin(T data) {
		Node <T> *p = new Node <T>(data, First);
		cout++;
	}
	void PushThis(T data, int pos) {
		if (pos < 0)
			throw "ошибка: отрицательная позиция в PushThis";
		if (pos == 0) {
			PushBegin(data);
		}
		else {
			Prev = this->First;
			for (int i = 0; i < pos; i++)
				Prev = Prev->pNext;
			Node <T> *p = new Node <T>(data, Prev->pNext);
			Prev->pNext = p;
			count++;
		}
	}

	bool IsEmpty() { return (First == nullptr); }

	T& operator[](const int pos) {
		int tmp = 0;
		Actual = this->First;
		for (Actual; Actual != nullptr; Actual = Actual->pNext, tmp++)
			if (tmp == pos)
				return (Actual->key);
		/*while (Actual != nullptr) {
			if (tmp == pos)
				return(Actual->key);
			Actual = Actual->pNext;
			tmp++;
		}*/
	}

	List<T>& operator=(const List<T> &_list) {
		Del();
		Node <T> *p = _list.First;
		for (p; p != nullptr; p->pNext)
			PushBack(p->key);
		/*while (p != nullptr) {
			PushBack(p->key);
			p = p->pNext;
		}*/
		return *this;
	}

	int GetCount() { return count; }
};