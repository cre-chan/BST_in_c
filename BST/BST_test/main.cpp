#include "test_stdafx.h"
#include "BST.h"



int main() {
	BST* temp = EMPTY_BST();
	srand(time(0));
	for (int i=0;i<25;i++){
		BST_insert(temp, rand()%17);
	};
	del_BST(temp);
	system("pause");
	return 0;
}


