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
            Knight::Knight(Color color, int x, int y);
            ~Knight();

        protected:
        private:
    };
}

#endif /* !KNIGHT_HPP_ */
