#ifndef CUCKOO_HASHING_TABLE_HPP
#define CUCKOO_HASHING_TABLE_HPP

#include "HashTable.hpp"

template <typename T>
class CuckooHashingTable : public HashTable
{
private:
public:
	CuckooHashingTable();
	~CuckooHashingTable();

	void insert(T key, T value) override;
	void remove(T key) override;
};

template <typename T>
CuckooHashingTable<T>::CuckooHashingTable()
{
	// In progress
}

template <typename T>
CuckooHashingTable<T>::~CuckooHashingTable()
{
	// In progress
}

template <typename T>
void CuckooHashingTable<T>::insert(T key, T value)
{
	// In progress
}

template <typename T>
void CuckooHashingTable<T>::remove(T key)
{
	// In progress
}

#endif