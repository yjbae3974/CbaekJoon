//
// Created by 배연준 on 2022/01/10.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Alphabet{
    char en;
    int num;
};

int main(){
    char word[55];
    scanf("%s",word);
    int length = strlen(word);
    int alpha = 0;
    int alphabet[26] = {0};
    int alphaNum = 0;
    //먼저 서로 다른 알파벳 개수 구하고, 그 수만큼 구조체 배열 만들고, 구조체 배열 정렬
    for(int i=0;i<length;i++){
        alphabet[word[i]-65]++;
    }
    for (int i = 0; i < 26; ++i) {
        if(alphabet[i] != 0){
            alphaNum++;
        }
    }
    //알파넘: 서로 다른 알파벳 개수. 알파벳: 0~25까지 각 위치에 맞게 개수가 각각 쓰여있음.
    struct Alphabet *p = calloc(alphaNum,sizeof (struct Alphabet));
    int key = 0;
    for (int i = 0; i < alphaNum; ++i) {
        while(1){
            if(alphabet[key] != 0){
                p[i].num = alphabet[key];
                p[i].en = key + 65;
                key++;
                break;
            }
            key++;
            if(key > 26)
                break;
        }
    }
    char* answer = calloc(length,sizeof(char));
    for (int i = 0; i < length; ++i) {
        answer[i] = 'A';
    }
    int cnt = length / 2;
    int position = 0;
    if(length % 2 == 0){
        for (int i = 0; i < alphaNum; ++i) {
            if(p[i].num % 2 == 1){
                printf("I'm Sorry Hansoo");
                return 0;
            }
        }
        for (int i = 0; i < alphaNum;i++) { //여기서는 각 p의 개수를 보고, 2로 나눈 값 만큼 배열에 대입.
            int tmp = p[i].num / 2;
            for (int j = 0; j < tmp; ++j) {
                answer[position] = p[i].en;
                answer[length-1-position] = p[i].en;
                position++;
            }

        }
    }
    else{   //단어 길이가 홀수일 때는 홀수인게 1개 이상이면 안됨.
        int findOdd = 0;
        int position = 0;
        for (int i = 0; i < alphaNum; ++i) {
            if(p[i].num % 2 == 1){
                if(findOdd == 0){
                    answer[cnt] = p[i].en;
                    p[i].num--;
                    findOdd = 1;
                }
                else{
                    printf("I'm Sorry Hansoo");
                    return 0;
                }
            }
        }
        for (int i = 0; i < alphaNum;i++) { //여기서는 각 p의 개수를 보고, 2로 나눈 값 만큼 배열에 대입.
            int tmp = p[i].num / 2;
            for (int j = 0; j < tmp; ++j) {
                answer[position] = p[i].en;
                answer[length-1-position] = p[i].en;
                position++;
            }

        }
    }
    printf("%s %d",answer,strlen(answer));
}
