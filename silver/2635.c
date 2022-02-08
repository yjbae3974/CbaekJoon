//
// Created by 배연준 on 2022/02/08.
//

#include <stdio.h>
#include <stdlib.h>

int continueNum(int num, int second){
    int cnt = 1;
    while(num >= second){
        int tmp;
        tmp = second;
        second = num - second;
        num = tmp;
        if(second < 0){
            second = 0 - second;
        }
        cnt++;
    }
    cnt++;
    return cnt;
}
void printNum(int num, int second){
    printf("%d %d ",num,second);
    while(num >= second){
        int tmp;
        tmp = second;
        second = num - second;
        num = tmp;
        if(second > 0){
            printf("%d ",second);
        }
        else{
            printf("%d ", 0 - second);
        }

    }
}
int main(){
    int num;
    scanf("%d",&num);
    int *cnt = calloc(num,sizeof (int));
    int key = 0;
    if(num == 1){
        printf("4\n");
        printNum(num, 1);
        return 0;
    }
    for (int i = 1; i < num; ++i) {
        cnt[i] = continueNum(num, i);
        if(cnt[key] < cnt[i])
            key = i;
    }
    printf("%d\n",cnt[key]);
    printNum(num, key);
}