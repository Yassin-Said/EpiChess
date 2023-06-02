/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** IPiece
*/

#ifndef IPIECE_HPP_
#define IPIECE_HPP_
    #include <tuple>
    #include <vector>
    #include "Chessboard.hpp"

enum Color {
    White,
    Black
};

enum Type {
    Pawn,
    Tower,
    Knight,
    Bishop,
    Queen,
    King
};

namespace EChess
{
    class Chessboard;
    class IPiece {
        public:
            IPiece() = default;
            ~IPiece() = default;
            virtual std::vector<std::tuple<int, int>> getMovements(Chessboard *chessboard) = 0;
            virtual void move(std::vector<int>) = 0;
            virtual int getNbMovements() = 0;
            virtual Color getColor() = 0;
            virtual Type getType() = 0;

        protected:
        private:
    };
}
#endif /* !IPIECE_HPP_ */
