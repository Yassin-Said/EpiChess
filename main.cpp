/*
** EPITECH PROJECT, 2023
** EpiChess
** File description:
** main
*/

#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include "Rect.hpp"
#include <QGraphicsView>

int main (int ac, char **av)
{



    QApplication app(ac, av);

    QGraphicsScene *scene = new QGraphicsScene();

    Rect rect;
    rect.setRect(0, 0, 100, 100);
    rect.setBrush(Qt::white);

    scene->addItem(&rect);
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    return app.exec();
}
/*

#include "pieces/IPiece.hpp"
#include "pieces/King.hpp"
#include "pieces/Bishop.hpp"
#include "pieces/Chessboard.hpp"
#include <iostream>

int main ()
{
    EChess::Chessboard *chess = new EChess::Chessboard;
    EChess::IPiece *king = new EChess::Bishop(Black, 2, 2);
    chess->addPiece(king);
    std::vector<std::tuple<int, int>> res = king->getMovements(chess);
    for (size_t i = 0; i < res.size(); i++) {
        std::cout << std::get<0>(res.at(i)) << " " << std::get<1>(res.at(i)) << std::endl;
    }
    return 0;
}*/