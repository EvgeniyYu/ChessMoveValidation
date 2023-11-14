#include "ChessFigure.h"
#include <iostream>

int main()
{
    ChessFigure figure(FigureType::ROOK, "E2");
    try
    {
        figure.Move("C2");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}