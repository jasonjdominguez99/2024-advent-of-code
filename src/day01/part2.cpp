#include "part2.hpp"

#include <unordered_map>

int day01::part2::solve(const std::vector<int>& leftList, const std::vector<int>& rightList)
{
    std::unordered_map<int, int> rightListOccurances;
    rightListOccurances.reserve(rightList.size());
    for (const auto rightNumber : rightList)
    {
        rightListOccurances[rightNumber]++;
    }

    int similarityScore = 0;

    for (const auto leftNumber : leftList)
    {
        similarityScore += leftNumber * rightListOccurances[leftNumber];
    }

    return similarityScore;
}
