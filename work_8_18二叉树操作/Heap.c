#include"Heap.h"
void Swap(HPDataType *x1, HPDataType *x2)
{
	assert(x1&&x2);
	HPDataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
void AdjustDown(HPDataType *a, int n, int root)//小堆
{
	assert(a);
	int parent = root;
	size_t child = 2*parent + 1;
	while (child < n)
	{
		if (a[child+1] < a[child ] && child+1 < n)
			++child;
		if (a[child] < a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}

}
void AdjustDown2(HPDataType *a, int n, int root)//大堆
{
	assert(a);
	int parent = root;
	size_t child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child + 1] > a[child] && child + 1 < n)
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}

}
void AdjustUp(HPDataType* a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity * 2);
	hp->_a[hp->_size] = x;
	hp->_size++;
	//调整
	int child = hp->_size-1;
	int parent = (child - 1) / 2;
	while (hp->_a[child] < hp->_a[parent]&&child>=0)
	{
		Swap(&hp->_a[child], &hp->_a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	return(hp->_size == 0);
}

void HeapPrint(Heap *hp)
{
	assert(hp);

	for (int i = 0; i<hp->_size; i++)
	{
		printf("%d ",hp->_a[i]);
	}
	printf("\n");
}
void HeapPrint1(HPDataType* a,int sz)
{
	assert(a);
	int i = 0;
	
	for (i = 0; i<sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//赋值
	for (int i = 0; i<n; i++)
	{
		hp->_a[i] = a[i];
	}
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, n, i);//小堆
		//AdjustDown2(hp->_a, n, i);//大堆
	}
}
void HeapSort(HPDataType* a, int n)
{
	int i, end;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
