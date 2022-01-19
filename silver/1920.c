//
// Created by brian on 2022-01-19.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1,num2;
    scanf("%d",&num1);
    int* numbers = calloc(num1,sizeof (int));
    for (int i = 0; i < num1; ++i) {
        scanf("%d",&numbers[i]);
    }
    scanf("%d",&num2);
    int* arr = calloc(num2,sizeof (int));
    for (int i = 0; i < num2; ++i) {
        scanf("%d",&arr[i]);
    }
    //numbers가 대상이고, arr i번째 마다 이 숫자가 numbers안에 존재하는지 판별하면 됨.

}