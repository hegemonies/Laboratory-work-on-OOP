#ifndef KIT_H
#define KIT_H

#include <iostream>

using namespace std;

template<class DataType>
class Kit {
protected:
	struct List
	{
		List *next;
		List *prev;
		DataType item;
	};
	int size;
	List *start = NULL;
public:
	Kit() {
		size = 500;
	}
	Kit(int s) {
		size = s;
	}
	virtual void initItemsOfList(int) = 0;/*
	virtual int countItemsOfList() = 0;
	virtual void addInList(DataType, int) = 0;
	virtual void deleteItemOfList(int) = 0;
	virtual void moveItemOfList(int, int) = 0;*/
};

#endif
