//
// Created by brian on 2022-01-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void MergeSort(long long int* base, int n);

int main(){
    int num1,num2;
    scanf("%d",&num1);
    long long int* numbers = calloc(num1,sizeof (long long int));
    for (int i = 0; i < num1; ++i) {
        scanf("%lld",&numbers[i]);
    }
    MergeSort(numbers, num1);
//    for (int i = 0; i < num1; ++i) {
//        printf("%d\n",numbers[i]);
//    }
    scanf("%d",&num2);
    for (int i = 0; i < num2; ++i) {
        long long int tmp;
        int pl = 0;
        int pr = num1 - 1;
        int ifDone = 0;
        scanf("%lld",&tmp);
        while(pl <= pr){
            int pc = (pl + pr) / 2;
            if(numbers[pc] == tmp){
                ifDone = 1;
                printf("1\n");
                break;
            }
            if(numbers[pc] > tmp){
                pr = pc - 1;
            }
            else
                pl = pc + 1;
        }
        if(ifDone == 0)
            printf("0\n");
    }
    //numbers가 대상이고, arr i번째 마다 이 숫자가 numbers안에 존재하는지 판별하면 됨.

}

void MergeSort(long long int *base, int n)
{
    int ahalf = n / 2; //배열의 앞쪽 개수
    int bhalf = n - ahalf; //배열의 뒤쪽 개수
    int ai = 0, bi = ahalf;
    int i = 0;
    long long int *tbase = 0;
    if (n <= 1)//배열의 크기가 1보다 작거나 같을 때
    {
        return;
    }
    MergeSort(base, ahalf);//앞쪽 배열 재귀호출로 정렬
    MergeSort(base + ahalf, bhalf);//뒤쪽 배열 재귀호출로 정렬
    tbase = (long long int *)malloc(sizeof(long long int)*n);//배열 크기의 임시 공간을 할당
    memcpy(tbase, base, sizeof(long long int)*n);//임시 공간에 배열 메모리 복사
    while ((ai<ahalf) && (bi<n))
    {
        if (tbase[ai] <= tbase[bi])//뒤쪽이 크거나 같을 때
        {
            base[i] = tbase[ai];//앞쪽 배열의 원소를 대입
            ai++;
        }
        else
        {
            base[i] = tbase[bi];//뒤쪽 배열의 원소를 대입
            bi++;
        }
        i++;
    }
    while (ai<ahalf)//앞쪽 배열의 남은 것들을 대입
    {
        base[i] = tbase[ai];
        i++;
        ai++;
    }
    while (bi<n)//뒤쪽 배열의 남은 것들을 대입
    {
        base[i] = tbase[bi];
        i++;
        bi++;
    }
    free(tbase);//임시 버퍼에 할당한 메모리 해제
}