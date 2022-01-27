#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int ptr;
    int *stk;
}IntStack;


int Initialize(IntStack *s, int max){
    s->ptr = 0;
    if((s->stk = calloc(max,sizeof (int))) == NULL){
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
int IsEmpty(IntStack *s){
    if(s->ptr <= 0){
        return 1;
    }
    else
        return 0;
}
int Peek(IntStack *s){
    if(s->ptr <= 0){
        return -1;
    }
    return s->stk[s->ptr - 1];
}

int main(){
    int num;
    scanf("%d",&num);
    IntStack seq;
    int* stk = calloc(num,sizeof (int));
    int* ans = calloc(num, sizeof(int));
    Initialize(&seq, num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &stk[i]);
    }
    int garbage;
    for (int i = num - 1; i >=0 ; i--) {
        while(Peek(&seq) <= stk[i] && !IsEmpty(&seq)){   //스택 맨 위 값이 더 작거나 스택이 비지 않았을 경우에 반복.
            Pop(&seq, &garbage);
        }
        if(IsEmpty(&seq)){  //만약 스택이 비었으면
            ans[i] = -1;
            Push(&seq,stk[i]);
        }
        else{
            ans[i] = Peek(&seq);
            Push(&seq, stk[i]);
        }
    }
    for (int i = 0; i < num; ++i) {
        printf("%d ",ans[i]);
    }
}