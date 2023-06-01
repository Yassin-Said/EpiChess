/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** APiece
*/

#ifndef APIECE_HPP_
#define APIECE_HPP_

enum Color {
    White,
    Black
};



namespace EChess
{
    class APiece {
        public:
            APiece(Color color, int x, int y);
            ~APiece();

        protected:
            int _x;
            int _y;
            Color _color;
            int mvts = 0;
        private:
    };
} // namespace Echess

#endif /* !APIECE_HPP_ */
