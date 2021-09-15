
#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>


typedef int SDataType;
typedef struct Stack
{
	SDataType *a;
	int top;//ջ��
	int capacity;//��������������
}Stack;


//��ʼ��
void StackInit(Stack *pst);
//����
void StackDestory(Stack *pst);
//��ջ
void StackPush(Stack *pst,SDataType x);
//��ջ
void StackPop(Stack *pst);
//ȡջ������
SDataType StackTop(Stack *pst);
//�жϿ�ջ
bool StackEmpty(Stack *pst);
//ȡջ�����ݸ���
int StackSize(Stack *pst);