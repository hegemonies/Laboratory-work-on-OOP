#include "vector.h"
#include <iostream>
using namespace std;

template<> void Vector<int>::initItemsOfList(int)
{
	for (int i = 0; i < s; i++) {
		if (i == 0) {
			Vector<DataType>::start = new (typename Vector<DataType>::List);
			Vector<DataType>::start->prev = NULL;
			Vector<DataType>::start->next = NULL;
			if ((typeid(DataType) == typeid(int)) 
				|| (typeid(DataType) == typeid(double)) 
				|| (typeid(DataType) == typeid(float)) 
				|| (typeid(DataType) == typeid(char))) {
				Vector<DataType>::start->item = 0;
			}
			continue;
		}
		cout << i << endl;
	}
}

template<class DataType>
void Vector<DataType>::initItemsOfList(int s)
{
	for (int i = 0; i < s; i++) {
		if (i == 0) {
			Vector<DataType>::start = new (typename Vector<DataType>::List);
			Vector<DataType>::start->prev = NULL;
			Vector<DataType>::start->next = NULL;
			if ((typeid(DataType) == typeid(int)) 
				|| (typeid(DataType) == typeid(double)) 
				|| (typeid(DataType) == typeid(float)) 
				|| (typeid(DataType) == typeid(char))) {
				Vector<DataType>::start->item = 0;
			}
			continue;
		}
		cout << i << endl;
	}
}
