#include "test_stdafx.h"
#include "BST.h"

#define number 12

int main() {
	BST* temp = EMPTY_BST();
	srand(time(0));
	for (int i=0;i<number;i++){
		int num = rand() % 125-60;
		printf("%d\n",num);
		BST_insert(temp, num);
	};
	display(temp);
	//for (int i = 0; i < 3; i++) {
	//	int query;
	//	bst_node* container;
	//	printf("enter a number u want to query\n");
	//	scanf_s("%d",&query);
	//	container = BST_find(temp,query);
	//	if (container == NULL) {
	//		printf("%d not found\n",query);
	//	}
	//	else
	//	{
	//		printf("%d\n",container->key);
	//	}
	//}
	del_BST(temp);
	system("pause");
	return 0;
}


