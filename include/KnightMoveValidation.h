#ifndef KNIGHT_MOVE_VALIDATION_H
#define KNIGHT_MOVE_VALIDATION_H

#include  "FigureMoveValidation.h"

class KnightMoveValidation: public FigureMoveValidation
{
public:
    KnightMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
};

#endif