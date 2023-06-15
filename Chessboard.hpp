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
            Chessboard();
            ~Chessboard() = default;
            void displayBoard();
            std::vector<std::vector<IPiece *>> getMap();
            void setMap(std::vector<std::vector<IPiece *>>);
            void addPiece(IPiece *);
            bool inRange(int, int);
            void delPiece(int x, int y);
            void erasePiece(int x, int y);
        private:
            std::vector<std::vector<IPiece *>> _map;
            int _sizeX;
            int _sizeY;
    };
}

#endif /* !CHESSBOARD_HPP_ */
