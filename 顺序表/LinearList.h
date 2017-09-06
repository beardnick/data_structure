#ifndef LINEARLIST_H_INCLUDED
#define LINEARLIST_H_INCLUDED
#define MAXSIZE 100
#include<stdio.h>

//define the struct
//last is the index of the last elem in the list

typedef struct
{
    int elem[MAXSIZE];
    int last;
}SeqList;

//initialize last = -1 , set the list as null

void InitList(SeqList *l)
{
    l->last =-1;
}

//insert an element to the list

int InseList(SeqList* l , int i , int elem)
{
    if(i < 1 || i > l->last + 2 || l->last >= MAXSIZE)return 0;
    int  k ;
    for( k = i - 1 ; k <= l->last ; k ++)
    {
        l->elem[k+1]=l->elem[k];
    }
    l->elem[i-1] = elem;
    l->last += 1;
    return 1;
}

//delete  an element from the list

int DeleList(SeqList* l , int i )
{
    if(l->last == -1 || i < 1 || i > l->last + 1)return 0;
    int k;
    for( k = i - 1 ; k < l->last ; k ++)
    {
        l->elem[k] = l->elem[k+1];
    }
    l->last -= 1;
    return 1;
}

//find a key from the list

int FindList(SeqList l  , int key)
{
    int k;
    for( k = 0 ; k <= l.last ; k ++)
    {
        if( l.elem[k] == key)return k + 1;
    }
    return -1;
}

//catch two list

int CatcList(SeqList* l1 , SeqList* l2)
{
    int k , j;
    if(l1->last + l2->last + 2 > MAXSIZE )return 0;
    for( k = l1->last + 1 , j = 0 ; k <= l1->last + l2->last +1 && j <= l2->last ; k ++ , j ++)
    {
        l1->elem[k] = l2->elem[j];
    }
    l1->last +=(l2->last +1) ;
    return 1;
}

//print all the elems in the list

void PrintAll(SeqList l)
{
    int i;
    for( i = 0 ; i <= l.last ; i ++)
    {
        printf("%d ", l.elem[i]);
    }
    printf("\n");
}


#endif // LINEARLIST_H_INCLUDED
