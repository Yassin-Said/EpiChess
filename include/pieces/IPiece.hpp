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

namespace EChess
{
    class IPiece {
        public:
            IPiece() = default;
            ~IPiece() = default;
            virtual std::tuple<int, int> getMovements() = 0;
            virtual void move(std::vector<std::vector<int>>) = 0;
            virtual int getNbMovements() = 0;

        protected:
        private:
    };
}
#endif /* !IPIECE_HPP_ */
