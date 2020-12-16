#include <iostream>
#include "DList.h"
using namespace std;
int main() {
	DList<int> dl;
	dl.pushFront(10);
	dl.pushFront(228);
	dl.pushBack(1337);
	dl.print();
	dl.printR();
	cout << "EraseBack: " << endl;
	dl.eraseBack();
	dl.print();
	dl.eraseFront();
	dl.print();
	cout << "Erase element" << endl;
	dl.pushFront(12);
	dl.pushFront(228);
	dl.pushBack(1337);
	dl.print();
	dl.eraseElem(10);
	dl.print();
	return 0;
}