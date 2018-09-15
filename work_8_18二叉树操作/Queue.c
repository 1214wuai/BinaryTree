
#include"BinaryTree.h"
Queue* QueueInit()
{


	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL)
	{
		q->_head = NULL;
		q->_tail = NULL;

	}
	return q;
}

void QueuePush(Queue* q, DataType x)
{
	assert(q);

	QueueNode* Node = (QueueNode*)malloc(sizeof(QueueNode));
	if (Node != NULL)
	{
		Node->tree = x;
		Node->_next = NULL;

	}
	if (q->_head == NULL)
		q->_head = Node;
	else
		q->_tail->_next = Node;
	q->_tail = Node;
}
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode *p = q->_head;
	if (q->_head != NULL)
	{
		q->_head = q->_head->_next;
		free(p);
		p = NULL;
	}
	if (q->_head == NULL)
		q->_tail = NULL;
}

DataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_head == NULL)
		return NULL;
	return q->_head->tree;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->tree;
}

size_t QueueSize(Queue* q)
{
	assert(q);
	int sz = 0;
	QueueNode *p = q->_head;
	while (p)
	{
		sz++;
		p = p->_next;
	}
	return sz;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_head == NULL)
		return 0;
	else
		return 1;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		QueuePop(q);
	}
	if (q->_head == NULL)
		return ;
}