#pragma once

#include <string>
#include <vector>

namespace Utils
{
    bool             isSafe(const int diff, const bool increasing);
    std::vector<int> parseLine(const std::string& line);
    bool             areLevelsSafe(const std::vector<int>& levels);
}
