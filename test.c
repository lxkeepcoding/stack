#define _CRT_SECURE_NO_WARNINGS   1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>


typedef char DataStackType;
//����һ����ջ
typedef struct StackNode
{
	DataStackType* a;
	int capacity;
	int top;
}ST;

//��ջ
void StackPushBack(ST* ps, DataStackType x);
//��ʼ��
void StackInit(ST* ps);
//��ջ
void StackPop(ST* ps);
//��ӡ
DataStackType StackTop(ST* ps);
//����
void StackDestroy(ST* ps);
bool StackEmpty(ST* ps);
int Stacksize(ST* ps);

//��ջ
void StackPushBack(ST* ps, DataStackType x)
{
	assert(ps);
	//β���漰�����ݵ�����
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity = 0 ? 4 : (ps->capacity * 2);
		DataStackType* tmp = realloc(ps->a, sizeof(DataStackType)* newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		//�¿��ٵ������ַ��ֵ���ṹ�嵱�е�����
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	//���鵱��β�˽��в���
	ps->a[ps->top] = x;
	ps->top++;
}
//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (DataStackType*)malloc(sizeof(DataStackType)*4);
	ps->capacity = 4;
	ps->top = 0;
}
//һ��һ����ջɾ���������еĺۼ�
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//һ��һ����ջ��ӡ
DataStackType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

//����
void StackDestroy(ST* ps)
{
	assert(ps);
	//�ͷ������ڴ�
	free(ps->a);
	ps->a = NULL;

	ps->capacity = 0;
	ps->top = 0;
}
//�ж��Ƿ�Ϊ�գ���bool���͵ķ���ֵ
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;//�ж��±��Ƿ��ǿ�
}
int Stacksize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool isValid(char* s) {
	assert(s);
	ST st;
	//��ʼ��
	StackInit(&st);
	//ȡ�ַ����еķ��ţ��������žͽ�ջ
	while (*s)
	{
		if (*s == '('
			|| *s == '['
			|| *s == '{')
		{
			StackPushBack(&st, *s);
			++s;
		}
		else
		{
			//��ջ����û������˵��û�����������ȡ�������Ž���ƥ�䣬����false
			if (StackEmpty(&st))
			{
				//ֻҪ���������ݾͲ��ǿ�ջ��������������ĿС����������Ŀ���ͻ�ջ��û�з��ŵ��ǻ������ݣ���ʱ��Ӧ�����ջ���������ڴ�й©������false
				StackDestroy(&st);
				return false;
			}
			//����ȡ�Ĳ��������ţ��ͽ��Ѿ���ջ��������ȡ������ƥ��
			DataStackType top = StackTop(&st);
			//ջ���±���ǰ��һλ
			StackPop(&st);

			//����ƥ��ʱ���ͷ���FALSE
			if (*s == ')' && top != '('
				|| *s == ']' && top != '['
				|| *s == '}' && top != '{')
			{
				StackDestroy(&st);//�����ڴ�й©
				return false;
			}
			else
			{
				//���ƥ�������һλ����
				s++;
			}

		}

	}

	//��ջ����Ϊ�գ�˵��ջ������������û�н���ƥ��
	bool ret = StackEmpty(&st);
	//����
	StackDestroy(&st);

	return ret;
}

int main()
{

}