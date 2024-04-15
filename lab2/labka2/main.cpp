#include "treap.h"
#include "unit_tests.h"
int main()
{
	srand(time(nullptr));

	Test_insert();
	Test_delete();

	struct TreapNode* root = nullptr;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);


	printf("\nFull treap:\n");
	printTreap(root, 0, 7);
	printf("\n\n");
	inorder(root);

	
	printf("\nDelete 20:\n");
	root = deleteNode(root, 20);
	printTreap(root, 0, 6);

	printf("\nDelete 40:\n");
	root = deleteNode(root, 40);
	printTreap(root, 0, 5);

	printf("\nDelete 60:\n");
	root = deleteNode(root, 60);
	printTreap(root, 0, 4);

	printf("\nDelete 10:\n");
	root = deleteNode(root, 10);
	

	return 0;
}