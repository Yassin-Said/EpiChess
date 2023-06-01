/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Queen
*/

#ifndef QUEEN_HPP_
#define QUEEN_HPP_

#include "APiece.hpp"

namespace EChess
{
    class Queen : public APiece{
        public:
            Queen::Queen(Color color, int x, int y);
            ~Queen();

        protected:
        private:
    };
}

#endif /* !QUEEN_HPP_ */
