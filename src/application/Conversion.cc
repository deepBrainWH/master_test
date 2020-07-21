#include "Conversion.h"

int main(int len, char** argv){
    SqStack S;
    InitStack(S);
    int N, element;
    PrintLine
    scanf("%d", &N);
    while (N){
        Push(S, N%8);
        N = N / 8;
    }
    while (!StackEmpty(S)){
        Pop(S, element);
        printf("%d", element);
    }
    printf("\n");
    DestroyStack(S);
    return 0;
}
