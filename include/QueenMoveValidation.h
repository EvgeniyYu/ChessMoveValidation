#ifndef QUEEN_MOVE_VALIDATION_H
#define QUEEN_MOVE_VALIDATION_H

#include "FigureMoveValidation.h"

class QueenMoveValidation: public FigureMoveValidation
{
public:
    QueenMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
};

#endif
