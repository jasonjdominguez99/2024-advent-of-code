#include "part1.hpp"

#include <cmath>

int day01::part1::solve(const std::vector<int>& leftList, const std::vector<int>& rightList)
{
    int sum = 0;

    for (size_t i = 0; i < leftList.size(); ++i)
    {
        const int leftNumber = leftList[i];
        const int rightNumber = rightList[i];

        sum += std::abs(leftNumber - rightNumber);
    }

    return sum;
}
