//
// Created by 배연준 on 2022/01/17.
//
#include <stdio.h>
#define ULL unsigned long long int
int primes[3] = {2,7,61};

ULL powFast(ULL a, ULL n, ULL mod){
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
ULL miller(ULL number, int primeNum){
    if(number % primeNum == 0)
        return 0;
    ULL k = number - 1;
    while(1){
        ULL tmp = powFast((ULL)primeNum,k,number);   //tmp는 a^num-1 % number
        if(tmp == number - 1)
            return 1;
        if(k%2){
            return (tmp == 1 || tmp == number - 1);
        }
        k/=2;
    }

}

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
    int a,b;
    scanf("%d %d",&a,&b);
    for (int i = a; i <= b; ++i) {

        if(isprime(i)){
            printf("%d\n",i);
        }

    }
}
