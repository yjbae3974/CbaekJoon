//
// Created by 배연준 on 2022/01/10.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d",&n);
    int* arr1 = calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&m);
    int* arr2 = calloc(m,sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    for(int i=0;i<m;i++){
        int able = 0;
        for (int j = 0; j < n; ++j) {
            if(arr2[i] == arr1[j]){
                able = 1;
                break;
            }
        }
        printf("%d\n",able);
    }

}