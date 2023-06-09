/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** King
*/

#ifndef KING_HPP_
#define KING_HPP_

#include "APiece.hpp"

namespace EChess
{
    class King : public APiece{
        public:
            King(Color color, int x, int y);
            ~King();
            std::vector<std::tuple<int, int>> getMovements(Chessboard *chessboard);
            void setCheck();
            bool inCheck();
        protected:
        private:
            bool _check = false;
    };
}

#endif /* !KING_HPP_ */
