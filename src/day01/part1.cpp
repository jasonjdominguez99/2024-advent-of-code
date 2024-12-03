#include "part1.hpp"

#include <cmath>
#include <iostream>

namespace
{
    const size_t InputDataSpacing = 3;
}

int64_t day01::part1::solve(const std::vector<std::string>& input, const size_t numDigits)
{
    std::vector<int> leftList;
    leftList.reserve(input.size());

    std::vector<int> rightList;
    rightList.reserve(input.size());

    for (const auto& line : input)
    {
        const std::string leftNumberText = line.substr(0, numDigits);
        const int         leftNumber = std::stoi(leftNumberText);
        leftList.push_back(leftNumber);

        const size_t      startIndex = numDigits - 1 + InputDataSpacing;
        const std::string rightNumberText = line.substr(startIndex);
        const int         rightNumber = std::stoi(rightNumberText);
        rightList.push_back(rightNumber);
    }

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int64_t sum = 0;

    for (size_t i = 0; i < leftList.size(); ++i)
    {
        const int leftNumber = leftList[i];
        const int rightNumber = rightList[i];

        sum += std::abs(leftNumber - rightNumber);
    }

    return sum;
}
