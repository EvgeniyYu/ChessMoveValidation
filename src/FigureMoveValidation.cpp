#include "FigureMoveValidation.h"

bool FigureMoveValidation::IsValidCoordinate(const std::string& next_coord) const
{
    const char FIRST_COLUMN_SYMBOL = 'A';
    const char LAST_COLUMN_SYMBOL = 'H';
    const char FIRST_ROW_SYMBOL = '1';
    const char LAST_ROW_SYMBOL = '8';
    if (next_coord[0] < FIRST_COLUMN_SYMBOL || next_coord[0] > LAST_COLUMN_SYMBOL) return false; 
    if (next_coord[1] < FIRST_ROW_SYMBOL || next_coord[1] > LAST_ROW_SYMBOL) return false;
    return true;
}

bool FigureMoveValidation::IsValidationPassed(const std::string& next_coord) const
{
    if (!IsValidCoordinate(next_coord)) return false;
    if (!IsValidMove(next_coord)) return false;
    return true;
}
