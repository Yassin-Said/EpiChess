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
            virtual std::tuple<int, int> findKing(std::vector<std::vector<IPiece *>> map) override;
            virtual void move(std::vector<int>) override;
            virtual Color getColor() override;
            virtual Type getType() override;
            virtual int getNbMovements() override;
            virtual bool checkMovement(std::tuple<int, int>, Chessboard* chessboard) override;
            virtual std::tuple<int, int> getPos() override;
            virtual void setPos(int x, int y) override;
            virtual std::string getPath() override {return _path;}

        protected:
            std::string _path;
            int _x;
            int _y;
            Color _color;
            int _mvts = 0;
            Type _type;
        private:
    };
} // namespace Echess

#endif /* !APIECE_HPP_ */
