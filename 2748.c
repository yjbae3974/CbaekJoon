//
// Created by brian on 2022-01-09.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a = 0;
    int b = 1;
    long long num;
    scanf("%lld",&num);
    long long *p = calloc(num + 1,sizeof(long long));
    p[0] = 0;
    p[1] = 1;
    int tmp;
    for(int i=2;i<=num;i++){
        p[i] = p[i-1] + p[i-2];
    }

    printf("%lld",p[num]);
}
