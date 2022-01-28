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

int Push(IntStack *s, int x, int y){
    if(s->ptr >= s->max)
    {return -1;}
    s->stk[s->ptr].score = x;
    s->stk[s->ptr].time = y;
    s->ptr++;
    return 0;
}
int Pop(IntStack *s,int *score){
    if(s->ptr <= 0 )
        return -1;
    else{
        s->stk[s->ptr - 1].time--;
        if(s->stk[s->ptr - 1].time == 0){
            *score += s->stk[--s->ptr].score;
        }
        return 1;
    }

}

int main(){
    int num;
    scanf("%d",&num);
    IntStack arr;
    Initialize(&arr,num);
    int score = 0;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d",&tmp);
        if(tmp == 0){
            Pop(&arr, &score);
        }
        else{
            int tmpscore, tmptime;
            scanf("%d %d",&tmpscore, &tmptime);
            Push(&arr,tmpscore,tmptime);
            Pop(&arr,&score);
        }
    }
    printf("%d",score);
}