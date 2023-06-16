/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** King
*/

#include "King.hpp"
#include "iostream"

EChess::King::King(Color color, int x, int y) : APiece(color, x, y)
{
    _check = false;
    _type = ::King;
    if (_color == ::White)
        _path = "/home/fmarcolo/Documents/EpiChess2/King.png";
    else
        _path = "/home/fmarcolo/Documents/EpiChess2/BKing.png";
}

EChess::King::~King()
{
}

std::vector<std::tuple<int, int, int, int>> EChess::King::castling(Chessboard *chessboard)
{
    std::vector<std::tuple<int, int, int, int>> res;
    std::vector<std::vector<IPiece *>> map = chessboard->getMap();
    _check = false;
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map.size(); j++) {
            if (map.at(i).at(j) && map.at(i).at(j)->getColor() != _color)
                map.at(i).at(j)->getMovements(chessboard);
         }
    }
    if (!_check && _mvts == 0) {
        if (!map[_x + 1][_y] && !map[_x + 2][_y] && map[_x + 3][_y] && map[_x + 3][_y]->getNbMovements() == 0)
            res.push_back(std::make_tuple(_y, _x + 2, _x + 3, _x + 1));
        if (!map[_x - 1][_y] && !map[_x - 2][_y] && !map[_x - 3][_y] && map[_x - 4][_y] && map[_x - 4][_y]->getNbMovements() == 0)
            res.push_back(std::make_tuple(_y, _x - 2, _x - 4, _x - 1));
    }
    return res;
}

std::vector<std::tuple<int, int>> EChess::King::getMovements(Chessboard *chessboard) {
    std::vector<std::vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
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
    return res;
}

void EChess::King::setCheck() {
    _check = true;
}

void EChess::King::setNotCheck() {
    _check = false;
}

bool EChess::King::inCheck() {
    return _check;
}
