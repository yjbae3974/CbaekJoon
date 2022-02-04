//
// Created by 배연준 on 2022/02/04.
//

#include<stdio.h>

int sum(int n){
    int sum = n;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int findNum(int n){
    int cnt = 0;
    while(n > 0){
        n /= 10;
        cnt++;
    }
    return cnt;
}


int main(){
    int num;
    scanf("%d",&num);
        for (int i = num - 9 * findNum(num); i < num; ++i) {
            if(sum(i) == num){
                printf("%d",i);
                return 0;
            }
            else
                continue;
        }
        printf("0");

}