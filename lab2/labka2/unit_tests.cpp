
#include "treap.h"
#include "unit_tests.h"

void Test_insert() {
    int key_root = 10, key_left = 5, key_right = 15;
    struct TreapNode* root = nullptr;

    root = insert(root, key_root);
    assert(search(root, key_root) != nullptr && search(root, key_root)->key == key_root);

    
    root = insert(root, key_left);
    assert(search(root, key_left) != nullptr && search(root, key_left)->key == key_left);
    assert(search(root, key_left)->priority <= root->priority); 

    root = insert(root, key_right);
    assert(search(root, key_right) != nullptr && search(root, key_right)->key == key_right);
    assert(search(root, key_right)->priority <= root->priority); 

    printf("All insert tests passed!\n");
}

void Test_delete() {
    int key_root = 10, key_left = 5, key_right = 15;
    struct TreapNode* root = nullptr;

    root = insert(root, key_root);
    root = insert(root, key_left);
    root = insert(root, key_right);

    root = deleteNode(root, key_left);
    assert(search(root, key_left) == nullptr); 
    assert(search(root, key_root) != nullptr); 
    assert(search(root, key_right) != nullptr);

    root = deleteNode(root, key_right);
    assert(search(root, key_right) == nullptr); 
    assert(search(root, key_root) != nullptr); 

    root = deleteNode(root, key_root);
    assert(search(root, key_root) == nullptr); 

   
    if (root != nullptr) {
        if (root->left != nullptr) {
            assert(root->priority >= root->left->priority);
        }
        if (root->right != nullptr) {
            assert(root->priority >= root->right->priority);
        }
    }

    printf("All delete tests passed!\n");
}