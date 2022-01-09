//
// Created by brian on 2022-01-09.
// 백준 2609, 최대 공약수와 최대 공배수 출력 문제
#include <stdio.h>

int findNum(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}


int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int left = 1;

       int index = 2;
       while(1){
           if(a % index == 0 && b % index == 0){
               a/=index;
               b/=index;
               left*=index;
               continue;
           }
           if(findNum(a,b) > index){
               index++;
               continue;
           }
           break;
       }
    int min = left;
    int max = left * a * b;
    printf("%d\n%d",min,max);
}

