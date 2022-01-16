//
// Created by brian on 2022-01-13.
//

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int length;
    scanf("%d",&length);
    int *prime_number = calloc(length,sizeof (int));
    int *realPrime = calloc(length,sizeof(int));
    for (int i = 0; i < length; i++)
        prime_number[i] = i;			// 각 인덱스 값은 본인 숫자

    for (long long i = 2; i * 2 < length; i++)
    {
        if (prime_number[i] == 0)		// 이미 지워져있으면 수행하지 않음
            continue;

        for (long long w = i, j = i; w * j < length; j++)
            prime_number[w * j] = 0;	// 배수에 있는 값은 0으로 지워줌
    }

    for (int i = 0; i < length; ++i)		// 지워지지 않은 숫자만 출력
        if (prime_number[i] != 0){
            //printf("%d ", prime_number[i]);
            int ch = 1;
        }


}