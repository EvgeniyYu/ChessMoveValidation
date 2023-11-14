#ifndef BISHOP_MOVE_VALIDATION_H
#define BISHOP_MOVE_VALIDATION_H

#include "FigureMoveValidation.h"

class BishopMoveValidation: public FigureMoveValidation
{
public:
    BishopMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
};

#endif