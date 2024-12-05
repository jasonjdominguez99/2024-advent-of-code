#include "part2.hpp"
#include "utils.hpp"

namespace
{
    bool areLevelsSafe(const std::vector<int>& levels)
    {
        if (levels.size() < 2)
        {
            return false;
        }

        bool safe = true;
        bool increasing = levels[1] - levels[0] > 0;
        for (size_t i = 1; i < levels.size(); ++i)
        {
            const int diff = levels[i] - levels[i - 1];
            if (!Utils::isSafe(diff, increasing))
            {
                safe = false;
                break;
            }
        }

        return safe;
    }
}

int day02::part2::solve(const std::vector<std::string>& input)
{
    int numSafe = 0;

    for (const auto& line : input)
    {
        std::vector<int> levels = Utils::parseLine(line);

        bool safe = areLevelsSafe(levels);

        size_t levelToRemoveIndex = 0;
        while (!safe && levelToRemoveIndex < levels.size())
        {
            std::vector<int> levelsCopy = levels;
            levelsCopy.erase(levelsCopy.begin() + levelToRemoveIndex);

            safe = areLevelsSafe(levelsCopy);
            ++levelToRemoveIndex;
        }

        if (safe)
        {
            ++numSafe;
        }
    }

    return numSafe;
}
