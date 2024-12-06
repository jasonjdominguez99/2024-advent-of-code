#include "part1.hpp"
#include "utils.hpp"

namespace
{
    constexpr std::string_view SearchWord = "XMAS";

    bool findWord(const std::vector<std::string>& input, const Utils::Position startPosition, const Utils::Direction direction)
    {
        const size_t startRow = startPosition.row;
        const size_t startCol = startPosition.col;

        const auto [rowIncrement, colIncrement] = Utils::getIncrement(direction);

        if (startRow - (SearchWord.size() - 1) * rowIncrement < 0)
        {
            return false;
        }

        if (startCol - (SearchWord.size() - 1) * colIncrement < 0)
        {
            return false;
        }

        if (startRow + (SearchWord.size() - 1) * rowIncrement >= input.size())
        {
            return false;
        }

        if (startCol + (SearchWord.size() - 1) * colIncrement >= input[startRow].size())
        {
            return false;
        }

        for (size_t i = 0; i < SearchWord.size(); ++i)
        {
            if (input[startRow + i * rowIncrement][startCol + i * colIncrement] != SearchWord[i])
            {
                return false;
            }
        }

        return true;
    }
}

int day04::part1::solve(const std::vector<std::string>& input)
{
    int numWordsFound = 0;

    for (size_t row = 0; row < input.size(); ++row)
    {
        for (size_t col = 0; col < input[row].size(); ++col)
        {
            if (input[row][col] != SearchWord[0])
            {
                continue;
            }

            for (const auto direction : Utils::Directions)
            {
                numWordsFound += findWord(input, { row, col }, direction) ? 1 : 0;
            }
        }
    }

    return numWordsFound;
}
