#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

struct List
{
	List *next;
	List *prev;
	inem;
};

void initItemsOfList(List *, int);
int countItemsOfList(List *);
void deleteItemOfList(List *, int);
void moveItemOfList(List *, int);

void initItemsOfList(List *list, int size)
{
	for (int i = 0; i < size; i++) {
		if (!i) {
			list[i].prev = NULL;
			list[i].item = -1;
			list[i].next = &list[i + 1];
			continue;
		}
		if ((i + 1) == size) {
			list[i].next = NULL;
			list[i].prev = &list[i - 1];
			list[i].item = -1;
			continue;
		}
		list[i].next = &list[i + 1];
		list[i].prev = &list[i - 1];
		list[i].item = -1;
	}
}

int countItemsOfList(List *list)
{
	int count = 0;
	if ((list->prev == NULL) && (list->next == NULL))
		return 0;
	for (; list->next; count++)
		list = list->next;
	return ++count;
}

void addInList(List *list, int itm, int num)
{
	
	for (; num > 0; num--) {
		list = list->next;
		if (!list->next) {
			return;
		}
	}
	list->item = itm;
}

void deleteItemOfList(List *list, int num)
{
	for (; num > 0; num--)
		list = list->next;
	if (!list->prev) {
		list->next->prev = NULL;
	} else if (!list->next) {
		list->prev->next = NULL;
	} else {
		List *tmp = list->next;
		list = list->prev;
		list->next = tmp;
		tmp->prev = list;
	}
}

void moveItemOfList(List *list, int start, int end)
{
	List *stList = list;
	List *enList = list;

	for (; start > 0; start--)
		stList = stList->next;
	for (; end > 0; end--)
		enList = enList->next;

	List *tmp;

	if (stList->next == enList || enList->prev == stList) {
		if (enList->next) {
			enList->next->prev = stList;
		}
		if (stList->prev) {
			stList->prev->next = enList;
		}

		stList->next = enList->next;
		enList->prev = stList->prev;

		enList->next = stList;
		stList->prev = enList;
	} else {
		if (stList->prev) {
			stList->prev->next = enList;
		}
		if (stList->next) {
			stList->next->prev = enList;
		}

		if (enList->prev) {
			enList->prev->next = stList;
		}
		if (enList->next) {
			enList->next->prev = stList;
		}

		tmp = stList->prev;
		stList->prev = enList->prev;
		enList->prev = tmp;

		tmp = stList->next;
		stList->next = enList->next;
		enList->next = tmp;
	}
	
}

int main(void)
{
	int size = 10;
	List *list = new List[size];
	initItemsOfList(list, size);

	int *a = new int[100];
	srand(time(0));

	int count = 0;

	for (int i = 0; i < 100; i++) {
		a[i] = rand() % 100;
		double d = sqrt(a[i]);
		int t = sqrt(a[i]);
		if ((d - t) == 0) {
			addInList(list, a[i], count);
			++count;
		}
	}
	int countList = countItemsOfList(list);
	for (int i = 0; i < countList; i++) {
		cout << list->item << " ";
		if (!list->next)
			break;
		list = list->next;
	}
	for (int i = 0; i < countList; i++) {
		if (!list->prev)
			break;
		list = list->prev;
	}
	cout << endl;
	cout << countItemsOfList(list) << endl;
	cout << endl;

	List *tmp = list;
	for (int i = 0; i < countItemsOfList(list); i++) {
		List *tmp_2 = list;
		for (int j = 0; j < countItemsOfList(list); j++) {
			if (tmp == tmp_2) {
				tmp_2 = tmp_2->next;
				continue;
			}
			if ((tmp->item == tmp_2->item) && (tmp->item != -1) && (tmp_2->item != -1)) {
				deleteItemOfList(list, j);
			}
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}

	for (int i = 0; i < countList; i++) {
		cout << list->item << " ";
		if (!list->next)
			break;
		list = list->next;
	}
	for (int i = 0; i < countList; i++) {
		if (!list->prev)
			break;
		list = list->prev;
	}
	cout << endl;
	cout << countItemsOfList(list) << endl;
}