//
// Created by 배연준 on 2022/01/14.
//

#include <stdio.h>

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int num = 1;
        for (int i = 1;; ++i) {
            num %=n;
            if(num == 0){
                printf("%d\n",i);
                break;
            }
            else{
                num = num * 10 + 1;
            }
        }

    }

}

