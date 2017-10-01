#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Menu {
	string text;
public:
	void openFile(string);
	void addStr(string);
	void showText();
	void searchStr(string);
	void removeStr(string);
	void clearTerm();
	void saveTextInFile(); 
};

void Menu::openFile(string path)
{
	ifstream in(path.c_str(), ios::in | ios::binary);
	try {
		if (!in) throw 1;
	} catch (...) {
		cout << "Cannot open file\n";
		return;
	}
	
	char ch;
	while (in.get(ch)) {
		text += ch;
	}
	in.close();
}

void Menu::addStr(string str)
{
	text += str;
}

void Menu::showText()
{
	cout << text << endl;
}

void searchStr(string str)
{
	char *tmp = text.c_str();
	while ()
}

int main(void)
{
	Menu m;
	m.openFile("test.txt");
	m.showText();

	m.addStr("MANCHESTER");
	m.showText();
}