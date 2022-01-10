//
// Created by 배연준 on 2022/01/10.
//
#include <stdio.h>

int ifPrime(int num){
    int able = 0;
    if(num == 1){
        return 0;
    }
    else{
        for(int i = 2;i<num;i++){
            if(num % i == 0){
                return 0;
            }
            else{
                continue;
            }
        }
        return num;
    }
}

int main(){
    int min, max;
    scanf("%d %d",&min,&max);
    int tot = 0;
    int first = 1;
    int minPrime;
    for(int i = min;i<=max;i++){
        if(ifPrime(i)){
            tot += i;
            if(first){
                minPrime = i;
                first = 0;
            }
        }

    }
    if(tot == 0){
        printf("-1");
        return 0;
    }
    printf("%d\n%d",tot,minPrime);
}

