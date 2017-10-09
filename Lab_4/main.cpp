#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
using namespace std;

template <class SType> class Sheet
{
	int height;
	int width;
	SType **array;

	void init() {
		try {
			array = new SType*[height];
		} catch (bad_alloc xa) {
			cout << "\tCould not allocate memory\n";
		}
		for (int i = 0; i < height; i++) {
			try {
				array[i] = new SType[width];
			} catch (bad_alloc xa) {
				cout << "\tCould not allocate memory\n";
			}
		}
	}

public:
	Sheet() {
		height = width = 0;
	};
	Sheet(int h, int w) {
		height = h;
		width = w;
		try {
			array = new SType*[height];
		} catch (bad_alloc xa) {
			cout << "\tCould not allocate memory\n";
		}
		for (int i = 0; i < height; i++) {
			try {
				array[i] = new SType[width];
			} catch (bad_alloc xa) {
				cout << "\tCould not allocate memory\n";
			}
		}
	};


	void getSheetFromFile(string name_file) {
		ifstream in(name_file.c_str());

		const char *str;
		string buf;

		while (!in.eof()) {
			getline(in, buf);
			str = buf.c_str();
			int count = 0;
			for (int i = 0; str[i] != 0; i++) {
				if (str[i] == ' ') {
					count++;
				}
				if (count > width) {
					width = count;
				}
			}
			height++;
		}
		width++;
		init();

		in.seekg(0, ios::beg);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				in >> array[i][j];
			}
		}

		in.close();
	}

	void addItem(SType item, int x, int y) {
		if ((x >= 0) && (x < height) && (y >= 0) && (y < width)) {
			array[x][y] = item;
		}
	}

	void printSheet() {
		for (int i = 0; i < 1; i++) {
			cout << "       " << setw(5);
		}
		for (int i = 0; i < width; i++) {
			cout << setw(5) << i + 1;
		}
		cout << endl;
		for (int i = 0; i < width + 1; i++) {
			cout << "------";
		}
		cout << endl;

		for (int i = 0; i < height; i++) {
			cout << setw(3) << i + 1 << "   |";
			for (int j = 0; j < width; j++) {
				cout << setw(5) << array[i][j];
			}
			cout << endl;
		}
	}
	~Sheet() {
		for (int i = 0; i < height; i++) {
			delete []array[i];
		}
		delete []array;
	}
};

int main()
{
	Sheet<int> obj;

	obj.getSheetFromFile("tset_sheet.txt");
	obj.printSheet();

	system("pause");

	return 0;
}
