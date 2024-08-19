// 배열 : 번호가 붙은 원소들이 연속적인 형태로 구성된 구조
// (원소에 붙은 번호는 index라 부른다.)

// Constructor 일정한 길이의 빈 배열을 만든다.
// Read 주어진 위치에 있는 원소를 알아본다
// Add & Insert 주어진 위치에 새로운 원소를 대입한다
// Delete 주어진 위치에 있는 원소를 삭제한다.

#include <iostream>
#include <stdint.h>
using namespace std;
using int32 = __int32;
using uint32 = unsigned __int32;



// int를 담는 배열
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


	// 데이터 추가
	void PushBack(T val);
	void PushFront(T val);
	bool Insert(uint32 idx, T val);

	// 데이터 삭제
	void PopBack();
	void PopFront();
	bool Erase();

	// 데이터 출력
	void PrintSize() const;
	void Print() const;
	

private:
	// Getter & Setter 편의상 제거
	uint32 mSize;
	uint32 mCapacity;
	int32* mHead;
};

template<typename T>
void MyArrayList<T>::PushBack(T val)
{
	//Cap확인 필요
	

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
	//인덱스 유효한지 확인., 크기제한 확인
	if (mSize < idx || mCapacity == mSize) return false;


	//마지막부터 하나씩 땡기고 그 인덱스 도착하면 값 넣고 끝
	// i는 zero base
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
		cout << i << "번째 수 : " << *(mHead + i) << endl;
	}
}