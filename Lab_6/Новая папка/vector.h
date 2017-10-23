#ifndef VECTOR_H
#define VECTOR_H

#include "kit.h"
#include <typeinfo>

#include <iostream>

using namespace std;

template<class DataType>
class Vector : public Kit<DataType>
{
	int capacity;
public:
	Vector() : Kit<DataType>() { capacity = 0; }

	Vector(int s) : Kit<DataType>(100)
	{
		capacity = s;
		initItemsOfList(s);
	}
	void initItemsOfList(int s)
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
					cout << Vector<DataType>::start->item << endl;
				}
				continue;
			}
			cout << typeid(DataType).name() << endl;
		}
		// typename Vector<DataType>::List *start = NULL;
		// start = new typename Vector<DataType>::List;
		// start->item = size;
		// cout << "size: " << start->item << endl;
		// cout << "capacity: " << capacity << endl;
	}


	/*
	int countItemsOfList();
	void addInList(DataType, int);
	void deleteItemOfList(int);
	void moveItemOfList(int, int);
	*/
};

#endif
