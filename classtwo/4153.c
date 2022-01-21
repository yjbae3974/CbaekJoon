//
// Created by 배연준 on 2022/01/21.
//

#include <stdio.h>

int main(){
    int arr[3];
    do{
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
        if(arr[0] == 0 && arr[1]==0 && arr[2]==0){
            break;
        }
        int max = 0;
        for (int i = 0; i < 3; ++i) {
            if(arr[i]>max)
                max = arr[i];
        }
        if(max == arr[0]){
           if(arr[0]*arr[0] == arr[1]*arr[1] + arr[2]*arr[2]){
               printf("right\n");
               continue;
           }
        }
        else if(max == arr[1]){
            if(arr[1]*arr[1] == arr[0]*arr[0] + arr[2]*arr[2]){
                printf("right\n");
                continue;
            }
        }
        else{
            if(arr[2]*arr[2] == arr[1]*arr[1] + arr[0]*arr[0]){
                printf("right\n");
                continue;
            }
        }
        printf("wrong\n");

    }while(1);

}