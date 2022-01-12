//
// Created by 배연준 on 2022/01/12.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char word[101];
    char* dynamic;
    gets(word);
    dynamic = calloc(strlen(word)+1,sizeof(char));
    strcpy(dynamic,word);
    int length = strlen(dynamic);
    printf("%s %d\n",dynamic, strlen(dynamic));
    int alphabet[26] ={0};
    for (int i = 0; i < length; ++i) {
        int tmp = dynamic[i] - 97;
        alphabet[tmp]++;
    }
    for (int i = 0; i < 26; ++i) {
        printf("%d ",alphabet[i]);
    }

}