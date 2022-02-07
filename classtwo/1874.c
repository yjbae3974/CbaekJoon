//
// Created by 배연준 on 2022/02/07.
//

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


int main(){
    int num;
    scanf("%d",&num);
    IntStack stk;
    Initialize(&stk, num);
    int* arr = calloc(num, sizeof(int));
    char* plusMinus = calloc(num*2 + 1, sizeof(char));
    for (int i = 0; i < num; ++i) {
        scanf("%d",&arr[i]);
    }
    int key = 0;    //현재 배열에서 몇번째를 보는지
    int index = 1;  //현재 어떤 수를 배열에 넣어야 하는지
    int keyChar = 0;
    int garbage;
    while(key <= num - 1){
        if(stk.stk[stk.ptr] < arr[key]){
            while(stk.stk[stk.ptr - 1] < arr[key]){
                Push(&stk, index);
                index++;
                plusMinus[keyChar] = '+';
                keyChar++;
            }
            Pop(&stk, &garbage);
            plusMinus[keyChar] = '-';
            keyChar++;
            if(garbage == arr[key]) {
                key++;
                continue;
            }
        }
        else if (stk.stk[stk.ptr] == arr[key]){
            Pop(&stk, &garbage);

            if(garbage == arr[key]) {
                plusMinus[keyChar] = '-';
                keyChar++;
                key++;
                continue;
            }
        }
        else{
            Pop(&stk, &garbage);
            if(garbage == arr[key]) {
                plusMinus[keyChar] = '-';
                keyChar++;
                key++;
                continue;
            }
            else{
                printf("NO");
                return 0;
            }
        }
    }
    for (int i = 0; i <= keyChar - 1; ++i) {
        printf("%c\n",plusMinus[i]);
    }
}