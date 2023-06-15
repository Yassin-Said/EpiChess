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
    #include <string>


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
            virtual std::tuple<int, int> findKing(std::vector<std::vector<IPiece *>> map) = 0;
            virtual std::vector<std::tuple<int, int>> getMovements(Chessboard *chessboard) = 0;
            virtual bool checkMovement(std::tuple<int, int>, Chessboard* chessboard) = 0;
            virtual void move(std::vector<int>) = 0;
            virtual int getNbMovements() = 0;
            virtual Color getColor() = 0;
            virtual Type getType() = 0;
            virtual std::tuple<int, int> getPos() = 0;
            virtual void setPos(int x, int y) = 0;
            virtual std::string getPath() = 0;

        protected:
        private:
    };
}
#endif /* !IPIECE_HPP_ */
