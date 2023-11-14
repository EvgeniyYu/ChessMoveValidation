#include "KnightMoveValidation.h"

KnightMoveValidation::KnightMoveValidation(const std::string& current_coord)
{
    m_current_coord = current_coord; 
}

/* TO DO: refactor this method, i.e. split on several private methods*/
bool KnightMoveValidation::IsValidMove(const std::string& next_coord) const
{
    const auto dx = abs(next_coord[0] - m_current_coord[0]);
    const auto dy = abs(next_coord[1] - m_current_coord[1]);
    if (!(abs(next_coord[0] - m_current_coord[0]) == 1 && abs(next_coord[1] - m_current_coord[1]) == 2 || abs(next_coord[0] - m_current_coord[0]) == 2 && abs(next_coord[1] - m_current_coord[1]) == 1))
        return false;
    else
        return true;
}