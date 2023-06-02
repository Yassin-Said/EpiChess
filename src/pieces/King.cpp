/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** King
*/

#include "pieces/King.hpp"

EChess::King::King(Color color, int x, int y) : APiece(color, x, y)
{
}

EChess::King::~King()
{
}

std::vector<std::tuple<int, int>> EChess::King::getMovements(Chessboard *chessboard)
{
    std::vector<std::tuple<int, int>>res;
    (void)chessboard;
    return res;
}

void EChess::King::setCheck() {
    _check = true;
}