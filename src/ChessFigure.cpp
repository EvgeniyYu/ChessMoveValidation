
#include "ChessFigure.h"
#include "PawnMoveValidation.h"
#include "RookMoveValidation.h"
#include "BishopMoveValidation.h"
#include "KnightMoveValidation.h"
#include "QueenMoveValidation.h"
#include "KingMoveValidation.h"


ChessFigure::ChessFigure(const FigureType type, const std::string& current_coord)
{
    switch (type)
    {
        case FigureType::PAWN:
            uptr_figure_move = std::make_unique<PawnMoveValidation>(current_coord);
            break;
        case FigureType::KNIGHT:
            uptr_figure_move = std::make_unique<KnightMoveValidation>(current_coord);
            break;
        case FigureType::QUEEN:
            uptr_figure_move = std::make_unique<QueenMoveValidation>(current_coord);
            break;
        case FigureType::KING:
            uptr_figure_move = std::make_unique<KingMoveValidation>(current_coord);
            break;
        case FigureType::BISHOP:
            uptr_figure_move = std::make_unique<BishopMoveValidation>(current_coord);
            break;
        case FigureType::ROOK:
            uptr_figure_move = std::make_unique<RookMoveValidation>(current_coord);
            break;
        default:
            break;
    }
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(const std::string& next_coord)
{
    if (uptr_figure_move == nullptr)
    {
        throw std::runtime_error("The type of the figure does not exist!");
    }
    return uptr_figure_move->IsValidationPassed(next_coord);
}

