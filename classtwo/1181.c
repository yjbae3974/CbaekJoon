//
// Created by brian on 2022-01-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strArr{
    char str[51];
    int len;
}strArr;

int main(){
    int num;
    strArr* words;
    scanf("%d",&num);
    words = calloc(num,sizeof(strArr));
    
    for (int i = 0; i < num; ++i) {
        scanf("%s",words[i].str);
        words[i].len = strlen(words[i].str);
    }
    for (int i = 0; i < num; ++i) {
        for (int j = i + 1; j < num; ++j) {
            if(words[i].len>words[j].len){
                char tmp[51];
                strcpy(tmp, words[i].str);
                strcpy(words[i].str,words[j].str);
                strcpy(words[j].str,tmp);
                int length;
                length = words[i].len;
                words[i].len = words[j].len;
                words[j].len = length;
            }
        }
    }
    for (int i = 0; i < num - 1; ++i) {
        if(words[i].len == words[i + 1].len) {
            int j = 1;
            while(words[i].len == words[i + j].len){
                if(strcmp(words[i].str,words[i+j].str) > 0){
                    char tmp[51];
                    strcpy(tmp, words[i].str);
                    strcpy(words[i].str,words[i+j].str);
                    strcpy(words[i+j].str,tmp);
                }
                j++;
            }

        }
    }
    for (int i = 0; i < num; ++i) {
        if(i != 0){
            if(strcmp(words[i].str,words[i-1].str) == 0)
                continue;
        }
        printf("%s\n",words[i].str);
    }
}