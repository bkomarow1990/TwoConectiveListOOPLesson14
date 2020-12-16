#pragma once
#include <iostream>
using namespace std;
template <typename T>
class DList
{
public:
	DList() = default;
	void pushFront(const T& data);
	const bool isEmpty()const;
	const size_t getSize()const;
	void print()const; //default print
	void printR()const; // reverse print
	void pushBack(const T& data);
	void eraseBack();
	void eraseFront();
	void clear();
	auto findNode(const T& value);
	void eraseElem(const T& value);
private:
	struct Node {
		Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr) 
			:data(data),next(next),prev(prev)
		{}

		T data;
		Node* next, * prev;

	};
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void DList<T>::pushFront(const T& data)
{
	Node* tmp = new Node(data, nullptr, head );
	if (isEmpty())
	{
		tail = tmp;
	}
	else {
		head->prev = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline const bool DList<T>::isEmpty() const
{
	return head==nullptr;
}

template<typename T>
inline const size_t DList<T>::getSize() const
{
	return size;
}

template<typename T>
inline void DList<T>::print() const
{
	Node* tmp = head;
	while (tmp!= nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	Node* tmp = tail;
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::pushBack(const T& data)
{
	Node* tmp = new Node(data, tail, nullptr);
	if (isEmpty())
	{
		head = tmp;
	}
	else {
		tail->next = tmp;
	}
	tail = tmp;
	++size;
}

template<typename T>
inline void DList<T>::eraseBack()
{
	if (isEmpty())
	{
		return;
	}
	if (size==1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
		return;
	}
		auto tmp = tail;
		tail = tail->prev;
		tail->next = nullptr;
}

template<typename T>
inline void DList<T>::eraseFront()
{
	if (isEmpty())
	{
		return;
	}
	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
		return;
	}
	// auto tmp = head;
	head = head->next;
	head->prev = nullptr;
}

template<typename T>
inline void DList<T>::clear()
{
	if (isEmpty())
	{
		return;
	}
	if (size==1)
	{
		eraseFront();
		return;
	}
	if (!isEmpty())
	{
		while (!isEmpty())
		{
			eraseFront();
		}
	}
}

template<typename T>
inline auto DList<T>::findNode(const T& value)
{
	Node* tmp = head;
	while (tmp != nullptr && tmp->data != value)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template<typename T>
inline void DList<T>::eraseElem(const T& value)
{
	Node* find = findNode(value);
	if (find != nullptr)
	{
		if (find==head)
		{
			find->next->prev = nullptr;
			find->next->next = tmp->next;
			return;
		}
		if (find==tail)
		{
			find->prev->next = nullptr;
			find->prev->prev = temp->prev;
			return;
		}
		--size;
		Node* tmp = find;
		find->prev->next = tmp->next;
		find->next->prev = tmp->prev;
		delete tmp;
		tmp = nullptr;
	}
}

