#ifndef PAWL_MOVE_VALIDATION_H
#define PAWL_MOVE_VALIDATION_H

#include "FigureMoveValidation.h"

class PawnMoveValidation: public FigureMoveValidation
{
public:
    PawnMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
    bool IsColumnStaysUnchanged(const std::string& next_coord) const;
    bool IsForwardMove(const std::string& next_coord) const;
    bool IsValidMoveSize(const std::string& next_coord) const;
};

#endif