#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    int *a = (int*)malloc(N);
    for(int i = 0; i<N;i++){
        a[i]=i;
    }
    printf("NORMAl");

    return 0;
}