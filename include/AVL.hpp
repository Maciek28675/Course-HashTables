#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>
#include <vector>

#include "HashTable.hpp"

using namespace std;

template <typename T1, typename T2>
struct AVLNode {
	T1 key;
	T2 value;
	AVLNode<T1, T2>* left;
	AVLNode<T1, T2>* right;
	int height;

	AVLNode(T1 key, T2 value) : key(key), value(value), left(nullptr), right(nullptr), height(1) {};
};


template <typename T1, typename T2>
class AVL : public HashTable<T1,T2>{
private:
	AVLNode<T1,T2>* root;

	int height(AVLNode<T1, T2>* node);
	int balanceFactor(AVLNode<T1, T2>* node);
	void updateHeight(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* rotateRight(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* rotateLeft(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* balance(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* insert(AVLNode<T1, T2>* node, T1 key, T2 value);
	AVLNode<T1, T2>* findMin(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* removeMin(AVLNode<T1, T2>* node);
	AVLNode<T1, T2>* remove(AVLNode<T1, T2>* node, T1 key);
	AVLNode<T1,T2>* search(AVLNode<T1, T2>* node, T1 key);

public:
	AVL(int size);
	~AVL();

	void insert(T1 key, T2 value) override;
	void remove(T1 key) override;
	T2 search(T1 key);
};

template<typename T1, typename T2>
int AVL<T1, T2>::height(AVLNode<T1, T2>* node) {
	return node ? node->height : 0;
}

template<typename T1, typename T2>
int AVL<T1, T2>::balanceFactor(AVLNode<T1, T2>* node) {
	return height(node->right) - height(node->left);
}

template<typename T1, typename T2>
void AVL<T1, T2>::updateHeight(AVLNode<T1, T2>* node) {
	int hl = height(node->left);
	int hr = height(node->right);
	node->height = (hl > hr ? hl : hr) + 1;
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::rotateRight(AVLNode<T1, T2>* node) {
	AVLNode<T1, T2>* left = node->left;
	node->left = left->right;
	left->right = node;
	updateHeight(node);
	updateHeight(left);
	return left;
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::rotateLeft(AVLNode<T1, T2>* node) {
	AVLNode<T1, T2>* right = node->right;
	node->right = right->left;
	right->left = node;
	updateHeight(node);
	updateHeight(right);
	return right;
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::balance(AVLNode<T1, T2>* node) {
	updateHeight(node);
	if (balanceFactor(node) == 2) {
		if (balanceFactor(node->right) < 0) {
			node->right = rotateRight(node->right);
		}
		return rotateLeft(node);
	}
	if (balanceFactor(node) == -2) {
		if (balanceFactor(node->left) > 0) {
			node->left = rotateLeft(node->left);
		}
		return rotateRight(node);
	}
	return node;
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::insert(AVLNode<T1, T2>* node, T1 key, T2 value) {
	if (!node) {
		return new AVLNode<T1, T2>(key, value);
	}
	if (key < node->key) {
		node->left = insert(node->left, key, value);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key, value);
	}
	else {
		return node;
	}
	return balance(node);
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::findMin(AVLNode<T1, T2>* node) {
	return node->left ? findMin(node->left) : node;
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::removeMin(AVLNode<T1, T2>* node) {
	if (!node->left) {
		return node->right;
	}
	node->left = removeMin(node->left);
	return balance(node);
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::remove(AVLNode<T1, T2>* node, T1 key) {
	if (!node) {
		return nullptr;
	}
	if (key < node->key) {
		node->left = remove(node->left, key);
	}
	else if (key > node->key) {
		node->right = remove(node->right, key);
	}
	else {
		AVLNode<T1, T2>* left = node->left;
		AVLNode<T1, T2>* right = node->right;
		delete node;
		if (!right) {
			return left;
		}
		AVLNode<T1, T2>* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;
		return balance(min);
	}
	return balance(node);
}

template<typename T1, typename T2>
AVLNode<T1, T2>* AVL<T1, T2>::search(AVLNode<T1, T2>* node, T1 key) {
	if (!node) {
		return nullptr;
	}
	if (key < node->key) {
		return search(node->left, key);
	}
	else if (key > node->key) {
		return search(node->right, key);
	}
	else {
		return node;
	}
}

template<typename T1, typename T2>
AVL<T1, T2>::AVL(int size) {
	for (int i = 0; i < size; i++) {
		insert(i, T2());
	}
}

template<typename T1, typename T2>
AVL<T1, T2>::~AVL() {
	vector<AVLNode<T1, T2>*> stack;
	stack.push_back(root);
	while (!stack.empty()) {
		AVLNode<T1, T2>* node = stack.back();
		stack.pop_back();
		if (node->left) {
			stack.push_back(node->left);
		}
		if (node->right) {
			stack.push_back(node->right);
		}
		delete node;
	}
}

template<typename T1, typename T2>
void AVL<T1, T2>::insert(T1 key, T2 value) {
	root = insert(root, key, value);
}

template<typename T1, typename T2>
void AVL<T1, T2>::remove(T1 key) {
	root = remove(root, key);
}

template<typename T1, typename T2>
T2 AVL<T1, T2>::search(T1 key) {
	AVLNode<T1, T2>* node = search(root, key);
	if (node) {
		return node->value;
	}
	throw std::out_of_range("Key not found");
}

#endif //!AVL_HPP
