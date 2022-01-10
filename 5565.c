//
// Created by brian on 2022-01-09.
//
#include <stdio.h>

int main(){
    int tot = 0;
    scanf("%d",&tot);
    int tmp;
    for(int i =0;i<9;i++){
        scanf("%d",&tmp);
        tot -= tmp;
    }
    printf("%d",tot);
}
