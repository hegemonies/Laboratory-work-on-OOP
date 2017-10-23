#pragma once
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
	unsigned int size;
	List *start;
public:
	Kit() {
		size = 500;
	}
	Kit(int s) {
		size = s;
	}
	virtual void initItemsOfList(int) = 0;
	/*
	virtual int countItemsOfList() = 0;
	virtual void addInList(DataType, int) = 0;
	virtual void deleteItemOfList(int) = 0;
	virtual void moveItemOfList(int, int) = 0;
	*/
};