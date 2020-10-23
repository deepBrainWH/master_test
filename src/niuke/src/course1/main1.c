//
// Created by wangheng on 1/17/20.
//
#include <stdio.h>
#define MAX_N 100

int main(int argc, char* argv[]){
    int n;//n组数
    printf("Input:\n");
    scanf("%d", &n);
    int a, b;//每组两个数
    int result[MAX_N];
    for(int i = 0;i<n;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        result[i] = a*b;
    }
    printf("Output:\n");
    for(int i = 0;i<n;i++){
        printf("%d\n", result[i]);
    }
    return 0;
}
