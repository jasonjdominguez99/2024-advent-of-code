#include "part2.hpp"
#include "utils.hpp"

int day02::part2::solve(const std::vector<std::string>& input)
{
    int numSafe = 0;

    for (const auto& line : input)
    {
        std::vector<int> levels = Utils::parseLine(line);

        bool safe = Utils::areLevelsSafe(levels);

        size_t levelToRemoveIndex = 0;
        while (!safe && levelToRemoveIndex < levels.size())
        {
            std::vector<int> levelsCopy = levels;
            levelsCopy.erase(levelsCopy.begin() + levelToRemoveIndex);

            safe = Utils::areLevelsSafe(levelsCopy);
            ++levelToRemoveIndex;
        }

        if (safe)
        {
            ++numSafe;
        }
    }

    return numSafe;
}
