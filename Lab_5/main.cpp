#include <iostream>
#include <cstdlib>
using namespace std;

class Kit
{
protected:
	int *list;
	int size;
	static const int maxSize = 500;
public:
	Kit()
	{
		cout << "\n\tPlease set a length\n";
		exit(1);
	}
	Kit(int s)
	{
		if (s >= 0 && s <= maxSize) {
			size = s;
			try {
				list = new int[size];
			} catch (bad_alloc xa) {
				cout << "\n\tBad allocation :(\n";
				exit(1);
			}
		} else if (s > maxSize) {
			size = 500;
			try {
				list = new int[size];
			} catch (bad_alloc xa) {
				cout << "\n\tBad allocation :(\n";
				exit(1);
			}
		} else {
			size = 0;
			try {
				list = new int[size];
			} catch (bad_alloc xa) {
				cout << "\n\tBad allocation :(\n";
				exit(1);
			}
		}
	}
	~Kit()
	{
		delete []list;
	}
	virtual void putItem(int) = 0;
	virtual int getItem() = 0;
};

class Queue : public Kit
{
	int putLock;
	int getLock;
public:
	Queue() : Kit() {}
	Queue(int size) : Kit(size) { putLock = getLock = 0; }

	void putItem(int item) {
		if (putLock >= size) {
			list[putLock % size] = item;
			getLock++;
			putLock++;
		} else {
			list[putLock++] = item;
		}
	}

	int getItem() {
		if (getLock == putLock) {
			cout << "\tEmpty queue.\n";
			return -1;
		}
		if (getLock >= size) {
			getLock = 0;
		}

		return list[getLock++];
	}

	void printQueue() {
		cout << "list = { ";
		for (int i = 0; i < size; i++) {
			cout << list[i];
			if (i < size - 1)
				cout << ", ";
		}
		cout << " }\n";
	}
};

class Stek : public Kit
{
	int capacity;
public:
	Stek() : Kit() {}
	Stek(int size) : Kit(size) { capacity = -1; }

	void putItem(int item) {
		if (capacity == size - 1) {
			cout << "\tStek is full.\n";
			return;
		}
		capacity++;
		list[capacity] = item;
	}

	int getItem() {
		if (capacity < 0) {
			cout << "\tStek is empty.\n";
			return -1;
		}
		return list[capacity--];
	}

	void printStek() {
		cout << "list = { ";
		for (int i = 0; i < size; i++) {
			cout << list[i];
			if (i < size - 1)
				cout << ", ";
		}
		cout << " }\n";
	}
};

int main(void)
{
	string answer;

	while (answer != "exit") {
		cout << "set \"1\" that select a Queue\n";
		cout << "set \"2\" that select a Stek\n";
		cout << "answer: ";
		getline(cin, answer);
		if (answer == "1") {
			cout << "set a size of Queue: ";
			getline(cin, answer);
			int size = atoi(answer.c_str());
			Queue queue(size);
			while (answer != "exit") {
				cout << "select \"1\" that put item\n";
				cout << "select \"2\" that get item\n";
				cout << "select \"3\" that exit from this menu\n";
				cout << "answer: ";
				getline(cin, answer);
				if (answer == "1") {
					cout << "enter a item: ";
					getline(cin, answer);
					int item = atoi(answer.c_str());
					queue.putItem(item);
					queue.printQueue();
				} else if (answer == "2") {
					cout << "get item = " << queue.getItem() << endl;
					queue.printQueue();
				} else if (answer == "3") {
					break;
				} else {
					cout << "Please enter 1, 2 or 3.\n";
				}
			}
		} else if (answer == "2") {
			cout << "set a size of Stek: ";
			getline(cin, answer);
			int size = atoi(answer.c_str());
			Stek stek(size);
			while (answer != "exit") {
				cout << "select \"1\" that put item\n";
				cout << "select \"2\" that get item\n";
				cout << "answer: ";
				getline(cin, answer);
				if (answer == "1") {
					cout << "enter a item: ";
					getline(cin, answer);
					int item = atoi(answer.c_str());
					stek.putItem(item);
					stek.printStek();
				} else if (answer == "2") {
					cout << "get item = " << stek.getItem() << endl;
					stek.printStek();
				} else if (answer == "3") {
					break;
				} else {
					cout << "Please enter 1 or 2.\n";
				}
			}
		} else {
			cout << "Please enter 1 or 2.\n";
		}
	}
}