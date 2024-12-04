#include "part1.hpp"

#include <sstream>

namespace
{
    const int MaxDiff = 3;

    bool isSafe(const int diff, const bool increasing)
    {
        const int absDiff = std::abs(diff);

        if (diff == 0 || absDiff > MaxDiff)
        {
            return false;
        }

        if (increasing && diff < 0)
        {
            return false;
        }

        if (!increasing && diff > 0)
        {
            return false;
        }

        return true;
    }

    std::vector<int> parseLine(const std::string& line)
    {
        std::vector<int> numbers;
        numbers.reserve(line.size());

        std::stringstream ss(line);
        int               num;
        while (ss >> num)
        {
            numbers.push_back(num);
        }

        return numbers;
    }
}

int day02::part1::solve(const std::vector<std::string>& input)
{
    int numSafe = 0;

    for (const auto& line : input)
    {
        std::vector<int> levels = parseLine(line);

        if (levels.size() < 2)
        {
            continue;
        }

        bool safe = true;
        bool increasing = levels[1] - levels[0] > 0;
        for (size_t i = 1; i < levels.size(); ++i)
        {
            const int diff = levels[i] - levels[i - 1];
            if (!isSafe(diff, increasing))
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
