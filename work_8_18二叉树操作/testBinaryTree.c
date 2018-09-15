#include"BinaryTree.h"
#include"Heap.h"
Test()
{
	char array[] = { 'A','B','D','#','#','#','C','E','#','#','F','#','#' };
	//char array[] = { 'A','B','D','#','#','X','#','#','C','E','#','#','F','#','#' };
	//char array[] = { 'A','B','D','#','#','X','#','#','C','E','#','#','#' };

	size_t i = 0;
	BTNode *root = BinaryTreeCreat(array, sizeof(array) / sizeof(BTDataType), &i);

	printf("\n前序：");
	BinaryTreePrevOrder(root);//前序
	printf("\n");
	BTreePrevOrderNonR(root);

	printf("\n中序：");
	BinaryTreeInOrder(root);//中序
	printf("\n");
	BTreeInOrderNonR(root);

	printf("\n后序：");
	BinaryTreePostOrder(root);//后序
	printf("\n");
	BTreePostOrderNonR(root);

	printf("\n");

	BTreeLevelOrder(root);//层序
	printf("\n");
	int Is = IsCompleteBTree(root);//完全二叉树
	printf("IsComplete?%d\n", Is);
	int Is1 = IsCompleteBTreeflag(root);
	printf("IsComplete1?%d\n", Is1);

	int sz = BinaryTreeSize(root);//结点个数
	printf("%d\n", sz);
	int szleaf = BinaryTreeLeafSize(root);//叶结点个数
	printf("%d\n", szleaf);
	int szlevelk = BinaryTreeLevelKSize(root, 2);//第k行结点个数
	printf("%d\n", szlevelk);
	
	BTNode *F = BTreeFind(root, 'C');//寻找一个结点
	if(F!=NULL)
		printf("%c", F->_data);
	BinaryTreeDestroy(&root);//销毁二叉树
	BinaryTreeInOrder(root);
}
testHeap()
{
	Heap hp;
	int array[] = { 53,17,78,9,45,65,87,23,31 };
	HeapInit(&hp, array, sizeof(array) / sizeof(HPDataType));//初始化为小堆
	HeapPrint(&hp);
	HeapPush(&hp, 6);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HPDataType Top = HeapTop(&hp);
	printf("top：%d\n", Top);
	int sz = HeapSize(&hp);
	printf("sz：%d\n", sz);
	int empty = HeapEmpty(&hp);
	printf("Is Empty?%d\n",empty);
	HeapSort(&array, sizeof(array) / sizeof(HPDataType));
	HeapPrint1(&array,sizeof(array)/sizeof(HPDataType));
	HeapDestory(&hp);
	 //时间常数logN
	 //堆的应用
	 //100亿个数之前最大的K个数：建K个小堆（小数在堆顶）
	 // 最下的K个数：建K个大堆

}
int main()
{
	Test();
	//testHeap();
	system("pause");
	return 0;
}