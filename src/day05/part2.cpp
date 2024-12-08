#include "part2.hpp"
#include "utils.hpp"

#include <unordered_map>
#include <unordered_set>

int day05::part2::solve(const std::vector<std::string>& inputRules, const std::vector<std::string>& inputUpdates)
{
    // TODO: improve using list instead of vector & forward interating through the list
    // TODO: improve by using more abstctions & better naming
    const std::unordered_map<int, std::unordered_set<int>> rules = Utils::parseRules(inputRules);

    int total = 0;

    for (const auto& line : inputUpdates)
    {
        std::vector<int> values = Utils::splitToInts(line, Utils::MaxNumEntriesPerUpdateLine);

        if (!Utils::isCorrectOrder(values, rules))
        {
            std::unordered_set<int> checked;
            checked.reserve(values.size());
            for (int i = static_cast<int>(values.size()) - 1; i > 0; --i)
            {
                const int value = values[i];

                if (checked.find(value) != checked.end())
                {
                    continue;
                }

                std::optional<int> indexToMoveTo;
                if (rules.find(value) != rules.end())
                {
                    const std::unordered_set<int>& ruleValues = rules.at(value);
                    for (int j = i - 1; j >= 0; --j)
                    {
                        const int prevValue = values[j];
                        if (ruleValues.find(prevValue) != ruleValues.end())
                        {
                            indexToMoveTo = j;
                        }
                    }
                }

                if (indexToMoveTo.has_value())
                {
                    values.erase(values.begin() + i);
                    values.insert(values.begin() + indexToMoveTo.value(), value);
                    ++i;
                }

                checked.insert(value);
            }

            const int middleValue = values[values.size() / 2];
            total += middleValue;
        }
    }

    return total;
}
