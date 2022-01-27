//
// Created by brian on 2022-01-22.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    int age;
    char name[105];
    int index;
}Person;
int compare(const void *a, const void *b)
{
    Person one = *(Person *)a;
    Person two = *(Person *)b;
    if(one.age> two.age){
        return 1;
    }
    else if(one.age == two.age && one.index > two.index){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    Person *arr = calloc(num,sizeof(Person));
    for (int i = 0; i < num; ++i) {
        scanf("%d %s",&arr[i].age, arr[i].name);
        arr[i].index = i;
    }
    qsort(arr,num,sizeof(Person),compare);
    for (int i = 0; i < num; ++i) {
        printf("%d %s\n",arr[i].age, arr[i].name);
    }


}