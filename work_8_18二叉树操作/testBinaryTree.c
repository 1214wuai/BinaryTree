#include"BinaryTree.h"
#include"Heap.h"
Test()
{
	char array[] = { 'A','B','D','#','#','#','C','E','#','#','F','#','#' };
	//char array[] = { 'A','B','D','#','#','X','#','#','C','E','#','#','F','#','#' };
	//char array[] = { 'A','B','D','#','#','X','#','#','C','E','#','#','#' };

	size_t i = 0;
	BTNode *root = BinaryTreeCreat(array, sizeof(array) / sizeof(BTDataType), &i);

	printf("\nǰ��");
	BinaryTreePrevOrder(root);//ǰ��
	printf("\n");
	BTreePrevOrderNonR(root);

	printf("\n����");
	BinaryTreeInOrder(root);//����
	printf("\n");
	BTreeInOrderNonR(root);

	printf("\n����");
	BinaryTreePostOrder(root);//����
	printf("\n");
	BTreePostOrderNonR(root);

	printf("\n");

	BTreeLevelOrder(root);//����
	printf("\n");
	int Is = IsCompleteBTree(root);//��ȫ������
	printf("IsComplete?%d\n", Is);
	int Is1 = IsCompleteBTreeflag(root);
	printf("IsComplete1?%d\n", Is1);

	int sz = BinaryTreeSize(root);//������
	printf("%d\n", sz);
	int szleaf = BinaryTreeLeafSize(root);//Ҷ������
	printf("%d\n", szleaf);
	int szlevelk = BinaryTreeLevelKSize(root, 2);//��k�н�����
	printf("%d\n", szlevelk);
	
	BTNode *F = BTreeFind(root, 'C');//Ѱ��һ�����
	if(F!=NULL)
		printf("%c", F->_data);
	BinaryTreeDestroy(&root);//���ٶ�����
	BinaryTreeInOrder(root);
}
testHeap()
{
	Heap hp;
	int array[] = { 53,17,78,9,45,65,87,23,31 };
	HeapInit(&hp, array, sizeof(array) / sizeof(HPDataType));//��ʼ��ΪС��
	HeapPrint(&hp);
	HeapPush(&hp, 6);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HPDataType Top = HeapTop(&hp);
	printf("top��%d\n", Top);
	int sz = HeapSize(&hp);
	printf("sz��%d\n", sz);
	int empty = HeapEmpty(&hp);
	printf("Is Empty?%d\n",empty);
	HeapSort(&array, sizeof(array) / sizeof(HPDataType));
	HeapPrint1(&array,sizeof(array)/sizeof(HPDataType));
	HeapDestory(&hp);
	 //ʱ�䳣��logN
	 //�ѵ�Ӧ��
	 //100�ڸ���֮ǰ����K��������K��С�ѣ�С���ڶѶ���
	 // ���µ�K��������K�����

}
int main()
{
	Test();
	//testHeap();
	system("pause");
	return 0;
}