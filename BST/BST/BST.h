#pragma once


//some numbers refer to the parent or children of a 
//bst node
enum {
	parent=0,
	left_child,
	right_child
};

//a bst_node is a root when its links[parent]==NULL
//a bst_node is a leaf when its links[left_child]==NULL and links[right_child]==NULL
typedef struct bst_node {
	int key;
	struct bst_node* links[3];
} bst_node;

typedef struct {
	bst_node* root;
}BST;



