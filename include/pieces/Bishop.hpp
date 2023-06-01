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
            Bishop::Bishop(Color color, int x, int y);
            ~Bishop();

        protected:
        private:
    };
}

/* !BISHOP_HPP_ */
