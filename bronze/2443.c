//
// Created by 배연준 on 2022/01/24.
//

#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        for (int j = 0; j < (num-i)*2 - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }
}