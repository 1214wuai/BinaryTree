
#include"Stack.h"
void StackInit(Stack* s)
{
	assert(s);

	s->_array = (DataType*)malloc(sizeof(DataType)*N);
	s->_top = 0;
	s->_capacity = N;//10
	return;
}
void StackPush(Stack* s, DataType x)
{
	assert(s);

	if (s->_top == s->_capacity)
	{
		s->_array = (DataType*)realloc(s->_array, (s->_capacity + N) * sizeof(DataType));
	}

	s->_array[s->_top] = x;
	s->_top++;
	return;
}

void PrintStack(Stack *s)
{
	assert(s);

	int i = s->_top - 1;
	for (i; i >= 0; i--)
	{
		printf("%c  ", s->_array[i]->_data);
	}
}

void StackPop(Stack* s)
{
	assert(s);

	if (s->_top == -1)
	{
		return ;
	}
	//int pop = s->_top-1;

	s->_top = s->_top - 1;
}

DataType StackTop(Stack* s)
{
	return s->_array[s->_top - 1];
}

size_t StackSize(Stack* s)//求栈的长度
{
	assert(s);

	return s->_top;
}
int StackEmpty(Stack* s)//判空
{
	assert(s);

	if (s->_top == 0)
		return 0;
	else
		return 1;
}
void StackDestroy(Stack* s)//清空栈
{
	assert(s);

	free(s->_array);
	s->_array = NULL;
	s->_top = 0;
}
