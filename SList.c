#define _CRT_SECURE_NO_WARNINGS   1

#include"SList.h"

void SListPrint(SLNode *plist)
{
	SLNode *cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode *BuySLNode(SLDataType x)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPushFront(SLNode **pplist, SLDataType x)
{
	SLNode*newnode = BuySLNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
void SListPushBack(SLNode **pplist, SLDataType x)
{
	SLNode*newnode = BuySLNode(x);
	//空和非空
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		//先遍历找尾
		SLNode *tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		SLNode *newnode = BuySLNode(x);
		tail->next = newnode;
	}
}

void SListPopFront(SLNode **pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLNode *next= (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}
void SListPopBack(SLNode **pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLNode *prev = NULL;
		SLNode *tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}


SLNode*SListFind(SLNode **pplist, SLDataType x)
{
	SLNode *cur = *pplist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void SListModify(SLNode *plist, SLDataType x, SLDataType y)
{
	SLNode *pos = SListFind(&plist, x);
	if (pos)
	{
		pos->data = y;
	}
	else
	{
		printf("没有该数字，无法修改\n");
	}
}


void SListInsertAfter(SLNode *pos, SLDataType x)
{
	assert(pos);
	SLNode *newnode = BuySLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListInsertBefore(SLNode **pplist, SLNode *pos, SLDataType x)
{
	assert(pos);
	SLNode *newnode = BuySLNode(x);
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}

	else
	{
		SLNode *prev = NULL;
		SLNode *cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}


void SListEraseAfter(SLNode*pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLNode*next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}
void SListEraseCur(SLNode **pplist,SLNode*pos)
{
	if (pos == *pplist)
	{
		return;
	}
	else
	{
		SLNode *prev = NULL;
		SLNode *cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = pos->next;
		free(cur);
		cur = NULL;
	}
}