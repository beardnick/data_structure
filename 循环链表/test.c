#include<stdio.h>
#include"CircleLinckList.h"
int main()
{
    CLinkList l;
    InitCList(&l);
    int  i ;
    for( i = 0 ; i < 100 ; i ++)
    {
        CreateFromTailCList(l , i);
    }
   PrintAllC(l);
    return 0;
}
