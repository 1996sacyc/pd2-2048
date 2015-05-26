#ifndef GAME_H
#define GAME_H
#include "setup.h"
#include <Qstring>
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <ctime>

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    class Set{
          public:
          int location; /*label位置*/
          int num; /*儲存變數0~2048*/
    };
    Set block[16];
    QString str;
    int dir;
    int check[4][4];
    int temcheck[4][4];
    int score;
    int result;
    void Gamestart();
    void Setpics(Set & b);
    void CheckGame();
    void NewGameInit();
    void GetNumber();
    void keyPressEvent(QKeyEvent *event);
    void CheckScore();
    int ProcessGame();
    int GetNewNumber();

private:
    Ui::game *ui;
};

#endif // GAME_H
