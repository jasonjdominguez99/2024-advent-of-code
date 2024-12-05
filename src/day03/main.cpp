#include "inputreader.hpp"
#include "part1.hpp"
#include "part2.hpp"

#include <iostream>

int main()
{
    std::cout << "Advent of Code 2024 - Day 03" << std::endl;
    std::cout << "---------TEST INPUT---------" << std::endl;

    const bool  isTest = true;
    std::string part1TestInput = InputReader::readFile("day03", isTest);
    std::cout << "Part 1: " << day03::part1::solve(part1TestInput) << std::endl;

    std::string part2TestInput = InputReader::readFile("day03", isTest, 2);
    std::cout << "Part 2: " << day03::part2::solve(part2TestInput) << std::endl;

    std::cout << "---------REAL INPUT---------" << std::endl;

    std::string input = InputReader::readFile("day03");

    std::cout << "Part 1: " << day03::part1::solve(input) << std::endl;
    std::cout << "Part 2: " << day03::part2::solve(input) << std::endl;

    return 0;
}
