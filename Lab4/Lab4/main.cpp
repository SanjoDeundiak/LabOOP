#include "Matrix.h"

#include <iostream>

int main()
{
    matrix<int> m(2, 3);

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << std::endl;
    }

    try
    {
        m.at(2, 4);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    m.resizem(3);
    m[2][0] = 7;
    m[2][1] = 8;
    m[2][2] = 9;

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << std::endl;
    }

    m.resizen(4);
    m[0][3] = 10;
    m[1][3] = 11;
    m[2][3] = 12;

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << std::endl;
    }

    std::cin.get();
}