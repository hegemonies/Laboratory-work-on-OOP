#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>
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

    static void getCount()
    {
    	static int count = 0;
    	cout << "It's static method: " << count << endl;
    	count++;
	}

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
		//width++;
		init();

		in.seekg(0, ios::beg);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				in >> array[i][j];
			}
		}

		in.close();
		Sheet<int>::getCount();
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
	srand(time(0));
	
	Sheet<int> obj[6];

	for (int i = 0; i < 6; i++) {
		ostringstream ss;
    	ss << i;
    	string s = ss.str();
	    cout << s;
	    string tmp_f = s + ".txt";
	    
		ofstream tmp(tmp_f.c_str());
		int rnd = rand() %  10;
		for (int j = 0; j < rnd; j++) {
			for (int h = 0; h < rnd; h++) {
				tmp << h + j + 1 << " ";
			}
			if (j < rnd - 1)
			    tmp << endl;
		}
		tmp.close();
		
		obj[i].getSheetFromFile(tmp_f);
		obj[i].printSheet();
		cout << endl;
	}
	return 0;
}
