#include<stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct  Node
{
    int data;
    struct Node * next;
}Node , *LinkList;

//initialize the list
//set next NULL

void InitList(LinkList * l)
{
    *l = (Node*)malloc(sizeof(Node*));
    (*l)->next = NULL;
}

void CreateFromTail(LinkList l , int value)
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    Node* tail;
    tail = l;
    while(tail->next != NULL)tail = tail->next;
    tail->next = p;
    p->next = NULL;
}

//print all the elems

void PrintAll(LinkList l)
{
    Node* p;
    p = l;
    while( p->next != NULL)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
}


LinkList minusSet(LinkList la , LinkList lb)
{
    LinkList lc;
    InitList(&lc);
    int flag;
    Node *p , *s;
    p = la;
    s = lb;
    while(p->next != NULL)
    {
        p = p->next;
        s = lb;
        flag = 1;
        while(s->next != NULL)
        {
            s = s->next;
            if( p->data == s->data)
            {
                flag = 0;
                break;
            }
        }
        if(flag)CreateFromTail(lc , p->data);
    }
    return lc;
}

int main()
{
    int i;
    LinkList la , lb;
    InitList(&la);
    InitList(&lb);
    srand((unsigned)time(NULL));
    for( i = 0 ; i < 10 ; i ++)
    {
        CreateFromTail(la, rand()%20);
        CreateFromTail(lb , rand()%20);
    }
    PrintAll(la);
    PrintAll(lb);
    PrintAll(minusSet(la , lb));
    return 0;
}
