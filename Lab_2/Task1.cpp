#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	
	int size = 4;
	short int **a = new short*[size];
	int count;
	for (int i = 0; i < size; i++) {
		a[i] = new short[size];
		for (int j = 0; j < size; j++) {
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	//Right diagonal
	short int *b = new short[size * size];
	count = 0;
	
	for (int i = 0; i < size; i++) {
		int k = 0 - i;
		for (int j = size - i - 1; j < size; j++) {
			b[count++] = a[i + k][j];
			k++;
		}
	}
	for (int i = 1; i < size; i++) {
		int k = 0;
		for (int j = 0; j < size - i; j++) {
			b[count++] = a[i + k][j];
			k++;
		}
	}
	
	cout << "\na = ";
	for (int i = 0; i < count; i++) {
		cout << b[i] << " ";
	}
	
	//Left diagonal
	short int *c = new short[size * size];
	count = 0;

	for (int i = 0; i < size; i++) {
		int k = 0;
		for (int j = i; j >= 0; j--) {
			c[count++] = a[k++][j];
		}
	}

	for (int i = 0; i < size - 1; i++) {
		int k = 1;
		for (int j = size - 1; j > i; j--) {
			c[count++] = a[k + i][j];
			k++;
		}
	}

	cout << "\nb = ";
	for (int i = 0; i < count; i++) {
		cout << c[i] << " ";
	}
	
	//Spiral in the center
	
	short int *d = new short[size * size];
	count = 0;
	int x, y;
	if ((size % 2) == 0) {
		x = (size / 2) - 1;
		y = (size / 2) - 1;
	} else {
		y = x = size / 2;
	}
	
	int k = 1;
	int s = 1;
	
	while (1) {
		for (int i = 0; i < k; i++) {//right
			d[count++] = a[y][x];
			//cout << a[y][x] << " :: " << y << " " << x << endl;
			x++;
			s++;
		}
		//cout << "s = " << s << endl;
		if (s >= (size * size)) {
			//d[count++] = a[y][x];
			break;
		}
		for (int i = 0; i < k; i++) {//down
			d[count++] = a[y][x];
			//cout << a[y][x] << " :: " << y << " " << x << endl;
			y++;
			s++;
		}
		//cout << "s = " << s << endl;
		for (int i = 0; i < k + 1; i++) {//left
			d[count++] = a[y][x];
			//cout << a[y][x] << " :: " << y << " " << x << endl;
			x--;
			s++;
		}
		//cout << "s = " << s << endl;
		if (s >= (size * size)) {
			//d[count++] = a[y][x];
			break;
		}
		for (int i = 0; i < k + 1; i++) {//up
			d[count++] = a[y][x];
			//cout << a[y][x] << " :: " << y << " " << x << endl;
			y--;
			s++;
		}
		//cout << "s = " << s << endl;
		k = k + 2;
	}
	cout << "\nc = ";
	for (int i = 0; i < count; i++) {
		cout << d[i] << " ";
	}
	
	//Spiral in the top left
	
	short int *e = new short[size * size];
	count = 0;
	k = 0;
	
	for (int s = 0; s < size * size; ) {
		k++;
		for (int i = k - 1; i < size - k + 1; i++) {//right
			e[count++] = a[k - 1][i];
			s++;
		}
		for (int i = k; i < size - k + 1; i++) {//down
			e[count++] = a[i][size - k];
			s++;
		}
		for (int i = size - k - 1; i >= k - 1; i--) {//left
			e[count++] = a[size - k][i];
			s++;
		}
		for (int i = size - k - 1; i >= k; i--) {//up
			e[count++] = a[i][k - 1];
			s++;
		}
	}
	
	cout << "\nd = ";
	for (int i = 0; i < count; i++) {
		cout << e[i] << " ";
	}
	
	//#2
	int newSize = 10;
	short int **f = new short*[newSize];
	
	cout << "\n\n";
	
	for (int i = 0; i < newSize; i++) {
		int tmpSize = rand() % 10;
		cout << "size = " << tmpSize << endl;;
		f[i] = new short[tmpSize];
		for (int j = 0; j < tmpSize; j++) {
			f[i][j] = rand() % 10;
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	
		
	return 0;
}
