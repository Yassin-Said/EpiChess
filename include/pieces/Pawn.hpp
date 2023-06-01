/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Pawn
*/

#ifndef PAWN_HPP_
#define PAWN_HPP_

#include "APiece.hpp"

namespace EChess
{
    class Pawn : public APiece{
        public:
            Pawn::Pawn(Color color, int x, int y);
            ~Pawn();

        protected:
        private:
    };
}

#endif /* !PAWN_HPP_ */
