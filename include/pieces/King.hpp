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
            King::King(Color color, int x, int y);
            ~King();

        protected:
        private:
    };
}

#endif /* !KING_HPP_ */
