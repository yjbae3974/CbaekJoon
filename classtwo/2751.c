#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void MergeSort(int *base, int n);

int main(void)
{

    int num;
    scanf("%d",&num);
    int* arr = calloc(num,sizeof (int));
    for (int i = 0; i < num; ++i) {
        scanf("%d",&arr[i]);
    }
    MergeSort(arr, num);
    for (int i = 0; i < num; ++i) {
        printf("%d\n",arr[i]);
    }
}

void MergeSort(int *base, int n)
{
    int ahalf = n / 2; //배열의 앞쪽 개수
    int bhalf = n - ahalf; //배열의 뒤쪽 개수
    int ai = 0, bi = ahalf;
    int i = 0;
    int *tbase = 0;
    if (n <= 1)//배열의 크기가 1보다 작거나 같을 때
    {
        return;
    }
    MergeSort(base, ahalf);//앞쪽 배열 재귀호출로 정렬
    MergeSort(base + ahalf, bhalf);//뒤쪽 배열 재귀호출로 정렬
    tbase = (int *)malloc(sizeof(int)*n);//배열 크기의 임시 공간을 할당
    memcpy(tbase, base, sizeof(int)*n);//임시 공간에 배열 메모리 복사
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



