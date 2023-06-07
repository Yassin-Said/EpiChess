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