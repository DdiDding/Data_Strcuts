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


	//삽입
	void push_back(T data);
	void push_front(T data);
	bool insert(int index, T data);

	//삭제
	void pop_front();
	void pop_back();
	void erase(int index);

	//탐색
	//find는 zero based index 사용
	Node<T> * find(int idx);
	Node<T> * back();
	Node<T> * front() const;

	//상태
	const bool empty()const;
	const int size()const;
	void Print();

private:

	Node<T> * mHead;
	//one based
	int mSize;
};

//삽입//////////////////////////////////////////////////////////////////
template<typename T>
void MyList<T>::push_back(T data)
{
	Node<T> * source = new Node<T>();
	source->data = data;
	source->nextNode = nullptr;

	//1. 리스트에 값이 없을경우를 디폴트로 헤드노드를 연결한다.
	if (empty() == true)
	{	
		mHead = source;
		mSize++;
		return;
	}

	//2. 리스트에 값이 있을 경우 마지막 노드를 찾아낸다.
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

	//1.헤드노드가 비었는지 확인한다.
	if (empty() == true)
	{
		mHead = source;
		++mSize;
		return;
	}

	//2-2.헤드노드가 비지 않았다면
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

//삭제//////////////////////////////////////////////////////////////////
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

//탐색//////////////////////////////////////////////////////////////////
template<typename T>
Node<T> * MyList<T>::find(int idx)
{
	//list가 비었다면, 사이즈 이상의 값을 찾으려면 nullptr반환
	if (empty() == true || mSize <= idx)
	{
		return nullptr;
	}

	//list에 값이 들어 있으면
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
	//1-1. 리스트에 값이 없을 경우
	if (empty() == true) return nullptr;

	//1-2. 리스트에 값이 있을 경우 마지막 노드를 찾아낸다.
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

//상태//////////////////////////////////////////////////////////////////
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