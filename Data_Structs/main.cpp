//#include "MyLinkedList.h"
#include "MyArrayList.h"
using namespace std;

int main()
{
	MyArrayList<int> arr(5);

	if (arr.Insert(9, 9) == false)
	{
		cout << "insert ½ÇÆÐ" << endl;
	}

	arr.Print();
	return 0;
}