#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

template <typename T1, typename T2>
class CuckooHashingTable;

template <typename T1, typename T2>
class ClosedAddressingTable;

template <typename T1, typename T2>
class HashTable
{
public:
	virtual void insert(T1 key, T2 value) = 0;
	virtual void remove(T1 key) = 0;
	virtual size_t hash(int key, int type = 0) = 0;
	virtual size_t hash(float key, int type = 0) = 0;
	virtual size_t hash(char key, int type = 0) = 0;
	virtual size_t hash(std::string key, int type = 0) = 0;
};

#endif