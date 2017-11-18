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

struct listNode {
	listNode *next;
	purchaseData *data;
};

class List
{
protected:
	const int totalSize = 500;
	int capacity;
	int size;
	listNode *start;
public:
	List(void)
	{
		capacity = 0;
		size = 100;
		start = NULL;
	}

	~List(void)
	{
		listNode *prev = start;
		if (prev) {
			listNode *next = start->next;

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

		listNode *node = start;

		if (!node) {
			start = new listNode;
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
			node->next = new listNode;
			CHECK_MALLOC(node->next);
			node->next->next = NULL;
			node->next->data = new purchaseData(capacity, prc, qt, nm);
			CHECK_MALLOC(node->next->data);
			return;
		}

		capacity++;
		listNode *tmp = node;
		node = node->next;
		node = new listNode;
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

		listNode *tmp = start;

		for (int i = 0; i < pos; i++) {
			tmp = tmp->next;
		}

		tmp->data->price = prc;
		tmp->data->quantity = qt;
		tmp->data->name = nm;
	}

	void deleteItem(purchaseData *item)//TODO poheril
	{
		listNode *node = start;
		listNode *prev;

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
		listNode *node = start;
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

	listNode *operator[] (int n)
	{
		if (n > capacity) {
			return NULL;
		}
		listNode *node = start;

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


	List preplist;
	
public:
	List list;
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
		if (n > preplist.getCapacity()) {
			return;
		}
		list.append(preplist[n - 1]->data->name, preplist[n - 1]->data->price, preplist[n - 1]->data->quantity * qt);
		height++;
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
		if (!list.getCapacity()) {
			cout << "Basket is empty.\n";
			return;
		}
		int sum = 0;
		for (int i = 0; i < list.getCapacity() + 1; i++) {
			sum += (list[i]->data->price * list[i]->data->quantity);
		}

		cout << "\nSuccessful! You made a purchase on " << sum << "\n";
	}

	void search(string nm)
	{
		listNode *node = preplist[0];

		while ((node != 0) && (node->data->name != nm)) {
			node = node->next;
		}
		if (node) {
			cout << node->data->name << " is found. His number is " << node->data->number + 1 << endl;
		}
		cout << "There is no such element\n";
	}
};

void help(void)
{
	cout << "All terms:\n";
	cout << "add : Add item in basket.\n";
	cout << "buy : Buy all item of basket.\n";
	cout << "search : Search item in list.\n";
}

int main(void)
{
	Sheet sheet;

	sheet.print("prep");

	string answer;
	bool first = true;

	while (answer != "exit") {
		if (first) {
			help();
			first = false;
		}

		cout << ">>>";
		getline(cin, answer);

		if (answer == "add") {
			cout << "Enter number of item: ";
			getline(cin, answer);

			int n = stoi(answer);

			cout << "Enter amount: ";
			getline(cin, answer);

			int a = stoi(answer);

			sheet.add(n, a);
			cout << endl;
			sheet.print("self");
			cout << endl;
			continue;
		}

		if (answer == "help") {
			help();
			continue;
		}

		if (answer == "search") {
			cout << "Enter name of item: ";
			getline(cin, answer);
			sheet.search(answer);
			continue;
		}

		if (answer == "buy") {
			sheet.buy();
			continue;
		}
		continue;
	}

	return 0;
}