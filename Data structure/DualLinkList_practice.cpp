// DualLinkList_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define OK      1
#define ERROR   0

typedef char    ElemType;
typedef int     Status;

typedef struct DualNode
{
    ElemType data;
    struct DualNode* prior; // 前驱节点
    struct DualNode* next;  // 后继节点
}DualNode, *DuLinkList;     // 给DualNode这个结构，起了两个名字

Status InitList(DuLinkList* L) // 初始化双向链表
{
    DualNode* p, * q; // 需要两个指针交替生成一串链
    int i;

    *L = (DuLinkList)malloc(sizeof(DualNode)); // 头结点生成，分配DualNode大小的空间
    if (!(*L)) // 如果生成失败
    {
        return ERROR;
    }
    (*L)->next = (*L)->prior = NULL; // 头尾都初始NULL

    p = (*L); // p先定位头结点

    for (i = 0; i < 26; i++) // 生成26个结点存放26个字母
    {
        q = (DualNode*)malloc(sizeof(DualNode));
        if (!q)
        {
            return ERROR;
        }
        q->data = 'A'+i; // 生成了个q结点，用ACSii码给字母

        q->prior = p;
        q->next = p->next;
        p->next = q; // 把q接到p的后面去

        p = q; // p挪到已经生成好的q，q可以生成下一个
    }

    p->next = (*L)->next;
    (*L)->next->prior = p; 
    (*L) = p; // 将头结点移出链表, 头指针直接指最后

    return OK;
}

void Caesar(DuLinkList* L, int i)
{
    if (i > 0)
    {
        do
        {
            (*L) = (*L)->next; // 头结点指向链表的下一个位置
        } while (--i);
    }

    if (i < 0)
    {
        do
        {
            (*L) = (*L)->prior; // 头结点指向链表最后一个位置
        } while (++i);
    }
} // 将整个链表挪动

int main()
{
    DuLinkList L;
    int i, n;

    InitList(&L);

    printf("Input an integer:");
    scanf_s("%d", &n);
    printf("\n");
    Caesar(&L, n);

    for (i = 0; i < 26; i++)
    {
        L = L->next;
        printf("%c ", L->data);
    } // 打印出链表

    printf("\n");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file