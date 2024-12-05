#include "part1.hpp"
#include "utils.hpp"

int day02::part1::solve(const std::vector<std::string>& input)
{
    int numSafe = 0;

    for (const auto& line : input)
    {
        std::vector<int> levels = Utils::parseLine(line);

        if (Utils::areLevelsSafe(levels))
        {
            ++numSafe;
        }
    }

    return numSafe;
}
