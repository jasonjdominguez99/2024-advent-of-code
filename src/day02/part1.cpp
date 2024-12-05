#include "part1.hpp"
#include "utils.hpp"

int day02::part1::solve(const std::vector<std::string>& input)
{
    int numSafe = 0;

    for (const auto& line : input)
    {
        std::vector<int> levels = Utils::parseLine(line);

        if (levels.size() < 2)
        {
            continue;
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

        if (safe)
        {
            ++numSafe;
        }
    }

    return numSafe;
}
