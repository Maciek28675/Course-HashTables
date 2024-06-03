#include <iostream>
#include <functional>
#include "Utilities.hpp"
#include "HashTable.hpp"
#include "ClosedAddressingTable.hpp"
#include "SinglyLinkedList.hpp"

int main()
{
	measurePerformance(1000, 1000000);
	return 0;
}