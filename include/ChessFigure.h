#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include "FigureMoveValidation.h"
#include <memory>

enum class FigureType
{
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN,
    KING,
    QUEEN
};

class ChessFigure
{
public:
    ChessFigure(const FigureType type, const std::string& current_coord);  
    virtual ~ChessFigure();
    bool Move(const std::string& next_coord);	
private:
    std::unique_ptr<FigureMoveValidation> uptr_figure_move;
};

#endif