#ifndef ROOK_MOVE_VALIDATION_H
#define ROOK_MOVE_VALIDATION_H

#include "FigureMoveValidation.h"

class RookMoveValidation: public FigureMoveValidation
{
public:
    RookMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
    bool IsCoordinateStaysUnchanged(const std::string& next_coord) const;
    bool IsOneLineMove(const std::string& next_coord) const;
};

#endif