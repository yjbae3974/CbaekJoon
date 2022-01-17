//
// Created by 배연준 on 2022/01/17.
//
#include <stdio.h>

int main(){
    int posx, posy;
    int maxX, maxY;
    scanf("%d %d %d %d",&posx,&posy,&maxX,&maxY);
    int minX;
    int minY;
    if(posx < maxX - posx)
        minX = posx;
    else
        minX = maxX - posx;
    if(posx < maxY - posy)
        minY = posy;
    else
        minY = maxY - posy;
    if(minX<minY)
        printf("%d",minX);
    else
        printf("%d",minY);

}

