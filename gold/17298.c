//
// Created by 배연준 on 2022/01/26.
//

#include <stdlib.h>
#include <stdio.h>
typedef struct{
    int num;
    int index;
}Number;

int main(){
    int num;
    scanf("%d",&num);
    int *arr = calloc(num,sizeof (int));
    Number *stk = calloc(num,sizeof (Number));
    int tmp, prev, ptr = 0, firstMax;
    int ifmax = 0;
    int stkMax = 0;
    for (int i = 0; i < num; ++i) {
        if(i == 0){
            scanf("%d",&arr[i]);
            prev = arr[i];
            firstMax = arr[i];
        }
        else{
            scanf("%d",&arr[i]);

            if(firstMax < arr[i] && ifmax == 0){
                firstMax = arr[i];
                ifmax = 1;
            }
            if(arr[i]>prev){
                stk[ptr].num = arr[i];
                stk[ptr].index = i;
                if(arr[i] > stkMax){
                    stkMax = arr[i];
                }
                ptr++;
            }
            prev = arr[i];
        }
    }
    if(ifmax == 1){
        printf("%d ",firstMax);
    }
    else{
        printf("-1 ");
    }
    int stkSize = ptr;

    ptr = 0;
    for (int i = 1; i < num; ++i) {
        int temp = arr[i];
        if(stk[ptr].index > i){ //현재 주시하는 친구의 인덱스보다 작은거를 볼 때
            if(stk[ptr].num <= arr[i]){  //그래서 만약 얘가 더 작으면
                if(arr[i]>stkMax){
                    printf("-1 ");
                    break;
                }
                int ifprint = 0;
                for (int j = ptr + 1; j < stkSize; ++j) {
                    if(stk[j].num > arr[i]){
                        printf("%d ",stk[j].num);
                        ifprint = 1;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                if(ifprint == 0)
                    printf("-1 ");
            }
            else{   //만약 stk[ptr]이 더 크면
                printf("%d ",stk[ptr].num);
            }
        }
        else if(stk[ptr].index == i){
            ptr++;
            int ifprint = 0;
            for (int j = ptr; j < stkSize; ++j) {
                if(stk[j].num > arr[i]){
                    ifprint = 1;
                    printf("%d ",stk[j].num);
                    break;
                }
            }
            if(ifprint == 0)
                printf("-1 ");
        }
        else{
            printf("-1 ");
        }
    }
}