#include <stdio.h>
#include <stdlib.h>
typedef enum status {
	success,fail,fatal,range_error,
}Status;
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef int ElemType;
typedef struct SqList
{
	ElemType *elem;
	int lenth;
	int list_size;

}SqList, *ptr;
typedef ptr SqListPtr;
Status List_init(SqListPtr L)
{
	Status s = success;
     L->list_size = LIST_INIT_SIZE;
	 L->lenth = 0;
	 L->elem = (ElemType*)malloc(sizeof(ElemType)*L->list_size);
	 if (L->elem==NULL)
	 {
		 s = fatal;
	 }; return s;
}
Status List_Retrival(SqListPtr L,int Pos,ElemType *elem)//按位置查找，返回元素
{
	Status s = range_error;
	if (L)
		if ((Pos-1)>=0&&(Pos-1)<=L->lenth)
		{
			*elem = L->elem[Pos - 1];
			s = success;
		}
		else
		{
			s = fatal;
		}
	return s;
	}
Status List_Locate(SqListPtr L, ElemType elem, int *Pos)//按元素查找，返回位置
{
	Status s = range_error;
	if (L)
	{
		for (int i = 0; i <= L->lenth; ++i)
		{
			if (L->elem == elem)
			{
				*Pos = i + 1; s = success; break;

			}
		}
	}
	else s = fatal; return s;
}
Status List_Insert(SqListPtr L, ElemType elem, int Pos)
{
	Status s = range_error;
	if ((Pos-1)>=0&&(Pos-1)<=L->list_size)
	{if (L&&L->lenth<=L->list_size)
		{
			for  (int i = L->lenth-1; i >= (Pos-1); --i)
			{
				L->elem[i + 1] = L->elem[i];
			};
			L->elem[Pos - 1] = elem;
			s = success;
		}
	}
	else s = fail; return s;
}
int main()
{

}

