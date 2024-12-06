#include "part1.hpp"
#include "utils.hpp"

namespace
{
    constexpr std::string_view SearchWord = "XMAS";
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
                numWordsFound += Utils::findWord(input, { row, col }, direction, SearchWord) ? 1 : 0;
            }
        }
    }

    return numWordsFound;
}
