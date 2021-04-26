#include "Data/data.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
size_t max_index(matrix::Matrix<>& matr);

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
    auto z2 = (data.w2 * data.x) + data.b2;
    //std::cout << data.b2 << z2 << std::endl;
    matrix::Matrix<> a2(z2.getLines(), z2.getColumns());
    std::transform(z2.begin(), z2.end(), a2.begin(), [](double elem) -> double { return (1.0 / (1.0 + std::exp(-1 * elem)));});
    //std::cout << "a2: " << a2 << std::endl;
    auto z3 = data.w3*a2 + data.b3;
    matrix::Matrix<> a3(z3.getLines(), z3.getColumns());
    std::transform(z3.begin(), z3.end(), a3.begin(), [](double elem) -> double { return (1.0 / (1.0 + std::exp(-1 * elem)));});

    auto result = max_index(a3);
    //std::cout << "a3: " << a3 << std::endl;
    //std::cout << "result: " << result << std::endl;
    //std::cout << data.w3 * data.b2; //example of printing multiplications of matrixes
    std::ofstream fout("result.txt"); //
    fout << result; // запись строки в файл
    fout.close(); // закрываем файл
}

size_t max_index(matrix::Matrix<>& matr)
{
    double max_elem = -1;
    size_t max_index = -1, index = 0;
    for (auto&& elem : matr)
    {
        if (elem > max_elem){
            max_elem = elem;
            max_index = index;
        }
        index++;
    }
    return max_index;
}
