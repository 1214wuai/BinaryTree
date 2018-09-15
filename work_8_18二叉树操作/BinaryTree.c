#include"BinaryTree.h"
#include"Stack.h"
BTNode* BuyBTNode(BTDataType x)
{
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = x;
	root->_left = NULL;
	root->_right = NULL;
	return root;
}
BTNode* BinaryTreeCreat(BTDataType *a, int n, int *pi)
{
	if (a[*pi] != '#')
	{
		BTNode *root = BuyBTNode(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreat(a, n, pi);
		(*pi)++;
		root->_right = BinaryTreeCreat(a, n, pi);
		return root;
	}
	else
		return NULL;
}
void BinaryTreePrevOrder(BTNode *root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode *root)//中序
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreeInOrder(root->_right);

}
void BinaryTreePostOrder(BTNode *root)//后序
{
	{
		if (root == NULL)
			return;
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);

	}
}
int BinaryTreeSize(BTNode *root)
{
	if (root == NULL)
		return 0;
	else
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
}
int BinaryTreeLeafSize(BTNode *root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
void BinaryTreeDestroy(BTNode **proot)
{
	assert(proot);
	if (*proot == NULL)
		return;
	BTNode*  root = *proot;
	BinaryTreeDestroy(&(root->_left));
	BinaryTreeDestroy(&(root->_right));
	free(root);
	*proot = NULL;
}
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode *L = BTreeFind(root->_left, x);
	if (L != NULL)
		return L;
	BTNode *R = BTreeFind(root->_right, x);
	if (R != NULL)
		return R;
	return NULL;
}
void BTreeLevelOrder(BTNode* root)//层序
{
	Queue *Q = QueueInit();
	if (root == NULL)
		return;
	QueuePush(Q, root);
	while (QueueEmpty(Q))
	{
		BTNode *p = QueueFront(Q);
		printf("%c ",p->_data);
		
		if (p->_left != NULL)
			QueuePush(Q, p->_left);
		if (p->_right != NULL)
			QueuePush(Q, p->_right);
		QueuePop(Q);
	}
}
int IsCompleteBTree(BTNode* root)
{
	Queue *Q = QueueInit();
	if (root)
		QueuePush(Q, root);
	while (QueueEmpty(Q))
	{
		BTNode *p = QueueFront(Q);
		QueuePop(Q);
		if (p)
		{
			QueuePush(Q, p->_left);
			QueuePush(Q, p->_right);
		}
		else
			break;
	}
	while (QueueEmpty(Q))
	{
		QueueNode *p = QueueFront(Q);
		if (p)
		{
			QueueDestroy(Q);
			return 0;
		}
		else
			QueuePop(Q);
	}
		return 1;
}
int IsCompleteBTreeflag(BTNode* root)// flag的方式判断 
{
	int flag = 1;
	QueueNode *Q = QueueInit();
	if (root == NULL)
		return 1;
	QueuePush(Q, root);
	while (QueueEmpty(Q) && flag == 1)
	{
		BTNode* cur = QueueFront(Q);
		if (cur->_left != NULL)
			QueuePush(Q, cur->_left);
		else
			flag = 0;
		if (cur->_right != NULL)
			QueuePush(Q, cur->_right);
		else
			flag = 0;
		QueuePop(Q);
	}
	while (QueueEmpty(Q))
	{
		BTNode *p = QueueFront(Q);
		
		if (p->_left == NULL && p->_right == NULL)
			QueuePop(Q);
		else
			return 0;
	}
	return 1;
}
void BTreePrevOrderNonR(BTNode* root)
{
	Stack s;
	StackInit(&s);
	BTNode * cur;
	cur = root;
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			printf("%c", cur->_data);
			cur = cur->_left;
		}
		BTNode *top = StackTop(&s);
		StackPop(&s);
		cur = top->_right;
	}
}
void BTreeInOrderNonR(BTNode* root)
{
	BTNode *cur = root;
	BTNode *top;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		printf("%c", top->_data);
		StackPop(&s);
		cur = top->_right;
	}
}
void BTreePostOrderNonR(BTNode* root)
{
	Stack s;
	BTNode* cur = root;
	BTNode* top;
	BTNode *prev=NULL;
	StackInit(&s);
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
			cur = top->_right;
	}
}
