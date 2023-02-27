#pragma one
#define N 10
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
#define INIT_CAPACITY 4
//struct SeqList
//{
//	int a[N];
//	int size;
//};
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
int SLFind(SL* ps, SLDataType x);