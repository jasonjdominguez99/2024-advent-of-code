#include "utils.hpp"

namespace
{
    const size_t InputDataSpacing = 3;
}

Utils::InputLists Utils::getSortedListsFromInput(const std::vector<std::string>& input, const size_t numDigits)
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

    return { leftList, rightList };
}
