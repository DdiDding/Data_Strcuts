// �迭 : ��ȣ�� ���� ���ҵ��� �������� ���·� ������ ����
// (���ҿ� ���� ��ȣ�� index�� �θ���.)

// Constructor ������ ������ �� �迭�� �����.
// Read �־��� ��ġ�� �ִ� ���Ҹ� �˾ƺ���
// Add & Insert �־��� ��ġ�� ���ο� ���Ҹ� �����Ѵ�
// Delete �־��� ��ġ�� �ִ� ���Ҹ� �����Ѵ�.

#include <iostream>
#include <stdint.h>
using namespace std;
using int32 = __int32;
using uint32 = unsigned __int32;



// int�� ��� �迭
template<typename T>
class MyArrayList
{
public:
	MyArrayList(uint32 capacity)
		:mSize(0), mCapacity(capacity)
	{
		mHead = new int32[capacity];
	}

	~MyArrayList()
	{
		delete(mHead);
	}


	// ������ �߰�
	void PushBack(T val);
	void PushFront(T val);
	bool Insert(uint32 idx, T val);

	// ������ ����
	void PopBack();
	void PopFront();
	bool Erase();

	// ������ ���
	void PrintSize() const;
	void Print() const;
	

private:
	// Getter & Setter ���ǻ� ����
	uint32 mSize;
	uint32 mCapacity;
	int32* mHead;
};

template<typename T>
void MyArrayList<T>::PushBack(T val)
{
	//CapȮ�� �ʿ�
	

	mHead[mSize] = val;
	//*(mHead + mSize) = val;
	++mSize;
}

template<typename T>
void MyArrayList<T>::PushFront(T val)
{
	*(mHead + mSize) = val;
	++mSize;
}


template<typename T>
bool MyArrayList<T>::Insert(uint32 idx, T val)
{
	//�ε��� ��ȿ���� Ȯ��., ũ������ Ȯ��
	if (mSize < idx || mCapacity == mSize) return false;


	//���������� �ϳ��� ����� �� �ε��� �����ϸ� �� �ְ� ��
	// i�� zero base
	for (uint32 i = mSize; idx <= i; --i)
	{
		if (idx == i)
		{
			*(mHead + i) = val;
		}
		else
		{
			*(mHead + i) = *(mHead + i - 1);
		}
	}

	++mSize;
	return true;
}

template<typename T>
void MyArrayList<T>::Print() const
{
	for (uint32 i = 0; i < mSize; ++i)
	{
		cout << i << "��° �� : " << *(mHead + i) << endl;
	}
}