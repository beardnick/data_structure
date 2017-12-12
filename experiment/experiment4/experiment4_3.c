#include <stdio.h>
#define MAX_SIZE 100
#define INF 10000

int graph[MAX_SIZE][MAX_SIZE];

int findMin(int size){
    int i , j;
    int ki , kj;
    ki = kj = 0;
    for( i = 0 ; i < size ; i ++){
        for(j = 0 ; j < size ; j ++){
            if(graph[i][j] < graph[ki][kj] && graph[i][j]){
                ki = i;
                kj = j;
            }
        }
    }
    return  ki;
}

int main(){
    int prime[MAX_SIZE] = {0};
    int size , j , i;
    int k;
    scanf("%d" , &size);
    for( i = 0 ; i < size ; i ++){
        prime[i] = INF;
        for( j = 0 ; j < size ; j ++){
            scanf("%d" , &graph[i][j]);
            if(graph[i][j] == 0){
                graph[i][j] = INF;
            }
        }
    }
    int counter = 0 , u;
    u = findMin(size);
   // printf("%d\n" , u);
    for (j = 0 ; j < size ; j ++) {
        prime[u] = -1;
        for(i = 0 ; i < size ; i ++) {
            if (prime[i] != -1) {
                prime[i] = prime[i] < graph[u][i] ? prime[i] : graph[u][i];
            }
        }
             k = 0;
            for(i = 0 ; i < size ; i ++){
                if(prime[k] == -1 ){
                    k ++;
                }else if(prime[i] < prime[k] && prime[i] != -1){
                    k = i;
                }
            }
            u = k;
           // printf("%d\n" , prime[u]);
            counter += prime[u];

    }
    printf("%d\n" , counter);

    return  0;
}