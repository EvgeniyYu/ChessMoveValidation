#ifndef FIGURE_MOVE_VALIDATION_H
#define FIGURE_MOVE_VALIDATION_H

#include <string>

class FigureMoveValidation
{
    bool IsValidCoordinate(const std::string& next_coord) const;
public:
    bool IsValidationPassed(const std::string& next_coord) const;
    virtual ~FigureMoveValidation() = default;
protected:
    virtual bool IsValidMove(const std::string& next_coord) const = 0;

    std::string m_current_coord;
};

#endif