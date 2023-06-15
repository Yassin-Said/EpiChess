/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Knight
*/

#include "Knight.hpp"
#include "King.hpp"

EChess::Knight::Knight(Color color, int x, int y) : APiece(color, x, y)
{
    if (_color == ::White)
        _path = "/home/fmarcolo/Documents/EpiChess2/Knight.png";
    else
        _path = "/home/fmarcolo/Documents/EpiChess2/BKnight.png";
}

EChess::Knight::~Knight()
{
}

std::vector<std::tuple<int, int>> EChess::Knight::getMovements(Chessboard *chessboard)
{
    std::vector<std::vector<int>> dir = {{1, -2}, {1, 2}, {-1, -2}, {-1, 2},
        {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
    std::vector<std::tuple<int, int>> res;
    for (int i = 0; i != 8; i++) {
        int temp_x = _x + dir.at(i).at(0);
        int temp_y = _y + dir.at(i).at(1);
        if (chessboard->inRange(temp_x, temp_y) && !chessboard->getMap().at(temp_x).at(temp_y)) {
            res.push_back(std::make_tuple(temp_x, temp_y));
            continue;
        }
        if (chessboard->inRange(temp_x, temp_y) && chessboard->getMap().at(temp_x).at(temp_y)->getColor() != _color) {
            if (chessboard->getMap().at(temp_x).at(temp_y)->getType() == ::King) {
                dynamic_cast<EChess::King *>(chessboard->getMap().at(temp_x).at(temp_y))->setCheck();
                continue;
            }
        res.push_back(std::make_tuple(temp_x, temp_y));
        }
    }
    return (res);
}
