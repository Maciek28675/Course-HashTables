#ifndef CUCKOO_HASHING_TABLE_HPP
#define CUCKOO_HASHING_TABLE_HPP

#define CYCLE_LIMIT 3

#include "HashTable.hpp"

#include <vector>
#include <functional>
#include <cmath>

template <typename T1, typename T2>
class CuckooHashingTable
{
private:
	std::vector<T1, T2> array1_;
	std::vector<T1, T2> array2_;

	size_t hash(int key, int type = 0) override;
	size_t hash(float key, int type = 0) override;
	size_t hash(char key, int type = 0) override;
	size_t hash(std::string key, int type = 0) override;

	void rehash();
	void resize(size_t newSize);

public:
	CuckooHashingTable();
	~CuckooHashingTable();

	void insert(T1 key, T2 value) override;
	void remove(T1 key) override;
};

template <typename T1, typename T2>
CuckooHashingTable<T1, T2>::CuckooHashingTable()
{
	// In progress
}

template <typename T1, typename T2>
CuckooHashingTable<T1, T2>::~CuckooHashingTable()
{
	// In progress
}

template <typename T1, typename T2>
void CuckooHashingTable<T1, T2>::insert(T1 key, T2 value)
{
	// In progress
}

template <typename T1, typename T2>
void CuckooHashingTable<T1, T2>::remove(T1 key)
{
	// In progress
}

#endif