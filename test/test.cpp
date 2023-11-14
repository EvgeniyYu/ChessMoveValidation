#include "gtest/gtest.h"
#include "ChessFigure.h"

class ChessMoveValidationTest : public ::testing::TestWithParam<
                          std::tuple<FigureType, std::string, std::string, bool>> {};

TEST_P(ChessMoveValidationTest, WhenMoveIsDone_CheckIfMoveIsCorrect) {
	auto param = GetParam();
	auto figure_type = std::get<0>(param); 
	auto current_coord = std::get<1>(param);
	auto next_coord = std::get<2>(param);
	auto expected_result = std::get<3>(param);
	std::unique_ptr<ChessFigure> figure = std::make_unique<ChessFigure>(figure_type, current_coord);
	bool actual_result = figure->Move(next_coord);
	EXPECT_TRUE(actual_result == expected_result);
}

/* 
TO DO: Change the type of m_current_coord and next_coord from std::string to structure. 
For example:
struct Coord
{
    char column;
    unsigned row;
};
*/
/* We check whether next_coord is valid or not */
/* We don't check whether current_coord is valid or not */
INSTANTIATE_TEST_SUITE_P(
    ChessMoveValidation, ChessMoveValidationTest,
    ::testing::Values(
        std::make_tuple(FigureType::ROOK, "E2", "C2", true),
		std::make_tuple(FigureType::ROOK, "E2", "C5", false),
		std::make_tuple(FigureType::KNIGHT, "B1", "C3", true),
		std::make_tuple(FigureType::KNIGHT, "B1", "C5", false),
		std::make_tuple(FigureType::BISHOP, "C1", "E3", true),
		std::make_tuple(FigureType::BISHOP, "C1", "C3", false),
		std::make_tuple(FigureType::PAWN, "E2", "E3", true),
		std::make_tuple(FigureType::PAWN, "E2", "E4", true),
		std::make_tuple(FigureType::PAWN, "E4", "E5", true),
		std::make_tuple(FigureType::PAWN, "E2", "C5", false),
		std::make_tuple(FigureType::KING, "E1", "E2", true),
		std::make_tuple(FigureType::KING, "E1", "E8", false),
		std::make_tuple(FigureType::QUEEN, "D1", "D8", true),
		std::make_tuple(FigureType::QUEEN, "D1", "H5", true),
		std::make_tuple(FigureType::QUEEN, "D1", "E3", false),
		std::make_tuple(FigureType::QUEEN, "C5", "V5", false),
		std::make_tuple(FigureType::QUEEN, "C2", "C9", false)
	));
