/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** APiece
*/

#include "APiece.hpp"

EChess::APiece::APiece(Color color, int x, int y)
{
    _color = color;
    _x = x;
    _y = x;
}

EChess::APiece::~APiece()
{
}
