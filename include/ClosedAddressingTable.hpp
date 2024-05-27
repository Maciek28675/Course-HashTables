#ifndef CLOSED_ADDRESSING_TABLE_HPP
#define CLOSED_ADDRESSING_TABLE_HPP

#include "HashTable.hpp"
#include "SinglyLinkedList.hpp"

template <typename T>
class ClosedAddressingTable : public HashTable
{
private:
public:
	ClosedAddressingTable();
	~ClosedAddressingTable();

	void insert(T key, T value) override;
	void remove(T key) override;
};

template <typename T>
ClosedAddressingTable<T>::ClosedAddressingTable()
{
	// In progress
}

template <typename T>
ClosedAddressingTable<T>::~ClosedAddressingTable()
{
	// In progress
}

template <typename T>
void ClosedAddressingTable<T>::insert(T key, T value)
{
	// In progress
}

template <typename T>
void ClosedAddressingTable<T>::remove(T key)
{
	// In progress
}

#endif