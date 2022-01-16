#include <stdio.h>
#include <math.h>

int main(){
    int num;
    long long tot = 0;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        int tmp = num / i;
        tot += tmp * i;
    }
    printf("%lld",tot);
}