#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <memory>
#include <QtPrintSupport/QPrintDialog>
#include "Chessboard.hpp"
#include "APiece.hpp"
#include "IPiece.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(EChess::Chessboard *, QWidget *parent = 0);
    void addPiece(EChess::IPiece *);
    ~MainWindow();

private:
    EChess::Chessboard *_map;
    Ui::MainWindow *ui;
    QPushButton *_buttons[64];
    EChess::IPiece *_memopiece;
    void drawIcon();
    std::vector<std::tuple<int,int>>_mvts;
    bool movePiece(int i, int x, int y);
    Color player = White;

private slots:
    void TilePressed();
};
#endif // MAINWINDOW_H
