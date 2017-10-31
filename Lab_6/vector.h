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
		capacity = s;
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
			typename Vector<DataType>::List *node = Vector<DataType>::start;
			typename Vector<DataType>::List *save = node;
			for (int j = 0; j < i; j++) {
				save = node;
				node = node->next;
			}
			node = new (typename Vector<DataType>::List);
			node->prev = save;
			save->next = node;
			node->next = NULL;
			if ((typeid(DataType) == typeid(int)) 
					|| (typeid(DataType) == typeid(double)) 
					|| (typeid(DataType) == typeid(float)) 
					|| (typeid(DataType) == typeid(char))) {
				node->item = (DataType)i;//TODO
			}
		}
	}
	void print() {
		cout << "ROBIT" << endl;
		typename Vector<DataType>::List *node = Vector<DataType>::start;
		for (int i = 0; i < capacity; i++) {
			cout << "elem ¹" << i << endl;
			cout << "\t this = " << node << endl;
			cout << "\t prev = " << node->prev << endl;
			cout << "\t next = " << node->next << endl;
			cout << "\t item = " << node->item << endl;
			node = node->next;
		}
	}
	void addInList(DataType itm, int i) {
		try {
			if (i >= capacity) {
				throw 1;
			}
		} catch (int e) {
			cout << "Out of the array/n";
			exit(1);
		}
		typename Vector<DataType>::List *node = Vector<DataType>::start;
		for (int j = 0; j < i; j++) {
			node = node->next;
		}
		node->item = itm;
	}
	void deleteItemOfList(int i) {
		try {
			if (i >= capacity) {
				throw 1;
			}
		} catch (int e) {
			cout << "Out of the array/n";
			exit(1);
		}
		typename Vector<DataType>::List *node = Vector<DataType>::start;
		typename Vector<DataType>::List *save = node;
		for (int j = 0; j < i; j++) {
			save = node;
			node = node->next;
		}
		save->next = node->next;
		node->next->prev = save;
		capacity--;
		delete node;
	}
	/*
	int countItemsOfList();
	void addInList(DataType, int);
	void deleteItemOfList(int);
	void moveItemOfList(int, int);
	*/
	
	typename Vector<DataType>::List* operator[](int i) {
		try {
			if (i >= capacity) {
				throw 1;
			}
		} catch (int e) {
			cout << "Out of the array/n";
			exit(1);
		}
		typename Vector<DataType>::List *node = Vector<DataType>::start;
		for (int j = 0; j < i; j++) {
			node = node->next;
		}
		return node;
	}
};

#endif

