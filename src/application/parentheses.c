//
// Created by wangheng on 8/27/19.
//
#include "parentheses.h"

void parentheses_app() {
    char exp[100], str[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    int top = -1, n = strlen(exp);
    char temp;
    for (int i = 0; i < n; i++) {
        if ((exp[i] == ']' || exp[i] == '}' || exp[i] == ')') && top == -1)
            break;
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            top++;
            str[i] = exp[i];
        } else {
            temp = str[top];
            top --;
            if ((temp == '(' && exp[i] == ')') || (temp == '[' && exp[i] == ']')
                || (temp == '{' && exp[i] == '}'))
                continue;
            else
                break;
        }
    }
    if(top == -1)
        printf("Balanced!\n");
    else
        printf("Unbalanced!\n");
}
int main(){
    parentheses_app();
    return 0;
}
