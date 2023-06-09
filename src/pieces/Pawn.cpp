/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Pawn
*/

#include "pieces/Pawn.hpp"
#include "pieces/King.hpp"

EChess::Pawn::Pawn(Color color, int x, int y) : APiece(color, x, y)
{
}

EChess::Pawn::~Pawn()
{
}

// std::vector<std::tuple<int, int>> EChess::Pawn::getMovements(Chessboard *chessboard)
// {
//     std::vector<std::tuple<int, int>> res;
//     int incr = 0;

//     if (_color == Black)
//         incr = -1;
//     else
//         incr = 1;
//     if (chessboard->getMap().at(_x).at(_y + incr) == nullptr) {
//         res.push_back(std::make_tuple(_x, _y + incr));
//         if (chessboard->getMap().at(_x).at(_y + incr * 2) == nullptr && getNbMovements() == 0)
//             res.push_back(std::make_tuple(_x, _y + incr));
//         if (chessboard->getMap().at(_x + 1).at(_y + incr) && chessboard->getMap().at(_x + 1).at(_y + incr)->getColor() != _color) {
//             if (chessboard->getMap().at(_x + 1).at(_y + incr)->getType() == ::King)
//                 dynamic_cast<EChess::King *>(chessboard->getMap().at(_x + 1).at(_y + incr))->setCheck();
//             else
//                 res.push_back(std::make_tuple(_x, _y + incr));
//         }
//     }
// }



std::vector<std::tuple<int, int>> EChess::Pawn::getMovements(Chessboard* chessboard)
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
    if (newY < chessboard->getMap().at(newX - 1).size()) {
        if (chessboard->getMap().at(newX - 1).at(newY) != nullptr && chessboard->getMap().at(newX - 1).at(newY)->getColor() != _color) {
            if (chessboard->getMap().at(newX - 1).at(newY)->getType() == ::King)
                dynamic_cast<EChess::King*>(chessboard->getMap().at(newX - 1).at(newY))->setCheck();
            else
                res.push_back(std::make_tuple(newX - 1, newY));
        }
    }
    return res;
}