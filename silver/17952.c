//
// Created by 배연준 on 2022/01/27.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int score;
    int time;
}Assignment;

typedef struct{
    int max;
    int ptr;
    Assignment *stk;
}IntStack;

int Initialize(IntStack *s, int max){
    s->ptr = 0;
    if((s->stk = calloc(max,sizeof (Assignment))) == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){
    if(s->ptr >= s->max)
    {return -1;}
    s->stk[s->ptr++] = x;
    return 0;
}
int Pop(IntStack *s, int *x){
    if(s->ptr <= 0 )
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

int main(){
    int num;
    scanf("%d",&num);
    IntStack arr;
    Initialize(&arr,num);
    for (int i = 0; i < ; ++i) {

    }
}