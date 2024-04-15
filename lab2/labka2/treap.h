#pragma once
#include <iostream>
#include <stdlib.h> 
#include <malloc.h>
#include <stdio.h>
using namespace std;

struct TreapNode
{
	int key;
	int priority;
	TreapNode* left;
	TreapNode* right;
};



TreapNode* rightRotate(TreapNode* y);

TreapNode* leftRotate(TreapNode* x);

TreapNode* newNode(int key);

TreapNode* search(TreapNode* root, int key);

TreapNode* insert(TreapNode* root, int key);

TreapNode* deleteNode(TreapNode* root, int key);

void inorder(TreapNode* root);

void printTreap(TreapNode* root, int space, int count);
