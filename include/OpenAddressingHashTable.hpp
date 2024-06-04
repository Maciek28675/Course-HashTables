#ifndef OPENHASH_TABLE_HPP
#define OPENHASH_TABLE_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

#include "hashtable.hpp"

template <typename T1, typename T2>
class OpenAddressingTable : public HashTable<T1,T2> {

private:
	struct HashEntry {
		T1 key;
		T2 value;
		bool isDeleted;
		bool isOccupied;
		HashEntry() : isDeleted(false), isOccupied(false) {}
	};
	
	std::vector<HashEntry> table;
	int size;
	int capacity;
	
	int hash(const T1& key);


public:
	OpenAddressingTable(int tableSize);
	~OpenAddressingTable();
	void insert(T1 key, T2 value) override;
	void remove(T1 key) override;
	T2 search(T1 key);
};

template <typename T1, typename T2>
int OpenAddressingTable<T1,T2>::hash(const T1& key) {
	std::hash<T1> hashFunction;
	return hashFunction(key) % capacity;
}


template <typename T1, typename T2>
OpenAddressingTable<T1,T2>::OpenAddressingTable(int tableSize): size(0), capacity(tableSize) {
	table.resize(tableSize);
}

template <typename T1, typename T2>
OpenAddressingTable<T1,T2>::~OpenAddressingTable() {
	table.clear();
}

template <typename T1, typename T2>
void OpenAddressingTable<T1,T2>::insert(T1 key, T2 value) {
	if (size == capacity) {
		throw std::out_of_range("Table is full");
	}
	
	int index = hash(key);
	int start_index = index;

	while (table[index].isOccupied && !table[index].isDeleted) {
		if (table[index].key == key )
			{
			throw std::invalid_argument("Key already exists");
		}
		index = (index + 1) % capacity;
		if (index == start_index) {
			throw std::out_of_range("Table is full");
		}
	}
	table[index].key = key;
	table[index].value = value;
	table[index].isOccupied = true;
	table[index].isDeleted = false;
	size++;

	std::cout << "inserted key" << key << " at index " << index << "\n";
}

template <typename T1, typename T2>
void OpenAddressingTable<T1,T2>::remove(T1 key) {
	int index = hash(key);
	int start_index = index;

	while (table[index].isOccupied) {
		if (table[index].key == key && !table[index].isDeleted) {
			table[index].isDeleted = true;
			std::cout << "Removed key: " << key << " from index: " << index << "\n";
			size--;
			return;
		}
		index = (index + 1) % capacity;
		if (index == start_index) {
			break;
		}
	}
	throw std::out_of_range("Key not found");
}

template <typename T1, typename T2>
T2 OpenAddressingTable<T1,T2>::search(T1 key) {
	int index = hash(key);
	int start_index = index;

	while (table[index].isOccupied) {
		if (table[index].key == key && !table[index].isDeleted) {
			std::cout << "Found key: " << key << " at index: " << index << "\n";
			return table[index].value;
		}
		index = (index + 1) % capacity;
		if (index == start_index) {
			throw std::out_of_range("Key not found");
			break;
		}
	}
	throw std::out_of_range("Key not found");
}

#endif //OPENHASH_TABLE_HPP
