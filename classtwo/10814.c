//
// Created by brian on 2022-01-22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int age;
    char name[105];

}Person;
typedef struct{
    int age;
    Person persons[100001];
    int cnt;
}Persons;
int main(){
    int num;
    scanf("%d",&num);
    Persons people[200];
    for (int i = 0; i < 200; ++i) {
        people[i].age = i+1;
        people[i].cnt = 0;
    }
//    for (int i = 0; i < num; ++i) {
//        int tmp;
//        scanf("%d",&tmp);
//        scanf("%s",people[tmp].persons[people[i].cnt].name);
//        people[i].cnt++;
//    }
//    for (int i = 0; i < 200; ++i) {
//        if(people[i].cnt != 0){
//            printf("cnt = %d\n",people[i].cnt);
//            for (int j = 0; j < people[i].cnt; ++j) {
//                printf("%s\n",people[i].persons[j].name);
//            }
//
//        }
//
//    }

}