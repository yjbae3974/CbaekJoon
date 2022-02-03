#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int max;
    int num;
    int front;
    int back;
    int* que;
}Deque;

int Initialize(Deque *q, int num){
    if(num <= 0){
        q->max = 0;
        return -1;
    }
    q->max = num;
    q->num = q->front = q->back = 0;
    q->que = calloc(num,sizeof(int));
    return 1;
}
int IsEmpty(Deque *q){
    if(q->num <=0){
        return 1;
    }
    return 0;
}
int Push(Deque *q, int direction, int num){
    //direction이 1이면 back, -1이면 front
    if(direction == 1){  //1일때, back에다가 푸시함.
        if(IsEmpty(q)){
            q->que[q->back] = num;
            q->num++;
            return 1;
        }
        else{
            if(q->back>0)
                q->back--;
            else
                q->back = q->max - 1;
            q->que[q->back] = num;
            q->num++;
            return 1;
        }
    }
    else{ //-1일 때, front에다가 푸시함.
        if(IsEmpty(q)){
            q->que[q->front] = num;
            q->num++;
            return 1;
        }
        else{
            if(q->front< q->max - 1)
                q->front++;
            else
                q->front = 0;
            q->que[q->front] = num;
            q->num++;
            return 1;
        }
    }
}

int Pop(Deque *q, int direction, int *x){
    //direction이 1이면 back, -1이면 front
    if(IsEmpty(q)){
        *x = -1;
        return -1;
    }
    if(direction == 1){  //back이므로, back에 있는거 하나를 지우고 back을 올림.
        *x = q->que[q->back++];
        q->num--;
        if(q->back >= q->max)
            q->back = 0;
    }
    else{
        *x = q->que[q->front--];
        q->num--;
        if(q->front < 0)
            q->front = q->max -1;
    }
    if(q->num == 0){
        q->back = q->front;
    }
    return 1;
}

int main(){
    int num;
    scanf("%d",&num);
    Deque que;
    Initialize(&que, num);
    int garbage;
    for (int i = 0; i < num; ++i) {
        char string[100];
        scanf("%s",string);
        if(strcmp(string, "push_front") == 0){
            int tmp;
            scanf("%d",&tmp);
            Push(&que, -1, tmp);
        }
        else if(strcmp(string, "push_back") == 0){
            int tmp;
            scanf("%d",&tmp);
            Push(&que, 1, tmp);
        }
        else if(strcmp(string, "pop_front") == 0){
            Pop(&que, -1,&garbage);
            printf("%d\n",garbage);
        }
        else if(strcmp(string, "pop_back") == 0){
            Pop(&que, 1,&garbage);
            printf("%d\n",garbage);
        }
        else if(strcmp(string, "front") == 0){
            if(que.num > 0){
                printf("%d\n",que.que[que.front]);
            }
            else{
                printf("-1\n");
            }
        }
        else if(strcmp(string, "back") == 0){
            if(que.num > 0){
                printf("%d\n",que.que[que.back]);
            }
            else{
                printf("-1\n");
            }
        }
        else if(strcmp(string, "size") == 0){
            printf("%d\n",que.num);
        }
        else if(strcmp(string, "empty") ==0){
            printf("%d\n", IsEmpty(&que));
        }
    }
}