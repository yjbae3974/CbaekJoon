//
// Created by 배연준 on 2022/01/27.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
}Coordinate;
int compare(void const *a, void const *b){
    Coordinate x = *(Coordinate *)a;
    Coordinate y =*(Coordinate *)b;
    if(x.x>y.x){
        return 1;
    }
    else if(x.x == y.x && x.y > y.y){
        return 1;
    }
    else if(x.x == y.x && x.y == y.y)
        return 0;
    else
        return -1;
}

int main(){
    int num;
    scanf("%d",&num);
    Coordinate *arr = calloc(num,sizeof(Coordinate));
    for (int i = 0; i < num; ++i) {
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }

    qsort(arr, num,sizeof(Coordinate),compare);
    for (int i = 0; i < num; ++i) {
        printf("%d %d\n",arr[i].x, arr[i].y);
    }
}