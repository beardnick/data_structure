#include<stdio.h>
#include"LinearList.h"
int main()
{
    SeqList l;
    InitList(&l);
    SeqList a;
    InitList(&a);
    int i;
    for(i = 0 ; i < 10 ; i ++)
    {
        InseList(&l , i +1, i+1);
        InseList(&a , i +1, i+1);
        printf("%d ", l.elem[i]);
    }
    printf("\n");
    CatcList(&l , &a);
    for( i = 0 ; i <= l.last ; i ++)
    {
        printf("%d " , l.elem[i]);
    }
    printf("\n");
    DeleList(&l , 9);
     for( i = 0 ; i <= l.last ; i ++)
    {
        printf("%d " , l.elem[i]);
    }
    printf("\n");
    printf("%d\n" , FindList(l , 9));
    return 0;
}
