#include <iostream>
#include <functional>
#include <cmath>
#include "Utilities.hpp"
#include "HashTable.hpp"
#include "ClosedAddressingTable.hpp"
#include "CuckooHashingTable.hpp"
#include "SinglyLinkedList.hpp"
#include "AVL.hpp"
#include "OpenAddressingHashTable.hpp"

int main()
{
	
	measurePerformance(1000, 10000);
	measurePerformance(1000, 20000);
	measurePerformance(1000, 30000);
	measurePerformance(1000, 40000);
	measurePerformance(1000, 50000);
	measurePerformance(1000, 60000);
	measurePerformance(1000, 70000);
	measurePerformance(1000, 80000);
	measurePerformance(1000, 90000);
	measurePerformance(1000, 100000);
	measurePerformance(1000, 110000);
	measurePerformance(1000, 120000);
	measurePerformance(1000, 130000);
	measurePerformance(1000, 140000);
	measurePerformance(1000, 150000);
	measurePerformance(1000, 200000);
	measurePerformance(1000, 250000);
	measurePerformance(1000, 300000);
	measurePerformance(1000, 400000);
	measurePerformance(1000, 500000);

	return 0;
}