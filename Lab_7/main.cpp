#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

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

	purchaseData() = default;

	purchaseData(const purchaseData&) = default;

	purchaseData(int n, int p, int q, string nm) : number(n), price(p), quantity(q), name(nm) {};
};

struct list {
	list *next;
	purchaseData *data;
};

class List
{
protected:
	const int totalSize = 500;
	int capacity;
	int size;
	list *start;
public:
	List(void)
	{
		capacity = 0;
		size = 100;
		start = NULL;
	}

	/*List(int cpct)
	{
		size = 100;
		if (cpct >= size || cpct >= totalSize) {
			cerr << "Too many member capacity\n";
			exit(1);
		}
		capacity = cpct;

		for (int i = 0; i < capacity; i++) {
			if (i == 0) {
				start = new list;
				start->next = NULL;
				start->data = new purchaseData(0, 0, 0, "");
				CHECK_MALLOC(start->data);
				// start->data->number = 0;
				// start->data->price = 0;
				// start->data->quantity = 0;
				// start->data->name = "";
			} else {
				list *node = new list;
				node->next = NULL;
				node->data = new purchaseData(0, 0, 0, "");
				CHECK_MALLOC(node->data);
				// node->data->number = 0;
				// node->data->price = 0;
				// node->data->quantity = 0;
				// node->data->name = "";

				list *tmp = start;

				while (tmp->next) {
					tmp = tmp->next;
				}

				tmp->next = node;
			}

		}
	}*/

	~List(void)
	{
		list *prev = start;
		if (prev) {
			list *next = start->next;

			while (next != NULL) {
				delete prev;
				prev = next;
				next = next->next;
			}
		}
	}

	void append(string nm, int prc, int qt)
	{
		try {
			if (capacity >= totalSize) {
				throw;
			}
		} catch (...) {
			cerr << "Out of the array/n";
			exit(1);
		}

		list *node = start;

		if (!node) {
			start = new list;
			CHECK_MALLOC(start);
			start->next = NULL;
			start->data = new purchaseData(capacity, prc, qt, nm);
			CHECK_MALLOC(start->data);
			return;
		}

		for (int i = 0; i < capacity; i++) {
			node = node->next;
		}

		if (capacity >= size && capacity + 1 < totalSize) {
			capacity++;
			size++;
			node->next = new list;
			CHECK_MALLOC(node->next);
			node->next->next = NULL;
			node->next->data = new purchaseData(capacity, prc, qt, nm);
			CHECK_MALLOC(node->next->data);
			return;
		}

		capacity++;
		list *tmp = node;
		node = node->next;
		node = new list;
		CHECK_MALLOC(node);
		node->next = NULL;
		node->data = new purchaseData(capacity, prc, qt, nm);
		CHECK_MALLOC(node->data);
		tmp->next = node;
	}

	void push(string nm, int prc, int qt, int pos)
	{
		if (pos > capacity) {
			cerr << "Error: there is no such position.\n" << "position = " << pos << endl;
			return;
		}

		list *tmp = start;

		for (int i = 0; i < pos; i++) {
			tmp = tmp->next;
		}

		tmp->data->price = prc;
		tmp->data->quantity = qt;
		tmp->data->name = nm;
	}

	void deleteItem(purchaseData *item)//TODO poheril
	{
		list *node = start;
		list *prev;

		for (int i = 0; i < capacity - 1; i++) {
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
		cout << "capacity = " << capacity + 1 << endl;
		for (int i = 0; i < capacity + 1; i++) {
			cout << node->data->number << " ";
			cout << node->data->name << " ";
			cout << node->data->price << " ";
			cout << node->data->quantity << " ";
			node = node->next;
			cout << "\n";
		}

	}

	int getCapacity()
	{
		return capacity;
	}

	list *operator[] (int n)
	{
		if (n > capacity) {
			return NULL;
		}
		list *node = start;

		for (int i = 0; i < n; i++) {
			node = node->next;
		}

		return node;
	}
};

class Sheet
{
	int height;
	const int width = 3;

	List list;

	List preplist;
	
public:
	Sheet()
	{
		preplist.append("Apple", 20, 1);
		preplist.append("Book", 320, 1);
		preplist.append("Ticket", 190, 1);
		preplist.append("Khunjut", 12, 1);
		preplist.append("Juice", 65, 1);
		preplist.append("Milk", 34, 1);
		preplist.append("Popcorn", 150, 1);
		preplist.append("Eggs", 27, 1);
		preplist.append("Sausage", 340, 1);
	}

	void add(int n, int qt)
	{
		// list *node = preplist[n - 1];
		list.append(preplist[n - 1]->data->name, preplist[n - 1]->data->price, preplist[n - 1]->data->quantity * qt);
	}

	void print(List &list, bool own)
	{
		cout << "       " << setw(5);
		cout << "Name";
		cout << "\t" << "Price";

		if (own) {
			cout << "\t" << "Quantity";
			cout << setw(9) << "Amount";	
		}
		cout << "\n";

		int k = own ? 3 : 0;

		for (int i = 0; i < width + k; i++) {
			cout << "-------";
		}
		cout << endl;

		for (int i = 0; i < list.getCapacity() + 1; i++) {

			if (!list.getCapacity() && !list[0]) {
				break;
			}

			cout << setw(4) << list[i]->data->number + 1 << "  |";
			cout << "\t" << list[i]->data->name;
			cout << "\t" << list[i]->data->price;
			if (own) {
				cout << "\t" << list[i]->data->quantity;
				cout << "\t" << setw(5) << list[i]->data->price * list[i]->data->quantity;
			}
			cout << "\n";
		}
	}

	void print(string name_list)
	{
		if (name_list == "self") {
			cout << "\n";
			print(list, true); 
		} else if (name_list == "prep") {
			cout << "\n";
			print(preplist, false);
		} else {
			cout << "Error name list\n";
		}
	}

	void buy(void)
	{
		int sum = 0;
		for (int i = 0; i < list.getCapacity() + 1; i++) {
			sum += (list[i]->data->price * list[i]->data->quantity);
		}

		cout << "\nSuccessful! You made a purchase on " << sum << "\n";
	}
};

int main(void)
{
	Sheet sheet;

	sheet.print("prep");

	sheet.add(4, 1);
	sheet.add(6, 1);
	sheet.add(8, 1);

	sheet.print("self");

	sheet.buy();

	return 0;
}