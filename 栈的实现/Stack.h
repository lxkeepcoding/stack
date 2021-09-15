
#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>


typedef int SDataType;
typedef struct Stack
{
	SDataType *a;
	int top;//栈顶
	int capacity;//容量，方便增容
}Stack;


//初始化
void StackInit(Stack *pst);
//销毁
void StackDestory(Stack *pst);
//入栈
void StackPush(Stack *pst,SDataType x);
//出栈
void StackPop(Stack *pst);
//取栈顶数据
SDataType StackTop(Stack *pst);
//判断空栈
bool StackEmpty(Stack *pst);
//取栈的数据个数
int StackSize(Stack *pst);