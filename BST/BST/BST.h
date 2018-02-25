#pragma once



//a bst_node is a root when its links[parent]==NULL
//a bst_node is a leaf when its links[left_child]==NULL and links[right_child]==NULL
typedef struct bst_node {
	int key;
	int index;
	struct bst_node* links[3];
} bst_node;

typedef struct {
	bst_node* root;
}BST;

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

	BST* EMPTY_BST();

	void del_BST(BST* bst);

	void BST_insert(BST* bst, int key);

	bst_node* BST_find(BST* bst,int key);

	bst_node* BST_successor(BST* bst,int key);

	void display(BST* bst);

#ifdef _cplusplus
}
#endif // _cplusplus