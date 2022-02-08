#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int factorial(int num){
    if(num > 0){
        return num * factorial(num - 1) % 10007;
    }
    else{
        return 1;
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d", factorial(n)/ (factorial(k)* factorial(n - k)));

}