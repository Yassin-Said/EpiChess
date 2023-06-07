/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Queen
*/

#include "pieces/Queen.hpp"
#include "pieces/King.hpp"

EChess::Queen::Queen(Color color, int x, int y) : APiece(color, x, y)
{
}

EChess::Queen::~Queen()
{
}

std::vector<std::tuple<int, int>> EChess::Queen::getMovements(Chessboard* chessboard)
{
    std::vector<std::tuple<int, int>> res;
    int incr = 0;

    if (_color == Black)
        incr = -1;
    else
        incr = 1;

    std::size_t newX = _x;
    std::size_t newY = _y + incr;

    if (chessboard->getMap().at(newX).at(newY) == nullptr) {
        res.push_back(std::make_tuple(newX, newY));
        if (getNbMovements() == 0 && chessboard->getMap().at(newX).at(newY + incr) == nullptr)
            res.push_back(std::make_tuple(newX, newY + incr));
    }
    if (newX + 1 < chessboard->getMap().size() && newY < chessboard->getMap().at(newX + 1).size()) {
        if (chessboard->getMap().at(newX + 1).at(newY) != nullptr && chessboard->getMap().at(newX + 1).at(newY)->getColor() != _color) {
            if (chessboard->getMap().at(newX + 1).at(newY)->getType() == ::King)
                dynamic_cast<EChess::King*>(chessboard->getMap().at(newX + 1).at(newY))->setCheck();
            else
                res.push_back(std::make_tuple(newX + 1, newY));
        }
    }

    if (newX >= 1 && newY < chessboard->getMap().at(newX - 1).size()) {
        if (chessboard->getMap().at(newX - 1).at(newY) != nullptr && chessboard->getMap().at(newX - 1).at(newY)->getColor() != _color) {
            if (chessboard->getMap().at(newX - 1).at(newY)->getType() == ::King)
                dynamic_cast<EChess::King*>(chessboard->getMap().at(newX - 1).at(newY))->setCheck();
            else
                res.push_back(std::make_tuple(newX - 1, newY));
        }
    }
    return res;
}
