/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** APiece
*/

#ifndef APIECE_HPP_
#define APIECE_HPP_

#include "IPiece.hpp"

namespace EChess
{
    class APiece : public IPiece {
        public:
            APiece(Color color, int x, int y);
            ~APiece();
            virtual void move(std::vector<int>) override;
            virtual Color getColor() override;
            virtual Type getType() override;
            virtual int getNbMovements() override;

        protected:
            int _x;
            int _y;
            Color _color;
            int _mvts = 0;
            Type _type;
        private:
    };
} // namespace Echess

#endif /* !APIECE_HPP_ */
