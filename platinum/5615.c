
#include<stdio.h>

#define ULL unsigned long long int

int primes[3] = {2,7,61};
int longPrimes[7] = {2,3,5,7,11,13,17};
ULL powFast(ULL a, ULL n, ULL mod){
    //모듈러 연산에 의해, 곱해지는 숫자 전부에 나머지 연산을 적용해도 결과는 같으므로, 구하고 싶은 숫자인 a^n % mod값도 오버플로우 없이 할 수 있을 것 같다.
    ULL tmp = 1;
    a %= mod;
    while(n){
        if(n%2==1)
            tmp = (tmp * a ) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return tmp;
}

ULL miller(ULL number, int primeNum){   //주어진 primeNum에 대해 조건을 통과하는지, 통과하면 아마도 소수일거라 생각하고 true 반환, 통과 못하면 합성수이므로 false반환.
    //만약 number가 primeNum으로 나뉘면 합성수이므로 false 반환
    if(number % primeNum == 0)
        return 0;
    ULL k = number - 1;
    while(1){
        ULL tmp = powFast((ULL)primeNum,k,number);   //tmp는 a^num-1 % number
        if(tmp == number - 1)
            return 1;
        if(k%2){ //k가 홀수라면,
            return (tmp == 1 || tmp == number - 1);
        }
        k/=2;
    }
    //그게 아니라면, primeNum의 d제곱을 number로 나눈 나머지가 1이 아니면서, primeNum의 d^ 2^r을 number로 나눈 나머지가 -1이 아니면, 합성수이다.
    //반대로 말하면, number-1 이 primeNum의 d제곱으로 나누어지면, 혹은 number+1이 primeNum의 d*2^r 제곱으로 나누어지면 소수이다.
}
//고속 거듭제곱 방법 시간복잡도는 log n 이다.

int isprime(ULL n){
    if(n<2){
        return 0;
    }
    for(int i=0;i<3;i++){
        if(n==primes[i]){
            return 1;
        }
        if(!miller(n,primes[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    int num;
    ULL maxNum = 4759123141;
    scanf("%d",&num);
    int cnt = 0;    //cnt는 만족하는 정수의 개수
    for (int i = 0; i < num; ++i) {
        ULL tmp;
        scanf("%lld",&tmp);
        if(isprime(tmp*2 + 1)){
            cnt++;
        }

    }
    printf("%d",cnt);
}