#include <stdio.h>
#include <stdlib.h>
#include "../List/CircleLinkList.h"
#define N 100

int main() {
    int a[N] , start , m , n , i;
    printf("please enter start , code , size !\n");
    scanf("%d%d%d",&start , &m , &n);
    printf("please enter the code of each person !\n");
    for(i = 0 ;i < n ; i ++){
        scanf("%d",&a[i]);
    }
    CLinkList  linkList;
    InitCList(&linkList);
    for( i = 0 ; i < n  ; i ++){    //@csk    after i ++ then check whether i < n
        CreateFromTailCList(linkList , a[i]);
    }
    Node* p = linkList;
    Node* temp;
    while (-- start){
        p = p->next;
        if(p->next == linkList)p =linkList;
    }
    while (n --){
        while (-- m){
            p = p->next;
            if(p->next == linkList )p = linkList;
        }
        temp = p->next;
        printf("%d ", temp->id);
        m = temp->data;
        p->next = temp->next;
        if(p->next == linkList )p = linkList;
        if(p == linkList && p->next == linkList)break;//it will delete the head last
        free(temp);
    }
    return 0;
}
