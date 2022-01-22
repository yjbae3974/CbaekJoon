//
// Created by brian on 2022-01-22.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d",&num);
    for (int i = 0; i < num; ++i) {
        int H,W,N;
        scanf("%d %d %d",&H,&W,&N);
        //첫번째는 층수, 두번째는 방최대 거리, 세번째는 몇번째인지. 층수는 n & h. 방거리는 n/h + 1.
        if( H == 1){
            printf("%d%02d\n",1, N);
        }
        else{
            if(N % H == 0){
                printf("%d%02d\n",H, N / H);
            }
            else{
                printf("%d%02d\n",N % H, N / H + 1);
            }

        }

    }
}