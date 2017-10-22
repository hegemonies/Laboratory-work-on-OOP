//#pragma once
#ifndef VECTOR_H
#define VECTOR_H7

#include "kit.h"


template<class DataType>
class Vector : public Kit<DataType>
{
	int capacity;
public:
	/*
	Vector() : Kit<DataType>(100)	{ capacity = 0; }

	Vector(int s) : Kit<DataType>(100)
	{
		capacity = s;
		initItemsOfList(s);
	}
	*/
	void initItemsOfList(int);
	/*
	int countItemsOfList();
	void addInList(DataType, int);
	void deleteItemOfList(int);
	void moveItemOfList(int, int);
	*/
};

#endif