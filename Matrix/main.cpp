#include "Data/data.hpp"
#include <algorithm>
#include <cmath>

int main ()
{
    auto&& data = ReadBook ();
    /*
    data.w2 = w2.txt
    data.w3 = w3.txt
    and so on...

    Everything is a matrix - vector is too = matrix <n * 1>

    multiplication as usual *
    sub and add works too using - and +

    COMPILING: g++ main.cpp Data/data.cpp -std=c++2a
    */
    auto tmp = (data.w2 * data.x);
    auto z2 = tmp + data.b2;
    std::cout << data.b2 << z2 << std::endl;
    matrix::Matrix<> a2(z2.getLines(), z2.getColumns());

    //std::transform(z2.begin(), z2.end(), a2.begin(), [](double elem) -> double { return (1.0 / (1.0 + std::exp(-1 * elem)));});
    //std::cout << "a2: " << a2 << std::endl;
    //std::cout << data.w3 * data.b2; //example of printing multiplications of matrixes
}
