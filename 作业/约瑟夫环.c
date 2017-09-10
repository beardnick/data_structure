#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    int data;
    struct Node* next;
}Node  , *CLinkList;

//initialize the list

void InitCList(CLinkList  *l)
{
    *l = (Node*)malloc(sizeof(Node*));//do not miss * , because l is a pointer of Node*
    (*l)->next = *l;
}

//create from tail

void CreateFromTailCList(CLinkList l , int value)
{
    int count = 1;
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = value;
    p->next = l;
    Node* temp = l;
    while(temp->next != l){
        temp = temp->next;
        count ++;
    }
    temp->next = p;
    p->id = count;
}

//delect from the list

void deleteFromList(CLinkList l , Node* p){
    Node* s;
    s = l;
    while (s->next != p)s = s->next;
    if(s->next != l){
        s = p->next;
        free(p);
        p = s;
    }
}


int main() {
    int a[] ={3 , 1 , 7 , 2 , 4 , 8 , 4};
    CLinkList  linkList;
    InitCList(&linkList);
    int i , m = 20 , n = 7;
    for( i = 0 ; i < n  ; i ++){    //@csk    after i ++ then check whether i < n
        CreateFromTailCList(linkList , a[i]);
    }
    int test;
    Node* p = linkList;
    Node* temp;
    while (n --){
        while (-- m){
            p = p->next;
            if(p->next == linkList || p == linkList)p = p->next;
        }
        temp = p->next;
        printf("%d ", temp->id);
        m = temp->data;
        p->next = temp->next;
        //free(temp);
    }
    return 0;
}
