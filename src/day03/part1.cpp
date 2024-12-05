#include "part1.hpp"

#include <regex>

namespace
{
    const std::regex InstructionPattern { R"(mul\((\d{1,3}),(\d{1,3})\))" };
}

int day03::part1::solve(const std::string& input)
{
    int result = 0;

    std::smatch                 match;
    std::string::const_iterator searchStart(input.begin());

    while (std::regex_search(searchStart, input.end(), match, InstructionPattern))
    {
        const int a = std::stoi(match[1].str());
        const int b = std::stoi(match[2].str());

        result += a * b;

        searchStart = match.suffix().first;
    }

    return result;
}
