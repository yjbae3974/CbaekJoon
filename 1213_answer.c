#include <stdio.h>
#include <string.h>
int main()
{
    char name[51] = { 0 }, alphabet[26] = { 0 }, cnt = 0, result[51] = { 0 };
    scanf("%s", name);
    int length = strlen(name);
    for (int i = 0; i < length; i++)
        alphabet[name[i] - 65]++;
    for (int i = 0; i < 26; i++)
        if (alphabet[i] % 2 == 1)
            cnt++;
    if(cnt>=2){
        printf("I'm Sorry Hansoo");
    }
    else{
        int key = 0;
        for (int i = 0; strlen(result) != length;) {
            if(alphabet[key]>=2){
                result[i] = key + 65;
                result[length - 1 - i] = key + 65;
                alphabet[key] -= 2;
                i++;
            }
            else if(alphabet[key] == 1){
                result[length/2] =  key + 65;
                alphabet[key]--;
            }
            else if(alphabet[key] == 0)
                key++;
        }
    }
    printf("%s", result);
    return 0;
}