#pragma once

#include <string>
#include <vector>

namespace InputReader
{
    std::vector<std::string> readLines(const std::string& day, bool test = false);
    std::string              readFile(const std::string& day, bool test = false);
}
