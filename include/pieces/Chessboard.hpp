/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** chessboard
*/

#ifndef CHESSBOARD_HPP_
#define CHESSBOARD_HPP_

#include "IPiece.hpp"

namespace EChess
{
    class IPiece;
    class Chessboard {
        public:
            Chessboard() = default;
            ~Chessboard() = default;
            void displayBoard();
            std::vector<std::vector<IPiece *>> getMap();
            bool inRange(int, int);
        private:
            std::vector<std::vector<IPiece *>> _map;
            int _sizeX;
            int _sizeY;
    };
}

#endif /* !CHESSBOARD_HPP_ */
