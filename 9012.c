//
// Created by 배연준 on 2022/01/10.
//

#include <stdio.h>
#include <stdlib.h>
int main(){
    int length;
    scanf("%d",&length);
    char **p = calloc(length,sizeof(char*));
    for (int i = 0; i < length; ++i) {
        p[i] = (char*) calloc(50,sizeof(char));
    }
    for (int i = 0; i < length; ++i) {
        scanf("%s",p[i]);
    }
    for(int i =0;i<length;i++){
        int tmp = 0;
        int isBroken = 0;
        int j =0;
        while(p[i][j] == '(' || p[i][j] == ')'){
            if(p[i][j] == '('){
                tmp++;
            }
            else if(p[i][j] == ')'){
                tmp--;
            }
            if(tmp <0){
                printf("NO\n");
                isBroken = 1;
                break;
            }
            j++;
        }
        if(isBroken == 0 && tmp == 0){
            printf("YES\n");
        }
        else if(isBroken == 0 && tmp != 0){
            printf("NO\n");
        }
    }
}