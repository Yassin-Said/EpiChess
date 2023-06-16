/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** APiece
*/

#include "APiece.hpp"
#include "King.hpp"
#include "iostream"

EChess::APiece::APiece(Color color, int x, int y)
{
    _path = "";
    _color = color;
    _x = x;
    _y = y;
}

EChess::APiece::~APiece()
{
}

std::tuple<int, int> EChess::APiece::findKing(std::vector<std::vector<IPiece *>> map)
{
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map.size(); j++) {
            if (map.at(i).at(j) && map.at(i).at(j)->getType() == ::King && map.at(i).at(j)->getColor() == _color) {
                return std::make_tuple(i, j);
            }
        }
    }
    return std::make_tuple(0, 0);
}

std::tuple<int, int> EChess::APiece::getPos()
{
    return (std::make_tuple(_x, _y));
}

void EChess::APiece::setPos(int x, int y)
{
    _x = x;
    _y = y;
}

void EChess::APiece::addMovement()
{
    _mvts++;
}

bool EChess::APiece::checkMovement(std::tuple<int, int> pos, Chessboard* chessboard)
{
    std::vector<std::vector<IPiece *>> savemap = chessboard->getMap();
    std::vector<std::vector<IPiece *>> map = chessboard->getMap();
    int memox = _x;
    int memoy = _y;

    _x = std::get<0>(pos);
    _y = std::get<1>(pos);
    map.at(_x).at(_y) = this;
    map.at(memox).at(memoy) = nullptr;
    chessboard->setMap(map);
    std::tuple<int, int> kPos = findKing(map);
    dynamic_cast<EChess::King *>(map.at(std::get<0>(kPos)).at(std::get<1>(kPos)))->setNotCheck();
    for (std::size_t i = 0; i < map.size(); i++) {
        for (std::size_t j = 0; j < map.size(); j++) {
            if (map.at(i).at(j) && map.at(i).at(j)->getColor() != _color)
                map.at(i).at(j)->getMovements(chessboard);
            if (dynamic_cast<EChess::King *>(map.at(std::get<0>(kPos)).at(std::get<1>(kPos)))->inCheck()) {
                chessboard->setMap(savemap);
                _x = (memox);
                _y = (memoy);
                return false;
            }
        }
    }
    chessboard->setMap(savemap);
    _x = (memox);
    _y = (memoy);
    return true;
}

Color EChess::APiece::getColor()
{
    return _color;
}

int EChess::APiece::getNbMovements()
{
    return _mvts;
}

Type EChess::APiece::getType()
{
    return _type;
}

void EChess::APiece::move(std::vector<int> pos)
{
    _x = pos.at(0);
    _y = pos.at(1);
}
