#include<stdio.h>
#include<assert.h>
#include"BinaryTree.h"
#define N 10
typedef struct BinaryTreeNode* DataType;

typedef struct Stack
{
	DataType *_array;
	int _top; //栈顶 
	int _capacity;//容量
}Stack, *pStack;

////////////////////////////////////////////////////// 栈的实现接口 
void StackInit(Stack* s);//初始化
void StackPush(Stack* s, DataType x);//入栈
void PrintStack(Stack *s);//打印栈
void StackPop(Stack* s);//弹栈

DataType StackTop(Stack* s);//返回栈顶
size_t StackSize(Stack* s);//求栈的长度
int StackEmpty(Stack* s);//判空
void StackDestroy(Stack *s);//清空