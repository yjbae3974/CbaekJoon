//
// Created by 배연준 on 2022/01/12.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char word[101];
    char* dynamic;
    int num;
    scanf("%d",&num);
    int tot=0;
    for (int i = 0; i < num; ++i) { //전에꺼를 저장하고, 만약 전에께 지금이랑 같으면 넘어가는데 만약 다르면 배열에서 확인해서 이미 그게 있음 나가리.
        scanf("%s",word);
        dynamic = calloc(strlen(word)+1,sizeof(char));
        strcpy(dynamic,word);
        int alphabet[26] ={0};
        int length = strlen(dynamic);
        int former = dynamic[0] - 97;
        int ifgroup = 1;
        alphabet[former] = 1;
        for (int i = 0; i < length; ++i) {
            if(former == dynamic[i] - 97){
                continue;
            }
            int tmp = dynamic[i] - 97;
            if(alphabet[tmp] == 1){
                ifgroup = 0;
                break;
            }
            alphabet[tmp] = 1;
            former = dynamic[i] - 97;
        }
        if(ifgroup)
            tot++;
    }
    printf("%d",tot);



}