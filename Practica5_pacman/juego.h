#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>
#include "objetos.h"
#include "pacman.h"
#include "ghosts.h"
#include "config.h"



class Juego : public QGraphicsScene
{
    Q_OBJECT

public:
    enum GameStatus {Playing, Win, Lose, Pause};
    Juego(int, int, int, int, QString);
    ~Juego();
    void start();
    void stop();
    void pacman_next(Objetos::Dir);
    int get_score();

    Objetos ***map;
    Pacman *pacman;
    Ghost *ghost[Ghost::GhostNum];
    QVector<Objetos*> powerball;
    GameStatus stat;

    friend class Pacman;
    friend class Ghost;


private slots:
    void pacman_mv();
    void powerball_flash();
    void ghost_mv(int);

private:
    int map_h, map_w;
    int map_s;
    int ball_num, eat_num, score;
    int geo_x, geo_y;

    QTimer *ghost_timer[Ghost::GhostNum];
    QTimer *pacman_timer;
    QTimer *powerball_flash_timer;
    bool flash;

};

#endif // JUEGO_H
