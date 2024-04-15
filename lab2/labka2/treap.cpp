
#include "treap.h"


TreapNode* rightRotate(TreapNode* y)
{
	TreapNode* x = y->left, * T2 = x->right;

	x->right = y;
	y->left = T2;

	return x;
}

TreapNode* leftRotate(TreapNode* x)
{
	TreapNode* y = x->right, * T2 = y->left;

	y->left = x;
	x->right = T2;

	return y;
}


TreapNode* newNode(int key)
{
	TreapNode* temp = new TreapNode;
	temp->key = key;
	temp->priority = rand() % 100;
	temp->left = temp->right = nullptr;
	return temp;
}

TreapNode* search(TreapNode* root, int key)
{

	if (root == nullptr || root->key == key)
		return root;

	if (root->key < key)
		return search(root->right, key);

	return search(root->left, key);
}


TreapNode* insert(TreapNode* root, int key)
{
	if (!root)
		return newNode(key);

	if (key <= root->key)
	{
		root->left = insert(root->left, key);

		if (root->left->priority > root->priority)
			root = rightRotate(root);
	}
	else
	{
		root->right = insert(root->right, key);

		if (root->right->priority > root->priority)
			root = leftRotate(root);
	}
	return root;
}

TreapNode* deleteNode(TreapNode* root, int key)
{
	if (search(root, key) == nullptr)
	{
		printf("\nKey %d not found\n", key);
		return nullptr;
	}

	if (root == nullptr)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else if (root->left == nullptr)
	{
		TreapNode* temp = root->right;
		delete(root);
		root = temp;
	}

	else if (root->right == nullptr)
	{
		TreapNode* temp = root->left;
		delete(root);
		root = temp;
	}

	else if (root->left->priority < root->right->priority)
	{
		root = leftRotate(root);
		root->left = deleteNode(root->left, key);
	}
	else
	{
		root = rightRotate(root);
		root->right = deleteNode(root->right, key);
	}

	return root;
}

#include <cstdio>

void inorder(TreapNode* root) {
	if (root) {
		inorder(root->left);
		printf("key: %d | priority: %d", root->key, root->priority);
		if (root->left)
			printf(" | left child: %d", root->left->key);
		if (root->right)
			printf(" | right child: %d", root->right->key);
		printf("\n");
		inorder(root->right);
	}
}

void printTreap(TreapNode* root, int space = 0, int count = 10) {
	if (root == nullptr)
		return;

	space += count;

	printTreap(root->right, space);

	printf("\n");
	for (int i = count; i < space; ++i)
		printf(" ");

	printf("(%d, %d)\n", root->key, root->priority);

	printTreap(root->left, space);
}