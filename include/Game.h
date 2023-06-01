/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** Game
*/

#ifndef GAME_H_
#define GAME_H_

namespace EChess
{
    class Game {
        public:
            Game() = default;
            ~Game() = default;
        protected:
        private:
            int _timeply1;
            int _timeply2;
    };
}
#endif /* !GAME_H_ */
