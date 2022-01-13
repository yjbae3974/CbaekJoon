//
// Created by 배연준 on 2022/01/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 120




int main(){
    char word[SIZE];
    while(1){
        fgets(word,SIZE,stdin);
        if(strcmp(word,".\n") == 0)
            return 0;
        word[strlen(word)-2] = '\0';
        for (int i = 0; word[i] != '\0'; ++i) { //대괄호 괄호들만 남기는 과정.
            if(!(word[i] == '('||word[i] == ')' || word[i] == '[' || word[i] == ']')){
                for (int j = i; j < strlen(word); ++j) {
                    word[j] = word[j+1];
                }
                i--;
                word[strlen(word)] = '\0';
            }
        }
        printf("%s\n",word);
        for (int i = 0; word[i] != '\0';) {
            if(word[i] == '('){
                if(word[i+1] == ')'){
                    for (int j = i; j < strlen(word); ++j) {
                        word[j] = word[j+2];
                    }
                    printf("%s",word);
                    i = 0;
                }
                else
                    i++;
            }
            else if(word[i]== '['){
                if(word[i+1] == ']'){
                    for (int j = i; j < strlen(word); ++j) {
                        word[j] = word[j+2];
                    }
                    i = 0;
                }
                else
                    i++;
            }
            else
                i++;
                continue;
        }
        if(strlen(word) == 0){
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}