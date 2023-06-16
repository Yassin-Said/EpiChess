#include "mainwindow.h"

#include <QApplication>
#include "IPiece.hpp"
#include "Chessboard.hpp"
#include "Bishop.hpp"
#include "Tower.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Queen.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EChess::Chessboard *chess2 = new EChess::Chessboard;
    for (int i = 0; i < 8; i++) {
        EChess::IPiece *bpawn = new EChess::Pawn(Black, i, 1);
        chess2->addPiece(bpawn);
        EChess::IPiece *pawn = new EChess::Pawn(White, i, 6);
        chess2->addPiece(pawn);
    }
    EChess::IPiece *btower = new EChess::Tower(Black, 0, 0);
    chess2->addPiece(btower);
    EChess::IPiece *btower2 = new EChess::Tower(Black, 7, 0);
    chess2->addPiece(btower2);
    EChess::IPiece *tower = new EChess::Tower(White, 0, 7);
    chess2->addPiece(tower);
    EChess::IPiece *tower2 = new EChess::Tower(White, 7, 7);
    chess2->addPiece(tower2);

    EChess::IPiece *bknight = new EChess::Knight(Black, 1, 0);
    chess2->addPiece(bknight);
    EChess::IPiece *bknight2 = new EChess::Knight(Black, 6, 0);
    chess2->addPiece(bknight2);
    EChess::IPiece *knight = new EChess::Knight(White, 1, 7);
    chess2->addPiece(knight);
    EChess::IPiece *knight2 = new EChess::Knight(White, 6, 7);
    chess2->addPiece(knight2);

    EChess::IPiece *bbishop = new EChess::Bishop(Black, 2, 0);
    chess2->addPiece(bbishop);
    EChess::IPiece *bbishop2 = new EChess::Bishop(Black, 5, 0);
    chess2->addPiece(bbishop2);
    EChess::IPiece *bishop = new EChess::Bishop(White, 2, 7);
    chess2->addPiece(bishop);
    EChess::IPiece *bishop2 = new EChess::Bishop(White, 5, 7);
    chess2->addPiece(bishop2);

    EChess::IPiece *bking = new EChess::King(Black, 4, 0);
    chess2->addPiece(bking);
    EChess::IPiece *king = new EChess::King(White, 4, 7);
    chess2->addPiece(king);
    EChess::IPiece *bqueen = new EChess::Queen(Black, 3, 0);
    chess2->addPiece(bqueen);
    EChess::IPiece *queen = new EChess::Queen(White, 3, 7);
    chess2->addPiece(queen);

    MainWindow w(chess2);

    w.show();
    return a.exec();
}
