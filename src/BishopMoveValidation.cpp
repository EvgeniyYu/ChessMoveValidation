#include "BishopMoveValidation.h"

BishopMoveValidation::BishopMoveValidation(const std::string& current_coord)
{
    m_current_coord = current_coord; 
}

/* TO DO: refactor this method, i.e. split on several private methods*/
bool BishopMoveValidation::IsValidMove(const std::string& next_coord) const
{
    if (!(abs(next_coord[0] - m_current_coord[0]) == abs(next_coord[1] - m_current_coord[1])))
        return false;
    else
        return true;
}