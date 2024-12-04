#include "part1.hpp"
#include "utils.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

int64_t day01::part1::solve(const std::vector<std::string>& input, const size_t numDigits)
{
    const auto [leftList, rightList] = Utils::getSortedListsFromInput(input, numDigits);

    int64_t sum = 0;

    for (size_t i = 0; i < leftList.size(); ++i)
    {
        const int leftNumber = leftList[i];
        const int rightNumber = rightList[i];

        sum += std::abs(leftNumber - rightNumber);
    }

    return sum;
}
