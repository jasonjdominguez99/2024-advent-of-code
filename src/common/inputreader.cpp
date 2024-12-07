#include "inputreader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace
{
    std::string getInputPath(const std::string& day, bool test, const std::optional<int>& part = std::nullopt)
    {
        std::string filename = test ? "test_input" : "input";
        return std::string(INPUT_DIR) + "/" + day + "/" + filename + (part.has_value() ? std::to_string(part.value()) : "") + ".txt";
    }
}

std::vector<std::string> InputReader::readLines(const std::string& day, bool test)
{
    std::vector<std::string> lines;
    std::ifstream            file(getInputPath(day, test));
    std::string              line;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::string InputReader::readFile(const std::string& day, bool test, const std::optional<int>& part)
{
    std::ifstream     file(getInputPath(day, test, part));
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
