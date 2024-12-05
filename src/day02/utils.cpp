#include "utils.hpp"

#include <sstream>

namespace
{
    const int MaxDiff = 3;
}

bool Utils::isSafe(const int diff, const bool increasing)
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

std::vector<int> Utils::parseLine(const std::string& line)
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
