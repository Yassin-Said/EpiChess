/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Bishop
*/

#ifndef BISHOP_HPP_
#define BISHOP_HPP_

#include "APiece.hpp"

namespace EChess
{
    class Bishop : public APiece{
        public:
            Bishop(Color color, int x, int y);
            virtual std::vector<std::tuple<int, int>> getMovements(Chessboard *chessboard) override;
            ~Bishop();

        protected:
        private:
    };
}

#endif

/* !BISHOP_HPP_ */
