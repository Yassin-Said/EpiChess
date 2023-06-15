#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "APiece.hpp"
#include <iostream>

MainWindow::MainWindow(EChess::Chessboard *map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _map = map;
    std::vector<std::vector<EChess::IPiece *>> mapmemo = _map->getMap();
    ui->setupUi(this);
    for (int i = 1; i < 65; i++) {
        int x = (i - 1) / 8;
        int y = (i - 1) % 8;
        QString name = "pushButton_" + QString::number(i);
        _buttons[i - 1] = MainWindow::findChild<QPushButton *>(name);
        if (mapmemo[y][x]) {
            _buttons[i - 1]->setIcon(QIcon(_map->getMap().at(y).at(x)->getPath().c_str()));
            _buttons[i - 1]->setIconSize(QSize(30, 30));
        }
        connect(_buttons[i - 1], SIGNAL(released()), this, SLOT(TilePressed()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPiece(EChess::IPiece *piece)
{
    _map->addPiece(piece);
}

bool MainWindow::movePiece(int i, int x, int y)
{
    for (size_t i = 0; i < _mvts.size(); i++) {
        int memo_x = 0;
        int memo_y = 0;
        if (std::get<0>(_mvts[i]) == y && std::get<1>(_mvts[i]) == x) {
            memo_x = std::get<0>(_memopiece->getPos());
            memo_y = std::get<1>(_memopiece->getPos());
            _map->erasePiece(y, x);
            _memopiece->setPos(y, x);
            _map->addPiece(_memopiece);
            _map->delPiece(memo_x, memo_y);
            _buttons[memo_y * 8 + memo_x]->setIcon(QIcon(""));
            return true;
        }
    }
    return false;
}

void MainWindow::drawIcon() {
    std::vector<std::vector<EChess::IPiece *>> mapmemo = _map->getMap();
    for (int i = 1; i < 65; i++) {
        int x = (i - 1) / 8;
        int y = (i - 1) % 8;
        if (mapmemo[y][x]) {
            _buttons[i - 1]->setIcon(QIcon(_map->getMap().at(y).at(x)->getPath().c_str()));
            _buttons[i - 1]->setIconSize(QSize(30, 30));
        }
    }
}

void MainWindow::TilePressed()
{
    QImage myImage;
    QPushButton *button = (QPushButton *)sender();
    std::cout << button->pos().x() << " " << button->pos().y() << std::endl;
    std::vector<std::vector<EChess::IPiece *>> map = _map->getMap();


    for (int i = 0; i < 64; ++i)
            _buttons[i]->setStyleSheet(QString("background-color: ") + (((i % 2) + (i / 8 % 2)) == 1 ? "black" : "white"));
    for (int i = 0; i < 64; ++i) {
        if (_buttons[i]->hasFocus()) {
            int x = i / 8;
            int y = i % 8;
            _buttons[i]->setStyleSheet("background-color: red");
            if (movePiece(i, x, y)) {
                _mvts = {};
                if (player == Black)
                    player = White;
                else
                    player = Black;
                continue;
            }
            if (map[y][x]) {
                _mvts = {};
                if (map[y][x]->getColor() == player) {
                    _buttons[i]->setStyleSheet("background-color: green");
                    _memopiece = map[y][x];
                    std::vector<std::tuple<int, int>>move = map[y][x]->getMovements(_map);
                    for (size_t index = 0; index < move.size(); index++) {
                        if (map[y][x]->checkMovement(move.at(index), _map))
                            _mvts.push_back(move.at(index));
                    }
                }
                for (size_t j = 0; j < _mvts.size(); j++)
                    _buttons[std::get<1>(_mvts[j]) * 8 + std::get<0>(_mvts[j])]->setStyleSheet("background-color: blue");
            }
        }
    }
    drawIcon();
}
