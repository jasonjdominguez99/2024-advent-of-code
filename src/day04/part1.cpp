#include "part1.hpp"

namespace
{
    constexpr std::string_view SearchWord = "XMAS";

    struct Position
    {
        size_t row;
        size_t col;
    };

    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        UpLeft,
        UpRight,
        DownLeft,
        DownRight
    };

    constexpr std::array<Direction, 8> Directions = {
        Direction::Up,
        Direction::Down,
        Direction::Left,
        Direction::Right,
        Direction::UpLeft,
        Direction::UpRight,
        Direction::DownLeft,
        Direction::DownRight
    };

    constexpr std::pair<int, int> getIncrement(const Direction direction)
    {
        switch (direction)
        {
        case Direction::Up:
            return std::make_pair(-1, 0);
        case Direction::Down:
            return std::make_pair(1, 0);
        case Direction::Left:
            return std::make_pair(0, -1);
        case Direction::Right:
            return std::make_pair(0, 1);
        case Direction::UpLeft:
            return std::make_pair(-1, -1);
        case Direction::UpRight:
            return std::make_pair(-1, 1);
        case Direction::DownLeft:
            return std::make_pair(1, -1);
        case Direction::DownRight:
            return std::make_pair(1, 1);
        default:
            return std::make_pair(0, 0);
        }
    }

    bool findWord(const std::vector<std::string>& input, const Position startPosition, const Direction direction)
    {
        const size_t startRow = startPosition.row;
        const size_t startCol = startPosition.col;

        const auto [rowIncrement, colIncrement] = getIncrement(direction);

        if (startRow - (SearchWord.size() - 1) * rowIncrement < 0)
        {
            return false;
        }

        if (startCol - (SearchWord.size() - 1) * colIncrement < 0)
        {
            return false;
        }

        if (startRow + (SearchWord.size() - 1) * rowIncrement >= input.size())
        {
            return false;
        }

        if (startCol + (SearchWord.size() - 1) * colIncrement >= input[startRow].size())
        {
            return false;
        }

        for (size_t i = 0; i < SearchWord.size(); ++i)
        {
            if (input[startRow + i * rowIncrement][startCol + i * colIncrement] != SearchWord[i])
            {
                return false;
            }
        }

        return true;
    }
}

int day04::part1::solve(const std::vector<std::string>& input)
{
    int numWordsFound = 0;

    for (size_t row = 0; row < input.size(); ++row)
    {
        for (size_t col = 0; col < input[row].size(); ++col)
        {
            if (input[row][col] != SearchWord[0])
            {
                continue;
            }

            for (const auto direction : Directions)
            {
                numWordsFound += findWord(input, { row, col }, direction) ? 1 : 0;
            }
        }
    }

    return numWordsFound;
}
