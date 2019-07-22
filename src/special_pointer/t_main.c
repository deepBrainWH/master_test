//
// Created by wangheng on 7/22/19.
//
#include "special_pointer.h"

int main(int argc, char* argv[], char* envp[]){

    printf("The parameters number is: %d\n", argc);
    printf("The program's name is: %s\n", argv[0]);
    printf("Print the environment variables: \n");
    for(int i = 0;envp[i] != NULL;i++){
        printf("%s\n", envp[i]);
    }

    return 0;
}
