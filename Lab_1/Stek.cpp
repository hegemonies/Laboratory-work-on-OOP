#include <iostream>
using namespace std;

class Stek
{
	int *arr;
	int size;
	int capacity;
public:
	Stek() {
		cout << "\tЗадайте длину стека.\n";
	}
	
	Stek(int s) {
		if (s > 10) {
			size = 10;
		} else if (s <= 0) {
			size = 1;
		}
		size = s;
		try {
			arr = new int[size];
		} catch (bad_alloc xa) {
			cout << "\tОшибка выделения памяти.\n";
		}
		capacity = -1;
	}

	~Stek() {
		delete []arr;
	}

	void putItem(int item) {
		if (capacity == size - 1) {
			cout << "\tСтек полон.\n";
			return;
		}
		capacity++;
		arr[capacity] = item;
	}

	int getItem() {
		if (capacity < 0) {
			cout << "\tСтек пуст.\n";
			return -1;
		}
		return arr[capacity--];
	}
};


int main(void)
{
	int size = 10;
	Stek stek(size);

	for (int i = 0; i < 12; i++) {
		stek.putItem(i);
	}
	for (int i = 0; i < size; i++) {
		cout << i << " = " << stek.getItem() << endl;
	}
}