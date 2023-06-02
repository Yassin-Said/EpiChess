/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** APiece
*/

#include "pieces/APiece.hpp"

EChess::APiece::APiece(Color color, int x, int y)
{
    _color = color;
    _x = x;
    _y = y;
}

EChess::APiece::~APiece()
{
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