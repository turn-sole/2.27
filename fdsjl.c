#include"SeqList.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}

	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a == NULL;
	ps->capacity = ps->size = 0;
}
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SLPushBack(SL* ps, SLDataType x)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->capacity *= 2;
	}
	ps->a[ps->size++] = x;
}
void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		ps->a = tmp;
		ps->capacity *= 2;
	}
}
void SLPushFront(SL* ps, SLDataType x)
{
	/*assert(ps);

	SLCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;*/

	SLInsert(ps, 0, x);
}
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);

	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	++begin;
	//}

	//ps->size--;

	SLErase(ps, 0);
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}