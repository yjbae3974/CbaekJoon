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
        return 1;
    }
}

int main(){
    int length;
    scanf("%d",&length);
    int tot = 0;
    for(int i =0;i<length;i++){
        int tmp;
        scanf("%d",&tmp);
        if(ifPrime(tmp)){
            tot++;
        }

    }
    printf("%d",tot);
}

