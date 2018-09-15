#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode* DataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
}BTNode;

BTNode* BuyBTNode(BTDataType x);
BTNode* BinaryTreeCreat(BTDataType *a, int n, int *pi);
int BinaryTreeSize(BTNode *root);
int BinaryTreeLeafSize(BTNode *root);
int BinaryTreeLevelKSize(BTNode *root, int k);
void BinaryTreeDestroy(BTNode **proot);
void BinaryTreePrevOrder(BTNode *root);//ǰ��
void BinaryTreeInOrder(BTNode *root);//����
void BinaryTreePostOrder(BTNode *root);//����
void BTreeLevelOrder(BTNode* root);//����
typedef struct QueueNode
{
	DataType tree;
	struct QueueNode* _next;

}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;

}Queue;
Queue* QueueInit();
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
void QueueDestroy(Queue* q);
int QueueEmpty(Queue* q);
BTNode* BTreeFind(BTNode* root, BTDataType x);

// �ж���ȫ������ 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTreeflag(BTNode* root);// flag�ķ�ʽ�ж� 
//								   // �ǵݹ���� 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);

#endif // !__BINARYTREE_H__
