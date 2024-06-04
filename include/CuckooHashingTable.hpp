#ifndef CUCKOO_HASHING_TABLE_HPP
#define CUCKOO_HASHING_TABLE_HPP

#define CYCLE_LIMIT 3
#define ALPHA 0.618

#include "HashTable.hpp"
#include "Node.hpp"

#include <vector>
#include <functional>
#include <cmath>

template <typename T1, typename T2>
class CuckooHashingTable : public HashTable<T1, T2>
{
private:
	std::vector<Node<T1, T2>> array1_;
	std::vector<Node<T1, T2>> array2_;

	size_t size_;
	size_t elements_;
	float loadFactor_;

	size_t hash(int key, int type = 0) override;
	size_t hash(float key, int type = 0) override;
	size_t hash(char key, int type = 0) override;
	size_t hash(std::string key, int type = 0) override;

	void rehash();
	void resize(size_t newSize);

public:
	CuckooHashingTable(size_t size);
	~CuckooHashingTable();

	void insert(T1 key, T2 value) override;
	void remove(T1 key) override;

	size_t calculateLoadFactor();
};

template <typename T1, typename T2>
CuckooHashingTable<T1, T2>::CuckooHashingTable(size_t size): size_(size), array1_(size), array2_(size), elements_(0), loadFactor_(0.0)
{
	
}

template <typename T1, typename T2>
CuckooHashingTable<T1, T2>::~CuckooHashingTable()
{
	// In progress
}

template <typename T1, typename T2>
size_t CuckooHashingTable<T1, T2>::hash(int key, int type = 0)
{
	size_t hashValue = 0;

	switch (type)
	{
		case 0:
		{
			hashValue = key % size_;
			break;
		}

		case 1:
		{
			double nominator = static_cast<size_t>(ALPHA * key) % static_cast<size_t>(pow(2, 16));
			hashValue = std::floor(nominator / (pow(2, 16) / size_));
			break;
		}
	}

	return hashValue;
}

template <typename T1, typename T2>
size_t CuckooHashingTable<T1, T2>::hash(float key, int type = 0)
{
	std::hash<float> hashFunction;
	size_t hashValue = 0;

	switch (type)
	{
		case 0:
		{
			hashValue = hashFunction(key);
			break;
		}

		case 1:
		{
			double nominator = static_cast<size_t>(ALPHA * key) % static_cast<size_t>(pow(2, 16));
			hashValue = std::floor(nominator / (pow(2, 16) / size_));
			break;
		}
	}

	return hashValue;
}

template <typename T1, typename T2>
size_t CuckooHashingTable<T1, T2>::hash(char key, int type = 0)
{
	char asciiValue = int(key);
	size_t hashValue = 0;

	switch (type)
	{
		case 0:
		{
			hashValue = (asciiValue) % size_;
			break;
		}

		case 1:
		{
			double nominator = static_cast<size_t>(ALPHA * asciiValue) % static_cast<size_t>(pow(2, 16));
			hashValue = std::floor(nominator / (pow(2, 16) / size_));
			break;
		}
	}

	return hashValue;
}

template <typename T1, typename T2>
size_t CuckooHashingTable<T1, T2>::hash(std::string key, int type = 0)
{
	int sum = 0;

	for (int i = 0; i < key.size(); i++)
		sum += int(key[i]) * pow(31, i);

	size_t hashValue = 0;

	switch (type)
	{
		case 0:
		{
			hashValue = sum % size_;
			break;
		}

		case 1:
		{
			double nominator = static_cast<size_t>(ALPHA * sum) % static_cast<size_t>(pow(2, 16));
			hashValue = std::floor(nominator / (pow(2, 16) / size_));
			break;
		}
	}

	return hashValue;
}

template <typename T1, typename T2>
void CuckooHashingTable<T1, T2>::insert(T1 key, T2 value)
{
	int arrayIndex1 = hash(key, 0);
	int arrayIndex2 = hash(key, 1);

	int cycleCounter = 0;

	if (array1_[arrayIndex1] == {key, value, false} && array2_[arrayIndex2] == {key, value, false})
		return;

	while (cycleCounter < CYCLE_LIMIT)
	{
		if (array1_[arrayIndex1].isEmpty)
		{

		}
	}
}

template <typename T1, typename T2>
void CuckooHashingTable<T1, T2>::remove(T1 key)
{
	// In progress
}

template <typename T1, typename T2>
size_t CuckooHashingTable<T1, T2>::calculateLoadFactor()
{
	loadFactor_ = elements_ / size_;
}

#endif