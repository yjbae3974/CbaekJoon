//
// Created by 배연준 on 2022/01/25.
//

#ifndef ___IntStack
#define ___IntStack

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
int Peek(const IntStack *s, int *x){
    if(s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr - 1];    //ptr은 현재 꼭대기를 가리키고 있고 배열은 거기서 1 뺀 값이 가장 위이므로 1을 뺌.
    return 0;
}
void Clear(IntStack *s){
    s->ptr = 0;
}
int Capacity(const IntStack *s){
    return s->max;
}
int Size(const IntStack *s){
    return s->ptr;
}
int isEmpty(const IntStack *s){
    return s->ptr <= 0; //포인터가 0이면 1반환 아니면 0반환
}
int isFull(const IntStack *s){
    return s->ptr >= s->max;    //포인터가 맥스거나 더 크면 1 반환 아니면 0 반환
}
int Search(const IntStack *s, int x){
    for (int j = s->ptr - 1; j >= 0 ; --j) {
        if(s->stk[j] == x)
            return j;
    }
    return -1;
}
void Print(const IntStack *s){
    for (int i = 0; i < s->ptr; ++i) {
        printf("%d\n",s->stk[i]);
    }
}

void Terminate(IntStack *s){
    if(s->stk != NULL){
        free(s->stk);
    }
    s->max = s->ptr = 0;
}

#endif //DATASTRUCTURE_INTSTACK_H
