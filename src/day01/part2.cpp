#include "part2.hpp"
#include "utils.hpp"

#include <unordered_map>

int64_t day01::part2::solve(const std::vector<std::string>& input, const size_t numDigits)
{
    const auto [leftList, rightList] = Utils::getSortedListsFromInput(input, numDigits);

    std::unordered_map<int, int> rightListOccurances;
    rightListOccurances.reserve(rightList.size());
    for (const auto rightNumber : rightList)
    {
        rightListOccurances[rightNumber]++;
    }

    int64_t similarityScore = 0;

    for (const auto leftNumber : leftList)
    {
        similarityScore += leftNumber * rightListOccurances[leftNumber];
    }

    return similarityScore;
}
