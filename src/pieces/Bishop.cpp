/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Bishop
*/

#include "pieces/Bishop.hpp"
#include "pieces/King.hpp"
#include <iostream>

EChess::Bishop::Bishop(Color color, int x, int y) : APiece(color, x, y)
{
}

EChess::Bishop::~Bishop()
{
}

std::vector<std::tuple<int, int>> EChess::Bishop::getMovements(Chessboard *chessboard)
{
    std::vector<std::vector<int>> dir = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    std::vector<std::tuple<int, int>> res;
    for (int i = 0; i != 4; i++) {
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
    return (res);
}
