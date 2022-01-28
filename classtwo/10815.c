//
// Created by 배연준 on 2022/01/28.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int one = *(int *)a;
    int two = *(int *)b;

    if(one > two){
        return 1;
    }
    else if (one == two){
        return 0;
    }
    else{
        return -1;
    }
}
int howMany(int* arr, int *key, int sizeOfArr, int start){
  int cnt = 0;
  int pl = start;
  int pr = sizeOfArr - 1;
  int pc;
  while(pl <= pr){
      pc = (pl + pr) / 2;
      if(arr[pc] <= *key){
          pl = pc + 1;
      }
      else{
          pr = pc - 1;
      }
  }
  return pr - start + 1;
}
int binaryS(int* key, int* arr, int size){
    int pl = 0;
    int pr = size - 1;
    int pc;
    while(pl <= pr){
        pc = (pl + pr) / 2;
        if(arr[pc]< *key){
            pl = pc + 1;
        }
        else{
            pr = pc - 1;
        }
    }
    if(arr[pl] == *key){
        return pl;
    }
    else{
        return -1;
    }
}

int main(){
    int cardNum;
    scanf("%d",&cardNum);
    int* cards = calloc(cardNum, sizeof(int));
    for (int i = 0; i < cardNum; ++i) {
        scanf("%d",&cards[i]);
    }
    qsort(cards, cardNum, sizeof(int),compare);
    int num;
    scanf("%d",&num);
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d",&tmp);
        int bin = binaryS(&tmp, cards, cardNum);
        if(bin != -1){
            printf("%d ", howMany(cards, &tmp, cardNum , bin));
        }
        else{
            printf("0 ");
        }
    }
}