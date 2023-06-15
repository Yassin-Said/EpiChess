/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "APiece.hpp"

namespace EChess
{
    class Knight : public APiece{
        public:
            Knight(Color color, int x, int y);
            ~Knight();
            std::vector<std::tuple<int, int>> getMovements(Chessboard *chessboard);
        protected:
        private:
    };
}

#endif /* !KNIGHT_HPP_ */
