#include "inputreader.hpp"
#include "part1.hpp"

#include <iostream>

int main()
{
    std::cout << "Advent of Code 2024 - Day 03" << std::endl;
    std::cout << "---------TEST INPUT---------" << std::endl;

    const bool  isTest = true;
    std::string testInput = InputReader::readFile("day03", isTest);

    std::cout << "Part 1: " << day03::part1::solve(testInput) << std::endl;

    std::cout << "---------REAL INPUT---------" << std::endl;

    std::string input = InputReader::readFile("day03");

    std::cout << "Part 1: " << day03::part1::solve(input) << std::endl;

    return 0;
}
