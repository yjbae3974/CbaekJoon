//
// Created by brian on 2022-01-13.
//

#include <stdio.h>
#define MAX 1000010
long long arr[MAX];
int main(){

    for(int i= 1;i<=MAX;i++){   //이러면 시간복잡도가 nlogn이다.
        for (int j = i; j <= MAX; j+=i) {
            arr[j] += i;
        }
        arr[i] += arr[i-1];
    }
    int num;
    scanf("%d",&num);

}
