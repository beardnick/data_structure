#include <stdio.h>

#define MAX_SIZE 100000
int a[MAX_SIZE] ;

int quickSort(int s[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j&&s[j]>x)j--;
            if(i<j)s[i++]=s[j];
            while(i<j&&s[i]<=x)i++;
            if(i<j)s[j--]=s[i];
        }
        s[i]=x;
        quickSort(s,l,i-1);
        quickSort(s,i+1,r);
    }
}

int main(){
    int n , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    quickSort(a , 0 , n - 1);
    for(i = 0 ; i < n ; i ++){
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}