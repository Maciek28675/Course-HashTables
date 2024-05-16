#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

template <typename T>
class CuckooHashingTable;

template <typename T>
class ClosedAddressingTable;

template <typename T>
class HashTable
{
private:
public:
	virtual void insert(T key, T value) = 0;
	virtual void remove(T key) = 0;
};

#endif