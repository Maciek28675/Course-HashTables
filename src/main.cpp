#include <iostream>
#include "HashTable.hpp"
#include "SinglyLinkedList.hpp"

int main()
{
	std::cout << "Hello World!\n";

	SinglyLinkedList<int> l1;

	l1.pushBack(0);
	l1.pushBack(1);
	l1.pushBack(2);
	l1.pushBack(3);

	l1.show();

	return 0;
}