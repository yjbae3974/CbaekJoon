//
// Created by 배연준 on 2022/02/02.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int weight;
    int height;
}Donchi;


int main(){
    int n;
    scanf("%d",&n);
    Donchi *arr = calloc(n,sizeof(Donchi));
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&arr[i].weight,&arr[i].height);
    }
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i].weight < arr[j].weight && arr[i].height < arr[j].height) {
                rank++;
            }
        }
        printf("%d ",rank);
        rank = 1;
    }
}