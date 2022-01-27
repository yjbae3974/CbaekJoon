//
// Created by 배연준 on 2022/01/25.
//

#ifndef DATASTRUCTURE_INTQUEUE_H
#define DATASTRUCTURE_INTQUEUE_H
/**
 * 링버퍼
 * 배열 요소를 앞쪽으로 옮기지 않음. 배열의 처음과 끝이 연결되어있음.
 */
typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
}IntQueue;

int Initialize(IntQueue *q, int max){
    q->num = q->front = q->rear = 0;    //첨에는 개수, 앞, 뒤 모두 0;
    if((q->que = calloc(max,sizeof(int))) == NULL){
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}
int Enque(IntQueue *q, int x){
    if(q->num >=q->max){    //개수랑 맥스가 같으면 이미 다 찬거니 -1을 반환.
        return -1;
    }
    q->num++;       //무언가를 넣는거니 num값을 추가함.
    q->que[q->rear++] = x;  //rear은 배열의 뒤인데, 그 공간에다가 넣는가보다. 그럼 front는 맨 처음 넣기 시작한 그 곳.
    if(q->rear == q->max){   //리어가 배열의 맨 끝에 도달하면
        q->rear = 0;    //rear이 배열의 맥스값과 같으면, 다시 첫번째로 보낸다.
    }
}
int Deque(IntQueue *q, int* x){
    if(q->num <= 0){
        return -1;
    }
    else{
        q->num--;
        *x = q->que[q->front++];
        if(q->front == q->max){ //만약 프론트가 맥스에 도달하면 프론트를 0으로 놔둠.
            q->front = 0;
        }
        return 0;
    }

}
int Front(const IntQueue *q, int* x){
    if(q->num <= 0){
        return -1;
    }
    else{
        *x = q->que[q->front];
    }
    return *x;
}
int Back(const IntQueue *q, int* x){
    if(q->num <= 0){
        return -1;
    }
    else{
        *x = q->que[q->rear];
    }
    return *x
}
int isEmpty(const IntQueue *q){
    return q->num <= 0;
}
int isFull(const IntQueue *q){
    return q->num >= q->max;
}
int Size(IntQueue *q){
    return q->num;
}
int Capacity(IntQueue *q){
    return q->max;
}
int Front(IntQueue *q){

}
void Print(IntQueue *q){
    for (int i = 0; i < q->num; ++i) {
        printf("%d ",q->que[(i+q->front) % q->max]);
    }
    printf("\n");
}
void Terminate(IntQueue *q){
    if(q->que != NULL){
        free(q->que);
        q->max = q->num = q->front = q->rear = 0;
    }
}

#endif //DATASTRUCTURE_INTQUEUE_H
