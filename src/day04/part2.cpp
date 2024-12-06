#include "part2.hpp"
#include "utils.hpp"

namespace
{
    constexpr std::string_view SearchWord = "MAS";
    constexpr size_t           SearchWordCenter = SearchWord.size() / 2;

    bool findIntersectingWordsFromCenter(const std::vector<std::string>& input, const Utils::Position center)
    {
        Utils::Position forwardDiagonalStart = { center.row + SearchWordCenter, center.col - SearchWordCenter };
        Utils::Position reverseForwardDiagonalStart = { center.row - SearchWordCenter, center.col + SearchWordCenter };

        bool forwardDiagonalWordFound = Utils::findWord(input, forwardDiagonalStart, Utils::Direction::UpRight, SearchWord) ||
                                        Utils::findWord(input, reverseForwardDiagonalStart, Utils::Direction::DownLeft, SearchWord);

        Utils::Position backwardDiagonalStart = { center.row + SearchWordCenter, center.col + SearchWordCenter };
        Utils::Position reverseBackwardDiagonalStart = { center.row - SearchWordCenter, center.col - SearchWordCenter };

        bool backwardDiagonalWordFound = Utils::findWord(input, backwardDiagonalStart, Utils::Direction::UpLeft, SearchWord) ||
                                         Utils::findWord(input, reverseBackwardDiagonalStart, Utils::Direction::DownRight, SearchWord);

        return forwardDiagonalWordFound && backwardDiagonalWordFound;
    }
}

int day04::part2::solve(const std::vector<std::string>& input)
{
    int numIntersectingWordsFound = 0;

    for (size_t row = SearchWordCenter; row < input.size() - SearchWordCenter; ++row)
    {
        for (size_t col = SearchWordCenter; col < input[row].size() - SearchWordCenter; ++col)
        {
            if (input[row][col] != SearchWord[SearchWordCenter])
            {
                continue;
            }

            numIntersectingWordsFound += findIntersectingWordsFromCenter(input, { row, col }) ? 1 : 0;
        }
    }

    return numIntersectingWordsFound;
}
