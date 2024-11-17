/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define S 10
#define inf 2e9
int max(int a,int b){
    return a>b ? a:b;
}
int min(int a,int b){
    return a<b ? a:b;
}
typedef struct{
    int a;
    int b;
}pair;
pair seg[(1<<S)];
void updateseg(int idx,int val,int f){
}