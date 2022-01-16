//
// Created by brian on 2022-01-15.
//

#include <stdio.h>
#include <stdlib.h>



int findRevise(char** arr, int rowStart, int colStart, char chess1[8][8], char chess2[8][8]){
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = rowStart; i < rowStart + 8; ++i) {
        for (int j = colStart; j < colStart + 8; ++j) {
//            printf("row: %d, col: %d, arr: %c, chess1: %c, chess2: %c\n",i - rowStart,j - colStart, arr[i][j],chess1[i - rowStart][j - colStart],chess2[i - rowStart][j - colStart]);
            if(arr[i][j] != chess1[i - rowStart][j - colStart])
                cnt1++;
            if(arr[i][j] != chess2[i - rowStart][j - colStart])
                cnt2++;
        }
    }
    if(cnt1 > cnt2)
        return cnt2;
    else
        return cnt1;
}

int main(){
    int row, col;
    scanf("%d %d",&row,&col);
    char** arr = calloc(row,sizeof(char*));
    for (int i = 0; i < row; ++i) {
        arr[i] = (char*) calloc(col,sizeof (char));
    }
    for (int i = 0; i < row; ++i) {
        scanf("%s", arr[i]);
    }
    char chess1[8][8];
    char chess2[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((i+j)%2 ==0){
                chess1[i][j] = 'B';
                chess2[i][j] = 'W';
            }
            else{
                chess1[i][j] = 'W';
                chess2[i][j] = 'B';
            }

        }
    }

    int min = 64;
    for (int i = 0; i <= row - 8; ++i) {
        for (int j = 0; j <= col - 8; ++j) {
            int tmp = findRevise(arr, i, j, chess1, chess2);
            if(tmp <= min)
                min = tmp;
        }
    }
    printf("%d",min);
}