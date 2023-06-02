/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Chessboard
*/

#include "pieces/Chessboard.hpp"

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