#include "kit.h"
#include "vector.h"
#include <iostream>
using namespace std;

template<class DataType>
void Vector<DataType>::initItemsOfList(int size)
{
	for (int i = 0; i < size; i++) {
		cout << i << endl;
	}
	Vector<DataType>::start = new typename Vector<DataType>::List;/*
	Vector<DataType>::start->next = NULL;
	Vector<DataType>::start->prev = NULL;
	Vector<DataType>::start->item = -1;
	cout << Vector<DataType>::start << endl;
	cout<< Vector<DataType>::start->next << endl;
	cout << Vector<DataType>::start->prev << endl;
	cout << Vector<DataType>::start->item << endl;
	cout << endl << Vector<DataType>::size << endl;
	cout << capacity << endl;*/
}
