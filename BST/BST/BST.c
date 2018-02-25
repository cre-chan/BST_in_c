#include "BST_stdafx.h"
#include "BST.h"
#include "queue.h"

#define NEW_BST() ((BST*)malloc(sizeof(BST)))
#define NEW_NODE() ((bst_node*)malloc(sizeof(bst_node)))
#define empty(bst) (bst->root==NULL)
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
static void show_node(bst_node* bst);

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
		node->index = 1;
		return;
	};

	//cur points to a node
	//and cur moves down the tree while cur is not a leaf
	bst_node* cur = bst->root;
	while (cur!=NULL) {

		//if the key is less than the cur's key
		//the cur go to its left_child
		//if the left_child is null, insert here and break
		if (key < cur->key)
		{
			if (cur->links[left_child] == NULL) {
				cur->links[left_child] = node;
				node->links[parent] = cur;
				node->index = cur->index * 2;
				break;
			}
			else
			{
				cur = cur->links[left_child];
			}
		}
		else if (key == cur->key) {
			return;
		}
		else
		{
			if (cur->links[right_child] == NULL) {
				cur->links[right_child] = node;
				node->links[parent] = cur;
				node->index = cur->index * 2+1;
				break;
			}
			else
			{
				cur = cur->links[right_child];
			}
		}
	}
}

bst_node* BST_find(BST* bst, int key) {
	//if the tree is empty
	if (empty(bst)) {
		return NULL;
	};

	//the cur moves down the tree until it
	//meets the key or a null pointer
	//return the cur at last
	bst_node* cur = bst->root;
	while (cur != NULL)
	{
		printf("cur is %d\n",cur->key);
		if (cur->key == key) {
			break;
		}
		else if (cur->key < key)
		{
			cur = cur->links[right_child];
		}
		else
		{
			cur = cur->links[left_child];
		}
	}

	return cur;
}

void display(BST* bst) {
	if (empty(bst)) return;
	queue* q = EMPTY_QUEUE();
	enqueue(q,bst->root);
	while (q->length != 0)
	{
		bst_node* cur = (bst_node*)dequeue(q);
		printf("%d-%d ", cur->key, cur->index);
		if (cur->links[left_child] != NULL)enqueue(q, (void*)cur->links[left_child]);
		if (cur->links[right_child] != NULL)enqueue(q, (void*)cur->links[right_child]);
	}
	
	printf("\n");
	//show_node(bst->root);
	printf("\n");
}

static void show_node(bst_node* node) {
	printf("%d-%d ",node->key,node->index);
	if (node->links[left_child]!= NULL) show_node(node->links[left_child]);
	if (node->links[right_child] != NULL) show_node(node->links[right_child]);
};

static void del_node(bst_node* node) {
	//del the children nodes
	if (node->links[left_child] != NULL) 
		del_node(node->links[left_child]);
	if (node->links[right_child] != NULL) 
		del_node(node->links[right_child]);
	//free the node
	free(VOID(node));
}