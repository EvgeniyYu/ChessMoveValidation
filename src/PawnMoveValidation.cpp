#include "PawnMoveValidation.h"

PawnMoveValidation::PawnMoveValidation(const std::string& current_coord)
{
    m_current_coord = current_coord; 
}

/* 
Pawn can move only in vertical direction. So a column should be the same.
We don't consider the case when one pawn eats an enemy's one and moved to another column. 
*/
bool PawnMoveValidation::IsColumnStaysUnchanged(const std::string& next_coord) const
{
    return (next_coord[0] == m_current_coord[0])? true: false;
}

bool PawnMoveValidation::IsForwardMove(const std::string& next_coord) const
{
    return (next_coord[1] > m_current_coord[1])? true: false;
}

/*
We consider the validation only for white figures, black ones are not considered
*/
bool PawnMoveValidation::IsValidMoveSize(const std::string& next_coord) const
{
    const unsigned MOVE_SIZE = 1;
    const char INIT_COORD = '2';
    const char MAX_MOVE_COORD = '4';
    return (next_coord[1] - m_current_coord[1] == MOVE_SIZE || (m_current_coord[1] == INIT_COORD && next_coord[1] == MAX_MOVE_COORD))? true: false;
}

bool PawnMoveValidation::IsValidMove(const std::string& next_coord) const
{
    if (!IsColumnStaysUnchanged(next_coord)) return false;
    if (!IsForwardMove(next_coord)) return false;
    if (!IsValidMoveSize(next_coord)) return false;
    return true;
}