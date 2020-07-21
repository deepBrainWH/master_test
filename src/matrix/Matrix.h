//
// Created by wangheng on 9/11/19.
//

#ifndef Matrix_H
#define Matrix_H

#include <iostream>
using namespace std;

int main(int len, char **argv);

class Matrix {
public:
    void tri_brand_matrix_compress_store() {
        int a[8][8] = {
                {1, 2, 0, 0, 0, 0, 0, 0},
                {3, 4, 5, 0, 0, 0, 0, 0},
                {0, 4, 5, 8, 0, 0, 0, 0},
                {0, 0, 5, 8, 8, 0, 0, 0},
                {0, 0, 0, 8, 3, 5, 0, 0},
                {0, 0, 0, 0, 1, 4, 3, 0},
                {0, 0, 0, 0, 0, 7, 9, 1},
                {0, 0, 0, 0, 0, 0, 8, 2},
        };
        int size = 22;
        int* b = new int[size+1];
        int* p = b;
        (*p) = a[0][0];p++;
        (*p) = a[0][1];p++;
        for(int i = 1;i<7;i++){
            for(int j = i-1;j<i+2;j++){
                (*p) = a[i][j];p++;
            }
        }
        (*p) = a[7][6];p++;
        (*p) = a[7][7];

        int i = 5;
        int j = 4;
        cout<<b[2*i+j-3]<<endl;
    }
};


#endif //MASTER_TEST_MATRIX_H
