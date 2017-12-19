#include <stdio.h>

#define MAX_SIZE 100000
int a[MAX_SIZE] ;

void shellSort(int begin , int end){
    int d = (end - begin)/3 + 1;
    int temp , i , j;
    while (d > 1){
        for(i = 0 ; i < d ; i ++){
            for(j = )
        }
    }

}

int main(){
    int n , i;
    scanf("%d" , &n);
    for(i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]);
    }
    for(i = 0 ; i < n ; i ++){
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}