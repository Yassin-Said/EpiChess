/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Tower
*/

#ifndef TOWER_HPP_
#define TOWER_HPP_

#include "APiece.hpp"

namespace EChess
{
    class Tower : public APiece{
        public:
            Tower::Tower(Color color, int x, int y);
            ~Tower();

        protected:
        private:
    };
}

#endif /* !TOWER_HPP_ */
