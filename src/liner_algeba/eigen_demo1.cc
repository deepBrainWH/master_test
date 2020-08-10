//
// Created by wangheng on 7/26/20.
//
#include <iostream>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;


int main(){
    Matrix<float, 2,3> matrix_23;
    Matrix<float, 3,1> vec3d;
    Matrix<float, 3,3> matrix_33 = Matrix<float,3,3>::Zero();
    //如果不确定矩阵大小，使用动态大小的矩阵
    Matrix<float,Dynamic,Dynamic> matrix_dynamic;
    //更显单的定义动态矩阵的方法
    MatrixXd matrix_x;

    matrix_23 << 1,2,3,4,5,6;
    cout<<matrix_23<<endl;
    return 0;
}
