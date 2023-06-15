/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Tower
*/

#include "Tower.hpp"
#include "King.hpp"

EChess::Tower::Tower(Color color, int x, int y) : APiece(color, x, y)
{
    if (_color == ::White)
        _path = "/home/fmarcolo/Documents/EpiChess2/Tower.png";
    else
        _path = "/home/fmarcolo/Documents/EpiChess2/BTower.png";
}


EChess::Tower::~Tower()
{
}

std::vector<std::tuple<int, int>> EChess::Tower::getMovements(Chessboard* chessboard)
{
    std::vector<std::tuple<int, int>> res;
    bool king = false;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        std::size_t newX = _x + dx;
        std::size_t newY = _y + dy;

        while (newX < chessboard->getMap().size() && newY < chessboard->getMap().at(newX).size()) {
            if (chessboard->getMap().at(newX).at(newY) == nullptr)
                res.push_back(std::make_tuple(newX, newY));
            else {
                if (chessboard->getMap().at(newX).at(newY)->getColor() != _color) {
                    if (chessboard->getMap().at(newX).at(newY)->getType() == ::King) {
                        king = true;
                        break;
                    }
                    res.push_back(std::make_tuple(newX, newY));
                }
                break;
            }
            newX += dx;
            newY += dy;
        }
    }
    return res;
}
