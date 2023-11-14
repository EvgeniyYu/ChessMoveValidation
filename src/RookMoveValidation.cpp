#include "RookMoveValidation.h"

RookMoveValidation::RookMoveValidation(const std::string& current_coord)
{
    m_current_coord = current_coord; 
}

bool RookMoveValidation::IsOneLineMove(const std::string& next_coord) const
{
    return ((next_coord[0] != m_current_coord[0]) && (next_coord[1] != m_current_coord[1]))? false: true;
}

bool RookMoveValidation::IsCoordinateStaysUnchanged(const std::string& next_coord) const
{
    return (next_coord[0] == m_current_coord[0] && next_coord[1] == m_current_coord[1])? false: true;
}

bool RookMoveValidation::IsValidMove(const std::string& next_coord) const
{
    if (!IsOneLineMove(next_coord)) return false;
    if (!IsCoordinateStaysUnchanged(next_coord)) return false;
    return true;
}