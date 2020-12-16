#include <iostream>
#include <list>
#include "Source.h"
using namespace std;
void printList(std::list<int>& li)
{
	for (auto& element : li) {
		cout << element << " ";
	}
	cout << endl;
}
bool isDiv5(const int& value) {
	return value % 5 == 0;
}
int main() {
	list<int> li{ 10,23,5,55 };
	printList(li);

	auto it = find_if(li.begin(), li.end(), isDiv5);
	if (it!=li.end())
	{
		li.insert(it, { 0,8,88 });
	}
	printList(li);
	return 0;
}

