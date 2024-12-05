#include "part2.hpp"

#include <regex>

namespace
{
    const std::regex InstructionPattern { R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))" };
}

int day03::part2::solve(const std::string& input)
{
    int result = 0;

    std::smatch                 match;
    std::string::const_iterator searchStart(input.begin());

    bool doInstruction = true;
    while (std::regex_search(searchStart, input.end(), match, InstructionPattern))
    {
        const std::string matchText = match[0].str();

        if (matchText == "do()")
        {
            doInstruction = true;
        }
        else if (matchText == "don't()")
        {
            doInstruction = false;
        }
        else if (doInstruction)
        {
            const int a = std::stoi(match[1].str());
            const int b = std::stoi(match[2].str());

            result += a * b;
        }

        searchStart = match.suffix().first;
    }

    return result;
}
