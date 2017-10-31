#include "vector.h"

int main()
{
	Vector<int> obj(4);
	//obj.initItemsOfList(5);
	obj.print();
	cout << endl;
	obj.addInList(22, 0);
	obj.print();
	obj.deleteItemOfList(1);
	obj.print();
	cout << "HEY : " << obj[0]->item;
	return 0;
}
