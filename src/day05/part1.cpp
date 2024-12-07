#include "part1.hpp"
#include "utils.hpp"

#include <unordered_map>
#include <unordered_set>

namespace
{
    constexpr int MaxNumEntriesPerUpdateLine = 23;
}

int day05::part1::solve(const std::vector<std::string>& inputRules, const std::vector<std::string>& inputUpdates)
{
    std::unordered_map<int, std::unordered_set<int>> rules = Utils::parseRules(inputRules);

    int total = 0;

    for (const auto& line : inputUpdates)
    {
        const std::vector<int> values = Utils::splitToInts(line, MaxNumEntriesPerUpdateLine);

        if (Utils::isCorrectOrder(values, rules))
        {
            const int middleValue = values[values.size() / 2];
            total += middleValue;
        }
    }

    return total;
}
