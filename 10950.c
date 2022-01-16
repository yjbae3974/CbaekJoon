//
// Created by brian on 2022-01-12.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d",&num);
    int **arr = calloc(num, sizeof(int*));
    for (int i = 0; i < num; ++i) {
        arr[i] = (int*) calloc(2, sizeof(int));
    }
    for (int i = 0; i < num; ++i) {
        scanf("%d %d",&arr[i][0], &arr[i][1]);
        printf("%d\n",arr[i][0] + arr[i][1]);
    }
}