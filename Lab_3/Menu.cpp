#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>

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
	void saveTextInFile(string);
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

void Menu::searchStr(string str)
{
	int count = 0;
	for (int i = 0; i < (int)text.length(); i++) {
		if (str == text.substr(i, str.length())) {
			count++;
			cout << count << "ое(ье) нахождение искомого слова: ";
			cout << text.substr(i - 15, str.length() + 15) << endl;
		}
	}
	cout << "найдено " << count << " искомых или похожих на них слов\n";
}

void Menu::removeStr(string str)
{
	int lengthStr = (int)str.length();
	for (int i = 0; i < (int)text.length(); i++) {
		if (str == text.substr(i, lengthStr) && !isalpha(text[i + lengthStr])) {
			text.erase(i, i + lengthStr + 1);
		}
	}
}

void Menu::clearTerm()
{
	text.clear();
}

void Menu::saveTextInFile()
{
	ofstream out("standart_output_text_file.txt");
	try {
		if (!out) throw 1;
	} catch (...) {
		cout << "Cannot open file\n";
		return;
	}

	out << text;

	out.close();
}

void Menu::saveTextInFile(string name_file)
{
	ofstream out(name_file.c_str());
	try {
		if (!out) throw 1;
	} catch (...) {
		cout << "Cannot open file\n";
		return;
	}

	out << text;

	out.close();
}

void help()
{
	cout << "List of the commands:\n";
	cout << "open : Gets text for the terminal from the file\n";
	cout << "input : The user enters a string that is added to the current text\n";
	cout << "show : Displays all text that the terminal stores\n";
	cout << "search : Search for a word in the entire text\n";
	cout << "remove : Delete all occurrences of a word from a text\n";
	cout << "clear : Clears the text stored by the terminal\n";
	cout << "save : Saves changes to an earlier opened file or creates a new file with the specified name\n";
	cout << "exit : Exit from program\n";
}

int main(void)
{
	Menu menu;
	string str;
	help();
	while ((str != "exit")) {
		str.clear();
		cout << "command: ";
		cin >> str;
		if (str == "open") {
			cout << "ВОШЕЛ В ОПЕН ФАЙЛЗ КАК ТЕЙЛЗ ИЗ СОНИКА\n";
			cout << "Please enter the name file: ";
			str.clear();
			cin >> str;
			menu.openFile(str);
			continue;
		}
		if (str == "input") {
			cout << "Please enter a string: ";
			string str1;
			//cin.clear();
			//char str1[50];
			//scanf("%s", str1);
			getline(cin, str1);
			menu.addStr(str1);
			cout << str1;
			continue;
		}
		if (str == "show") {
			menu.showText();
			continue;
		}
		if (str == "search") {
			cout << "Please enter a string: ";
			str.clear();
			getline(cin, str);
			menu.searchStr(str);
			continue;
		}
		if (str == "remove") {
			cout << "Please enter a string: ";
			str.clear();
			getline(cin, str);
			menu.removeStr(str);
			continue;
		}
		if (str == "clear") {
			menu.clearTerm();
			continue;
		}
		if (str == "save") {
			cout << "Please enter the name file: ";
			str.clear();
			getline(cin, str);
			menu.saveTextInFile(str);
			continue;
		}
		if (str == "\n") {
			continue;
		}
	}
}