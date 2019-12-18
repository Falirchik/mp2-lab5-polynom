#pragma once
#include "monom.h"



template <class T>
class List {
	struct Node {
		T data;
		Node *pNext,
			*pPrev;
	};
	Node *pFirst,				//первое звено
		*pLast,					//последнее
		*pFict,					//фиктивное для работы
		*pCurr;					//текущее
public:
	List() { 
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pFict = nullptr;
	};
	List(const List<T> &_l);
	~List() { DelAll(); };

	T GetData() { return pCurr->data; }
	void SetData(T _data) { pCurr->data = _data; }
	void CurrInFirst() { pCurr = pFirst; }

	void DelAll();
	void DelFirst();
	void DelLast();
	void DelCur();
	void StepForward() { pCurr = pCurr->pNext; };
	void StepBack() { pCurr = pCurr->pPrev; };

	void InFirst(T _data);
	void InLast(T _data);
	void InFict(T _data);
	void InCurr(T _data);

	bool IsEmpty();
	bool IsEnd();
	bool IsLast();

	
};

template<class T>
inline List<T>::List(const List<T>& _l){
	pFirst = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
	Node *tmp = _l.pFict;
	InFict(tmp->data);
	if (_l.pFirst != nullptr)
		tmp = tmp->pNext;
	for (tmp; (tmp != _l.pFict) && (tmp != nullptr); tmp = tmp->pNext)
		InLast(tmp->data);
}

template<class T>
inline void List<T>::DelAll(){
	for (pFirst; (pFirst != pFict) && (pFirst != nullptr); ) {
		Node *pp = pFirst;
		pFirst = pFirst->pNext;
		delete pp;
	}
	pFirst = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
}

template<class T>
inline void List<T>::DelFirst() {
	if (IsEmpty())
		throw "список пуст!";
	else {
		Node *p = pFirst->pNext;
		delete pFirst;
		pCurr = p;
		pFirst = pCurr;
		pCurr->pPrev = pFict;
		pFict->pNext = pCurr;
	}
}

template<class T>
inline void List<T>::DelLast(){
	Node *p = pLast;
	pCurr = pLast;
	StepBack();
	pCurr->pNext = pFict;
	pFict->pPrev = pCurr;
	pLast = pCurr;
	pCurr = pLast->pNext;
	delete p;
}

template<class T>
inline void List<T>::DelCur(){
	Node *p = pFict;
	if (p == pFirst)
		DelFirst();
	else if (p == pLast)
		DelLast();
	else {
		StepBack();
		pCurr->pNext = p->pNext;
		StepForward();
		pCurr->pPrev = p->pPrev;
		delete p;
	}
}

template<class T>
inline void List<T>::InFirst(T _data){
	Node *p = new Node;
	p->data = _data;
	if (!IsEmpty()) {
		p->pNext = pFirst;
		p->pPrev = pFict;
		pFirst->pPrev = p;
		pFict->pNext = p;
		pFirst = p;
	}
	else {
		p->pPrev = pFict;
		p->pNext = pFict;
		pFirst = p;
		pLast = p;
		pFict = p;
		pFict->pPrev = p;
		pFict->pNext = p;

	}
}

template<class T>
inline void List<T>::InLast(T _data){
	Node *p = new Node;
	p->data = _data;
	if (!IsEmpty()) {
		pLast->pNext = p;
		pFict->pPrev = p;
		p->pPrev = pLast;
		p->pNext = pFict;
		pLast = p;
	}
	else InFirst(_data);
}

template<class T>
inline void List<T>::InFict(T _data){
	pFict = new Node;
	pFict->data = _data;
	pCurr = pFict;
}

template<class T>
inline void List<T>::InCurr(T _data){
	Node *p = new Node;
	p->data = _data;
	if ((pCurr != pFirst) && (pFirst == nullptr)) {
		p->pPrev = pCurr->pPrev;
		p->pNext = pCurr;
		pCurr->pPrev = p;
		StepBack(); StepBack();
		pCurr->pNext = p;
	}
	else InFirst(_data);
}

template<class T>
inline bool List<T>::IsEmpty(){
	if (pFirst != nullptr)
		return false;
	else return true;
}

template<class T>
inline bool List<T>::IsEnd(){
	if (pCurr != pFict)
		return false;
	else return true;
}

template<class T>
inline bool List<T>::IsLast(){
	if (pCurr!=pLast)
		return false;
	else return true;
}
