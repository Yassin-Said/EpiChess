/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Queen
*/

#include "Queen.hpp"
#include "King.hpp"
#include "iostream"

EChess::Queen::Queen(Color color, int x, int y) : APiece(color, x, y)
{
    if (_color == ::White)
        _path = "/home/fmarcolo/Documents/EpiChess2/Queen.png";
    else
        _path = "/home/fmarcolo/Documents/EpiChess2/BQueen.png";
}

EChess::Queen::~Queen()
{
}

std::vector<std::tuple<int, int>> EChess::Queen::getMovements(Chessboard* chessboard)
{
    std::vector<std::tuple<int, int>> res;
    std::vector<std::vector<int>> dir = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < 8; i++) {
        int temp_x = _x + dir.at(i).at(0);
        int temp_y = _y + dir.at(i).at(1);
        while (chessboard->inRange(temp_x, temp_y) && !chessboard->getMap().at(temp_x).at(temp_y)) {
            res.push_back(std::make_tuple(temp_x, temp_y));
            temp_x += dir.at(i).at(0);
            temp_y += dir.at(i).at(1);
        }
        if (chessboard->inRange(temp_x, temp_y) && chessboard->getMap().at(temp_x).at(temp_y)->getColor() != _color) {
            if (chessboard->getMap().at(temp_x).at(temp_y)->getType() == ::King) {
                dynamic_cast<EChess::King *>(chessboard->getMap().at(temp_x).at(temp_y))->setCheck();
                continue;
            }
            res.push_back(std::make_tuple(temp_x, temp_y));
        }
    }
    return res;
}
