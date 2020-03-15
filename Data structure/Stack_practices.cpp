#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct
{
    ElemType* base;
    ElemType* top;
    int stackSize;
}sqStack; // 顺序存储结构的栈

void InitStack(sqStack* s)
{
    s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack* s, ElemType e)
{
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }
    } // 检查是否溢出，如果溢出则realloc空间给栈

    *(s->top) = e;
    s->top++;
}

void Pop(sqStack* s, ElemType* e)
{
    if (s->top == s->base)
    {
        return;
    } // 检查是否已经空栈，如果已空则不做操作直接return
    *e = *--(s->top);
}

int StackLen(sqStack s) // 不进行内容修改的话，直接把栈的地址用进来，不用*s，下面也用s.top不用s->top
{
    return(s.top - s.base); // 直接可以返回元素数量，不会返回地址数的差
}

void ClearStack(sqStack* s)
{
    s->top = s->base;
}

void bin2dec(sqStack s, ElemType c, int len) // 二进制换十进制
{
    int i, sum = 0;
    for (i = 0; i < len; i++)
    {
        Pop(&s, &c);
        sum = sum + (c - 48) * pow(2, i);
    }
    printf("The decimal value is: %d\n", sum);
}

void bin2oct(sqStack s, ElemType c, int len)
{
    int i, sum = 0, out = 0, count = 0;

    while(len > 0)
    {
        sum = 0;
        for (i = 0; i < 3; i++)
        {
            Pop(&s, &c);
            sum = sum + (c - 48) * pow(2, i);
            if (--len == 0)
            {
                break;
            }
        }
        out = out + sum * pow(10, count++);
    }

    printf("The octal value is: %d\n", out);
}

void bin2hex(sqStack s, ElemType c, int len)
{
    int i, sum = 0, count = 0;
    char out;
    sqStack hexStack;
    InitStack(&hexStack);

    while (len > 0)
    {
        sum = 0;
        for (i = 0; i < 4; i++)
        {
            Pop(&s, &c);
            sum = sum + (c - 48) * pow(2, i);
            if (--len == 0)
            {
                break;
            }
        }
        if (sum < 10) 
        {
            Push(&hexStack, '0' + sum);
        }
        else
        {
            Push(&hexStack, 'A' + (sum - 10));
        }
    }

    printf("The heximal value is: ");
    while (hexStack.top != hexStack.base)
    {
        Pop(&hexStack, &c);
        printf("%c", c);
    }

    ClearStack(&hexStack);
}

int main()
{
    ElemType c;
    sqStack s;
    int len;

    InitStack(&s);

    printf("Insert a binary number, with # at the end:\n");
    scanf_s("%c", &c);

    while (c != '#')
    {
        Push(&s, c);
        scanf_s("%c", &c);
    }

    getchar(); // 清理键盘缓冲区的'\n'

    len = StackLen(s);
    printf("The used length of stack is %d\n", len);
    printf("\n");

    bin2dec(s, c, len);
    bin2oct(s, c, len);
    bin2hex(s, c, len);

    printf("\n");
    ClearStack(&s);

    return 0;
}