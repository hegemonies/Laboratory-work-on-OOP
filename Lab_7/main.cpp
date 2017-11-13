#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define CHECK_MALLOC(X) ({ \
		if((X)==NULL) { \
			cerr << "main.c: Error allocating memory\n"; \
			exit(1); \
		}; })

struct purchaseData
{
	int number;
	int price;
	int quantity;
	string name;
};

class List
{
protected:
	struct list {
		list *next;
		purchaseData *data;
	};
	unsigned int totalSize;
	unsigned int capacity;
	unsigned int size;
	list *start;
public:
	List(void)
	{
		capacity = 0;
		size = 100;
		totalSize = 500;
		start = NULL;
	}

	List(unsigned int cpct)
	{
		size = 100;
		totalSize = 500;
		if (cpct >= size || cpct >= totalSize) {
			cerr << "Too many member capacity\n";
			exit(1);
		}
		capacity = cpct;

		for (unsigned int i = 0; i < capacity; i++) {
			if (i == 0) {
				start = new list;
				start->next = NULL;
				start->data = new purchaseData;
				start->data->number = 0;
				start->data->price = 0;
				start->data->quantity = 0;
				start->data->name = "";
			} else {
				list *node = new list;
				node->next = NULL;
				node->data = new purchaseData;
				node->data->number = 0;
				node->data->price = 0;
				node->data->quantity = 0;
				node->data->name = "";

				list *tmp = start;

				while (tmp->next) {
					tmp = tmp->next;
				}

				tmp->next = node;
			}

		}
	}

	~List(void)
	{
		list *prev = start;
		list *next = start->next;

		while (next != NULL) {
			delete prev;
			prev = next;
			next = next->next;
		}
	}

	void push(string nm, int prc, int qt)
	{
		try {
			if (capacity >= totalSize) {
				throw 1;
			}
		} catch (...) {
			cerr << "Out of the array/n";
			exit(1);
		}

		list *node = start;

		if (!node) {
			//capacity++;
			start = new list;
			CHECK_MALLOC(start);
			start->next = NULL;
			start->data = new purchaseData;
			CHECK_MALLOC(start->data);
			start->data->number = capacity;
			start->data->price = prc;
			start->data->quantity = qt;
			start->data->name = nm;
			return;
		}

		for (unsigned int i = 0; i < capacity; i++) {
			node = node->next;
		}

		if (capacity >= size && capacity + 1 < totalSize) {
			capacity++;
			size++;
			node->next = new list;
			CHECK_MALLOC(node->next);
			node->next->next = NULL;
			node->next->data = new purchaseData;
			CHECK_MALLOC(node->next->data);
			node->next->data->number = capacity;
			node->next->data->price = prc;
			node->next->data->quantity = qt;
			node->next->data->name = nm;
			return;
		}

		capacity++;
		list *tmp = node;
		node = node->next;
		node = new list;
		CHECK_MALLOC(node);
		node->next = NULL;
		node->data = new purchaseData;
		CHECK_MALLOC(node->data);
		node->data->number = capacity;
		node->data->price = prc;
		node->data->quantity = qt;
		node->data->name = nm;
		tmp->next = node;
	}

	void deleteItem(purchaseData *item)//TODO poheril
	{
		list *node = start;
		list *prev;

		for (unsigned int i = 0; i < capacity - 1; i++) {
			if (node->data == item) {
				break;
			}
			prev = node;
			node = node->next;
		}

		if (node->data != item) {
			return;
		}

		prev->next = node->next;

		delete node;
	}

	void print(void)
	{
		list *node = start;
		cout << "capacity = " << capacity << endl;
		for (unsigned int i = 0; i < capacity + 1; i++) {
			cout << node->data->number << " ";
			cout << node->data->name << " ";
			cout << node->data->price << " ";
			cout << node->data->quantity << " ";
			node = node->next;
			cout << "\n";
		}

	}
};

int main(void)
{
	List list;

	list.push("Apple", 20, 1);
	list.push("Book", 320, 1);
	list.push("Ticket", 190, 2);

	list.print();
	
	return 0;
}