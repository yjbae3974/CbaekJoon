//
// Created by 배연준 on 2022/02/09.
//

#include <stdio.h>
#include <stdlib.h>

int log(int num){
    if(num > 1){
        return log(num / 3) + 1;
    }
    else
        return 0;
}
void Locate(int** arr, int garo, int sero, int log){
    if(log == 3){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                arr[garo+i][sero+j] = 1;
                if(i == 1 && j == 1){
                    arr[garo+i][sero+j] = 0;
                }
            }
        }
    }
    else{
        Locate(arr, garo, sero,log / 3);
        Locate(arr, garo + log / 3, sero, log / 3);
        Locate(arr, garo + 2 * log / 3, sero, log / 3);
        Locate(arr, garo, sero + log / 3, log / 3);
        Locate(arr, garo + 2 * log / 3, sero + log / 3, log / 3);
        Locate(arr, garo, sero + 2 * log / 3, log / 3);
        Locate(arr, garo + log / 3, sero + 2 * log / 3, log / 3);
        Locate(arr, garo + 2 * log / 3, sero + 2 * log / 3, log / 3);
    }
}

int main(){
    int num;
    scanf("%d",&num);
    int no = log(num);
    int** arr = calloc(num, sizeof(int*));
    for (int i = 0; i < num; ++i) {
        arr[i] = calloc(num,sizeof(int));
    }
    Locate(arr, 0, 0, num);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%c", arr[i][j]?'*':' ');
        }
        printf("\n");
    }
}