//
// Created by 배연준 on 2022/01/10.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int* arr = calloc(n,sizeof (int));
    long long sum = 0;
    int key = 0;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp != 0){
            arr[key] = tmp;
            key++;
        }
        else{
            arr[key] = 0;
            key--;
        }
    }
    for(int i =0;i<key;i++){
        sum += arr[i];
    }
    printf("%lld",sum);
}