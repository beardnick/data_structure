#include<stdio.h>
int a[2][7] ={{3 , 1 , 7 , 2 , 4 , 8 , 4} , {1 , 2 , 3 , 4 , 5 , 6 , 7}};
void solve(int start , int code , int size)
{
    int i;
    int newStart , newCode;
    if( size <1)return;
    else
    {
    newStart = (start - 1 + code)%size;
    if(newStart == 0)newStart = size;
    newCode = a[0][newStart - 1];
     printf("%d " , a[1][newStart-1]);
    for(i = newStart - 1 ; i < size -1 ; i ++)
    {
        a[0][i] = a[0][i + 1];
        a[1][i] =a [1][i+1];
    }
    solve(newStart , newCode , --size);
    }
    }
int main()
{
    solve(1 , 20 , 7);
    return 0;
}
