#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "APiece.hpp"
#include "Pawn.hpp"
#include "King.hpp"
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
            _buttons[i - 1]->setIconSize(QSize(60, 60));
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

bool MainWindow::rookMove(int i, int x, int y)
{
    for (size_t i = 0; i < _cstl.size(); i++) {
        int memo_x = 0;
        int memo_y = 0;
        int memo2_x = 0;
        int memo2_y = 0;
        if (std::get<1>(_cstl[i]) == y && std::get<0>(_cstl[i]) == x) {
            memo_x = std::get<0>(_memopiece->getPos());
            memo_y = std::get<1>(_memopiece->getPos());
            _map->erasePiece(y, x);
            _memopiece->setPos(y, x);
            _map->addPiece(_memopiece);
            _map->delPiece(memo_x, memo_y);
            memo2_x = memo_x;
            memo2_y = std::get<2>(_cstl[i]);
            EChess::IPiece *memo = _map->getPiece(std::get<0>(_cstl[i]), memo_y);
            memo->setPos(std::get<3>(_cstl[i]), std::get<0>(_cstl[i]));
            _map->addPiece(memo);
            _map->delPiece(std::get<2>(_cstl[i]), memo_y);
            std::cout << "get that -> " << memo_y * 8 + memo_x << " " << memo_y * 8 + memo2_y<< std::endl;
            _buttons[memo_y * 8 + memo_x]->setIcon(QIcon(""));
            _buttons[memo_y * 8 + memo2_y]->setIcon(QIcon(""));
            return true;
        }
    }
    return false;
}

bool MainWindow::movePiece(int i, int x, int y)
{
    if (rookMove(i, x, y))
        return true;
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
            _buttons[i - 1]->setIconSize(QSize(60, 60));
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
                std::vector<std::vector<EChess::IPiece *>> newmap = _map->getMap();
                _mvts = {};
                _cstl = {};
                newmap[y][x]->addMovement();
                if (player == Black)
                    player = White;
                else
                    player = Black;
                continue;
            }
            if (map[y][x]) {
                _mvts = {};
                _cstl = {};
                if (map[y][x]->getColor() == player) {
                    _buttons[i]->setStyleSheet("background-color: green");
                    _memopiece = map[y][x];
                    std::vector<std::tuple<int, int>>move = map[y][x]->getMovements(_map);
                    std::vector<std::tuple<int, int, int, int>>intercstl;
                    if (map.at(y).at(x)->getType() == ::King)
                        intercstl = dynamic_cast<EChess::King *>(map.at(y).at(x))->castling(_map);
                    for (size_t index = 0; index < move.size(); index++) {
                        if (map[y][x]->checkMovement(move.at(index), _map))
                            _mvts.push_back(move.at(index));
                    }
                    for (size_t index = 0; index < intercstl.size(); index++) {
                        if (map[y][x]->checkMovement(std::make_tuple(std::get<1>(intercstl.at(index)),std::get<0>(intercstl.at(index))), _map))
                            _cstl.push_back(intercstl.at(index));
                    }
                }
                for (size_t j = 0; j < _mvts.size(); j++)
                    _buttons[std::get<1>(_mvts[j]) * 8 + std::get<0>(_mvts[j])]->setStyleSheet("background-color: blue");
                for (size_t j = 0; j < _cstl.size(); j++)
                    _buttons[std::get<0>(_cstl[j]) * 8 + std::get<1>(_cstl[j])]->setStyleSheet("background-color: orange");
            }
        }
    }
    drawIcon();
}
