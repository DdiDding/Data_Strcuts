#pragma once
#include <iostream>
#include "MyLinkedList.h"

//
//template<typename T>
//void MyList<T>::erase(T data)
//{
//
//}
//
//template<typename T>
//bool MyList<T>::empty()
//{
//	return false;
//}
//
//template<typename T>
//const int MyList<T>::size() const
//{
//	return size;
//}
//

int main()
{
	MyList<int> list;
	list.push_back(3);
	list.push_back(4);
	list.Print();

	list.push_front(2);
	list.push_front(1);
	list.Print();

	/*list.pop_back();
	list.Print();

	list.pop_front();
	list.Print();*/

	list.erase(1);
	list.Print();

	//cout << list.back()->data<<endl;

	return 0;
}

