#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Utils
{
    inline std::vector<int> splitToInts(const std::string& str, const int maxNumEntries)
    {
        std::vector<int> result;
        result.reserve(maxNumEntries);
        std::stringstream ss(str);
        std::string       item;

        while (std::getline(ss, item, ','))
        {
            result.push_back(std::stoi(item));
        }

        return result;
    }

    inline std::unordered_map<int, std::unordered_set<int>> parseRules(const std::vector<std::string>& inputRules)
    {
        std::unordered_map<int, std::unordered_set<int>> rules;
        for (const auto& line : inputRules)
        {
            const size_t separator = line.find('|');
            const int    rule = std::stoi(line.substr(0, separator));
            const int    value = std::stoi(line.substr(separator + 1));
            rules[rule].insert(value);
        }

        return rules;
    }

    inline bool isCorrectOrder(const std::vector<int>& values, const std::unordered_map<int, std::unordered_set<int>>& rules)
    {
        std::unordered_set<int> visited;
        for (const int value : values)
        {
            visited.insert(value);

            if (rules.find(value) != rules.end())
            {
                for (const int rule : rules.at(value))
                {
                    if (visited.find(rule) != visited.end())
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}
