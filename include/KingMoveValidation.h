#ifndef KING_MOVE_VALIDATION_H
#define KING_MOVE_VALIDATION_H

#include "FigureMoveValidation.h"

class KingMoveValidation: public FigureMoveValidation
{
public:
    KingMoveValidation(const std::string& current_coord);
private:
    bool IsValidMove(const std::string& next_coord) const override;
    bool IsHorizontalOneCellMove(const std::string& next_coord) const;
    bool IsVerticalOneCellMove(const std::string& next_coord) const;
};

#endif