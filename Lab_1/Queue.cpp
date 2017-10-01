#include <iostream>
using namespace std;

const int maxSize = 10;

class Queue
{
	short int *arr;
	int size;
	int putLock;
	int getLock;
public:
	Queue() {
		cout << "Задайте длину очереди\n";
	}

	Queue(int len) {
		if (len >= maxSize) {
			size = maxSize;
		} else if (len <= 0) {
			size = 0;
		}
		try {
			arr = new short[size];
		} catch (bad_alloc xa) {
			cout << "\tОшибка выделения.\n";
		}
		size = len;
		putLock = getLock = 0;
	}

	~Queue() {
		delete []arr;
	}

	void putItem(short int item) {
		if (putLock >= size) {
			arr[putLock % size] = item;
			getLock++;
			putLock++;
		} else {
			arr[putLock++] = item;
		}

	}

	short getItem() {
		if (getLock == putLock) {
			cout << "\tОчередь пуста.\n";
			return -1;
		}
		if (getLock >= size) {
			getLock = 0;
		}

		return arr[getLock++];
	}
};

int main(void)
{
	int size = 10;
	Queue arr(size);

	for (int i = 0; i < 10; i++) {
		arr.putItem(i);
	}
	for (int i = 0; i < size; i++) {
		cout << i << " = " << arr.getItem() << endl;
	}
}