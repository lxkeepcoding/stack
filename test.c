#define _CRT_SECURE_NO_WARNINGS   1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>


typedef char DataStackType;
//声明一个堆栈
typedef struct StackNode
{
	DataStackType* a;
	int capacity;
	int top;
}ST;

//入栈
void StackPushBack(ST* ps, DataStackType x);
//初始化
void StackInit(ST* ps);
//出栈
void StackPop(ST* ps);
//打印
DataStackType StackTop(ST* ps);
//销毁
void StackDestroy(ST* ps);
bool StackEmpty(ST* ps);
int Stacksize(ST* ps);

//入栈
void StackPushBack(ST* ps, DataStackType x)
{
	assert(ps);
	//尾插涉及到增容的问题
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity = 0 ? 4 : (ps->capacity * 2);
		DataStackType* tmp = realloc(ps->a, sizeof(DataStackType)* newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		//新开辟的数组地址赋值给结构体当中的数组
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	//数组当中尾端进行插入
	ps->a[ps->top] = x;
	ps->top++;
}
//初始化
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (DataStackType*)malloc(sizeof(DataStackType)*4);
	ps->capacity = 4;
	ps->top = 0;
}
//一个一个出栈删除在数组中的痕迹
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//一个一个出栈打印
DataStackType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

//销毁
void StackDestroy(ST* ps)
{
	assert(ps);
	//释放数组内存
	free(ps->a);
	ps->a = NULL;

	ps->capacity = 0;
	ps->top = 0;
}
//判断是否为空，用bool类型的返回值
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;//判断下标是否是空
}
int Stacksize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool isValid(char* s) {
	assert(s);
	ST st;
	//初始化
	StackInit(&st);
	//取字符串中的符号，是左括号就进栈
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
			//当栈区中没有数据说明没有左括号与读取的有括号进行匹配，返回false
			if (StackEmpty(&st))
			{
				//只要进入了数据就不是空栈区，当左括号数目小于右括号数目，就会栈区没有符号但是还有数据，此时就应该清空栈区，避免内存泄漏，返回false
				StackDestroy(&st);
				return false;
			}
			//当读取的不是左括号，就将已经进栈的左括号取出进行匹配
			DataStackType top = StackTop(&st);
			//栈区下标往前走一位
			StackPop(&st);

			//当不匹配时，就返回FALSE
			if (*s == ')' && top != '('
				|| *s == ']' && top != '['
				|| *s == '}' && top != '{')
			{
				StackDestroy(&st);//避免内存泄漏
				return false;
			}
			else
			{
				//如果匹配就往下一位继续
				s++;
			}

		}

	}

	//当栈区不为空，说明栈区还有左括号没有进行匹配
	bool ret = StackEmpty(&st);
	//销毁
	StackDestroy(&st);

	return ret;
}

int main()
{

}