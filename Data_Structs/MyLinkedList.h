#pragma once
#include <iostream>
#include <list>
using namespace std;

template<typename T>
struct Node
{
	Node<T>(){};
	Node * nextNode;
	T data;
};


template<typename T>
class MyList
{
public:

	MyList()
		:mSize(0)
	{ }


	//����
	void push_back(T data);
	void push_front(T data);
	bool insert(int index, T data);

	//����
	void pop_front();
	void pop_back();
	void erase(int index);

	//Ž��
	//find�� zero based index ���
	Node<T> * find(int idx);
	Node<T> * back();
	Node<T> * front() const;

	//����
	const bool empty()const;
	const int size()const;
	void Print();

private:

	Node<T> * mHead;
	//one based
	int mSize;
};

//����//////////////////////////////////////////////////////////////////
template<typename T>
void MyList<T>::push_back(T data)
{
	Node<T> * source = new Node<T>();
	source->data = data;
	source->nextNode = nullptr;

	//1. ����Ʈ�� ���� ������츦 ����Ʈ�� ����带 �����Ѵ�.
	if (empty() == true)
	{	
		mHead = source;
		mSize++;
		return;
	}

	//2. ����Ʈ�� ���� ���� ��� ������ ��带 ã�Ƴ���.
	Node<T> * dest = back();
	dest->nextNode = source;
	mSize++;
	return;
}

template<typename T>
inline void MyList<T>::push_front(T data)
{
	Node<T> * source = new Node<T>();
	source->data = data;
	source->nextNode = nullptr;

	//1.����尡 ������� Ȯ���Ѵ�.
	if (empty() == true)
	{
		mHead = source;
		++mSize;
		return;
	}

	//2-2.����尡 ���� �ʾҴٸ�
	source->nextNode = mHead;
	mHead = source;
	++mSize;
	return;
}

template<typename T>
inline bool MyList<T>::insert(int index, T data)
{
	Node<T> * prev = find(index);
	if (prev == nullptr) return false;
	Node<T> * next = prev->nextNode;
	
	Node<T> * source = new Node<T>();
	source->data = data;
	source->nextNode = nullptr;

	if (next == nullptr)
	{
		prev->nextNode = source;
	}
	else 
	{
		prev->nextNode = source;
		source->nextNode = next;
	}

	++mSize;
	return true;
}

//����//////////////////////////////////////////////////////////////////
template<typename T>
inline void MyList<T>::pop_front()
{
	if (empty() == true) return;

	Node<T> * t = mHead->nextNode;
	delete(mHead);
	mHead = t;
	--mSize;
	return;
}

template<typename T>
inline void MyList<T>::pop_back()
{
	if (empty() == true) return;

	Node<T> * b = find(mSize - 2);
	delete(back());
	b->nextNode = nullptr;
	--mSize;
	return;
}

template<typename T>
inline void MyList<T>::erase(int index)
{
	Node<T> * t = find(index);
	if (t == nullptr) return;

	Node<T> * next = t->nextNode;
	Node<T> * prev = find(index - 1);
	prev->nextNode = next;
	delete(t);
	mSize--;
	return;
}

//Ž��//////////////////////////////////////////////////////////////////
template<typename T>
Node<T> * MyList<T>::find(int idx)
{
	//list�� ����ٸ�, ������ �̻��� ���� ã������ nullptr��ȯ
	if (empty() == true || mSize <= idx)
	{
		return nullptr;
	}

	//list�� ���� ��� ������
	Node<T> * t = mHead;
	for (int i = 0; i < idx; ++i)
	{
		t = t->nextNode;
	}
	
	return t;
}

template<typename T>
inline Node<T>* MyList<T>::back()
{
	//1-1. ����Ʈ�� ���� ���� ���
	if (empty() == true) return nullptr;

	//1-2. ����Ʈ�� ���� ���� ��� ������ ��带 ã�Ƴ���.
	Node<T> * t = mHead;
	while (t->nextNode != nullptr)
	{
		t = t->nextNode;
	}
	return t;
}

template<typename T>
inline Node<T>* MyList<T>::front() const
{
	return mHead;
}

//����//////////////////////////////////////////////////////////////////
template<typename T>
inline const bool MyList<T>::empty() const
{
	return (0 == mSize ? true : false);
}

template<typename T>
inline const int MyList<T>::size() const
{
	return mSize;
}

template<typename T>
void MyList<T>::Print()
{
	if (empty() == true)
	{
		cout << "Size is Zero!" << '\n';
		return;
	}

	Node<T> * t = mHead;
	while (t->nextNode != nullptr)
	{
		cout << t->data << " ";
		t = t->nextNode;
	}
	cout << t->data << endl;
}