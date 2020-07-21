//
// Created by wangheng on 8/27/19.
//

#include "arithmetic_expression.h"

int main(int len, char **argc) {
    char exp[100], res[100], stack[100];
    printf("Typing the arithmetic expression: ");
    scanf("%s", exp);
    int stack_top = -1;
    int res_top = -1;
    int len_exp = strlen(exp);
    for (int i = 0; i < len_exp; i++) {
        if (not_op(exp[i])) {
            res[++res_top] = exp[i];
        } else if (stack_top == -1) {
            stack[++stack_top] = exp[i];
        } else {
            while (icp(exp[i] < isp(stack[stack_top]) && stack_top >= 0)) {
                res[++res_top] = stack[stack_top--];
            }
            if(exp[i] != ')') {
                stack[++stack_top] = exp[i];
            }else{
                continue;
            }
        }
    }
    return 0;
}

int isp(char a) {
    switch (a) {
        case '*':
            return 5;
        case '/':
            return 5;
        case '+':
            return 3;
        case '-':
            return 3;
        case '(':
            return 1;
        case ')':
            return 6;
        default:
            exit(-1);
    }
    return 0;
}

int icp(char a) {
    switch (a) {
        case '*':
            return 4;
        case '/':
            return 4;
        case '+':
            return 2;
        case '-':
            return 2;
        case '(':
            return 6;
        case ')':
            return 1;
        default:
            exit(-1);
    }
    return 0;
}

int not_op(char a) {
    if (a != '*' && a != '/' && a != '+' && a != '-')
        return 1;
    return 0;
}
