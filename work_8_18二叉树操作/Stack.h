#include<stdio.h>
#include<assert.h>
#include"BinaryTree.h"
#define N 10
typedef struct BinaryTreeNode* DataType;

typedef struct Stack
{
	DataType *_array;
	int _top; //ջ�� 
	int _capacity;//����
}Stack, *pStack;

////////////////////////////////////////////////////// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);//��ʼ��
void StackPush(Stack* s, DataType x);//��ջ
void PrintStack(Stack *s);//��ӡջ
void StackPop(Stack* s);//��ջ

DataType StackTop(Stack* s);//����ջ��
size_t StackSize(Stack* s);//��ջ�ĳ���
int StackEmpty(Stack* s);//�п�
void StackDestroy(Stack *s);//���