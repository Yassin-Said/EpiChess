/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Chessboard
*/
#include <iostream>
#include "pieces/Chessboard.hpp"

EChess::Chessboard::Chessboard()
{
    _map = {{{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}, {{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}}};
    _sizeX = 8;
    _sizeY = 8;
}

std::vector<std::vector<EChess::IPiece *>> EChess::Chessboard::getMap()
{
    return _map;
}

bool EChess::Chessboard::inRange(int x, int y)
{
    if (x >= 0 && x < _sizeX && y >= 0 && y < _sizeY)
        return true;
    return false;
}

void EChess::Chessboard::setMap(std::vector<std::vector<EChess::IPiece *>> map)
{
    this->_map = map;
}

void EChess::Chessboard::addPiece(IPiece *piece)
{
    std::tuple<int, int> pos = piece->getPos();
    if (inRange(std::get<0>(pos), std::get<1>(pos)))
        _map.at(std::get<0>(pos)).at(std::get<1>(pos)) = piece;
}
