#include "data.hpp"

static matrix::Matrix<> ReadMatrix (std::ifstream& stream , size_t x , size_t y);
static std::vector<double> ReadMas (std::ifstream& stream , size_t size);

matrix::Matrix<> operator * (const matrix::Matrix<>& lhs , const matrix::Matrix<>& rhs)
{
    auto out (lhs);
    out.multiplication (rhs);
    return out;
}
matrix::Matrix<> operator * (const matrix::Matrix<>& lhs , double num)
{
    auto out(lhs);
    for (auto&& elem : out)
        elem *= num;
    return out;
}
matrix::Matrix<> operator * (double num, const matrix::Matrix<>& rhs)
{
    auto out(rhs);
    for (auto&& elem : out)
        elem *= num;
    return out;
}
matrix::Matrix<> operator + (const matrix::Matrix<>& lhs, const matrix::Matrix<>& rhs)
{
    if (lhs.getColumns() != rhs.getColumns() || lhs.getLines() != rhs.getLines())
        return matrix::Matrix<>(1, 1);

    auto out(rhs);
    for (size_t i = 0; i < lhs.getLines(); ++i)
        for (size_t j = 0; j < lhs.getColumns(); ++j)
            out.at(i, j) += lhs.at(i, j);

    return out;
}

matrixes ReadBook ()
{
    std::array<std::ifstream , 5> files = {
        std::ifstream ("Data/w2.txt"),
        std::ifstream ("Data/w3.txt"),
        std::ifstream ("Data/b2.txt"),
        std::ifstream ("Data/b3.txt"),
        std::ifstream ("Data/x.txt")
    };
    for (auto&& file : files)
        if (!file.is_open ())
        {
            std::cerr << "Can't open file!";
            std::abort ();
        }

    matrixes data;
    data.w2 = ReadMatrix (files[0] , data.w2.getLines () , data.w2.getColumns ());
    data.w3 = ReadMatrix (files[1] , data.w3.getLines () , data.w3.getColumns ());
    data.b2 = ReadMatrix (files[2] , data.b2.getLines () , data.b2.getColumns ());
    data.b3 = ReadMatrix (files[3] , data.b3.getLines () , data.b3.getColumns ());

    for (size_t i = 0; i < 784; ++i)
    {
        char trash = 0;
        files[4] >> data.x.at (i , 0);
        files[4] >> trash;
    }

    for (auto& file : files)
        file.close ();

    return data;
}

//[[...], [...], ...]
matrix::Matrix<> ReadMatrix (std::ifstream& stream , size_t x , size_t y)
{
    matrix::Matrix<> data (x , y);

    char trash = 0;
    stream >> trash; //[
    for (size_t i = 0; i < x; ++i)
    {
        auto&& mas = ReadMas (stream , y);
        std::copy (mas.begin () , mas.end () , &(data.at (i , 0)));
        stream >> trash; //,
    }
    return data;
}

//[num, num, ...] - will be read
std::vector<double> ReadMas (std::ifstream& stream , size_t size)
{
    std::vector<double> out (size);
    char trash = 0;
    stream >> trash;
    for (size_t i = 0; i < size; ++i)
    {
        stream >> out[i];
        stream >> trash;
    }
    return out;
}
