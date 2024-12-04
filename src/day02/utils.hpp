#pragma once

#include <string>
#include <vector>

namespace Utils
{
    struct InputLists
    {
        std::vector<int> leftList;
        std::vector<int> rightList;
    };

    InputLists getSortedListsFromInput(const std::vector<std::string>& input, const size_t numDigits);
}
