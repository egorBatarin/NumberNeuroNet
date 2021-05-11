#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include <tuple>
#include "matrix/Matrix.h"

struct matrixes
{
    matrixes () : w2 (30 , 784) , w3 (10 , 30) , b2 (30 , 1) , b3 (10 , 1) , x (784 , 1), b22(2 , 1), b33(1, 2) {}
    matrix::Matrix<> w2; //(30, 784)
    matrix::Matrix<> w3;
    matrix::Matrix<> b2;
    matrix::Matrix<> b3;
    matrix::Matrix<> x;
    matrix::Matrix<> b22;
    matrix::Matrix<> b33;
};

//Function to use
matrixes ReadBook ();

matrix::Matrix<> operator * (const matrix::Matrix<>& lhs , const matrix::Matrix<>& rhs);
matrix::Matrix<> operator * (const matrix::Matrix<>& lhs , long double num);
matrix::Matrix<> operator * (long double num, const matrix::Matrix<>& rhs);
