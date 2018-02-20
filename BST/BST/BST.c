#include "BST_stdafx.h"
#include "BST.h"

#define NEW_BST() ((BST*)malloc(sizeof(BST)))
#define NEW_NODE() ((bst_node*)malloc(sizeof(bst_node)))
#define empty(bst) (!bst->root)
#define VOID(ptr) ((void*)ptr)
#define isLeaf(node) (node->links[left_child]==NULL && node->links[right_child]==NULL)

//some numbers refer to the parent or children of a 
//bst node
enum {
	parent = 0,
	left_child,
	right_child
};


static void del_node(bst_node*);

BST* EMPTY_BST() {
	BST* temp=NEW_BST();
	temp->root = NULL;
	return temp;
}

void del_BST(BST* bst) {
	if (!empty(bst)) del_node(bst->root);
	free(VOID(bst));
}

void BST_insert(BST* bst,int key) {
	//create a new node with key
	bst_node* node = NEW_NODE();
	node->key = key;
	node->links[parent] = NULL;
	node->links[left_child] = NULL;
	node->links[right_child] = NULL;

	//if the bst is empty, deal with the root
	if (empty(bst)) {
		bst->root = node;
		return;
	};

	bst_node* cur = bst->root;
	while (!isLeaf(cur)) {
		if (key < cur->key)
		{
			if (cur->links[left_child] == NULL) {
				cur->links[left_child] = node;
				node->links[parent] = cur;
				break;
			}
			else
			{
				cur = cur->links[left_child];
			}
		}
		else
		{
			if (cur->links[right_child] == NULL) {
				cur->links[right_child] = node;
				node->links[parent] = cur;
				break;
			}
			else
			{
				cur = cur->links[right_child];
			}
		}
	}
}

int BST_find(BST* bst, int key) {
	//if the tree is empty
	if (empty(bst)) {
		return 0;
	};

}

static void del_node(bst_node* node) {
	if (node->links[left_child] != NULL) 
		del_node(node->links[left_child]);
	if (node->links[right_child] != NULL) 
		del_node(node->links[right_child]);
	free(VOID(node));
}