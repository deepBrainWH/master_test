#ifndef LINEEDIT_CC
#define LINEEDIT_CC
#include "LineEdit.h"

Status Print(SElementType e){
    printf("%c", e);
    return OK;
}

int main(){
    SqStack S;
    char ch, e = 0;
    int e_ = (int)e;
    InitStack(S);
    ch = getchar();
    PrintLine
    while (ch != '^'){
        while (ch != EOF && ch != '\n'){
            switch (ch){
                case '#': Pop(S, e_);
                    break;
                case '@': ClearStack(S);
                    break;
                default:
                    Push(S, ch);
            }
            ch = getchar();
        }
        StackTraverse(S, Print);
        ClearStack(S);
        ch = getchar();
    }
    printf("Close application.\n");
    DestroyStack(S);
    return 0;
}

#endif