//
// Created by 배연준 on 2022/01/19.
//

#include <stdio.h>
#include <stdlib.h>
long long int findLength(int* arr,int length, int num){
    long long int cnt = 0;
    for (int i = 0; i < num; ++i) {
        if(arr[i]>length){
            cnt += (long long int)arr[i] - (long long int)length;
        }
    }
    return cnt;
}

int main(){
    long long int numOfTree, numOfLength;
    scanf("%lld %lld",&numOfTree,&numOfLength);
    int* trees = calloc(numOfTree,sizeof(int));
    long long int height = 0;
    for (int i = 0; i < numOfTree; ++i) {
        scanf("%d",&trees[i]);
        if(trees[i] > height)
            height = trees[i];
    }
    long long int max = height, min = 0, mid = 0;
    while(min <= max){
        mid = (max + min) / 2;
        long long int tmp = findLength(trees,mid, numOfTree);
        if(tmp == numOfLength){
            min = mid;
            break;
        }
        if(tmp>numOfLength){
            min = mid + 1;
        }
        else
            max = mid - 1;
    }
    if(max<min){
        printf("%d",max);
    }
    else{
        printf("%d",min);
    }

}