#ifndef GHOSTS_H
#define GHOSTS_H
#include "objetos.h"

class Juego;

class Ghost : public Objetos
{
public:
    enum Color {Red, Orange, Pink, Green};
    enum Status {Normal, Blue, Run};
    const static int GhostNum = 4;
    Juego *juego;

    Ghost(int);
    void move();
    Color get_color();

    friend class Juego;
    friend class Pacman;

private:
    void moveup();
    void movedown();
    void moveleft();
    void moveright();

    void randomdir();
    bool movalid(int, int);

    Color color;
    Status status;
    QVector<QPixmap> mov[4];
    QVector<QPixmap> blue_mov;
    QVector<QPixmap> running_mov;
    int mov_index;
    bool is_released;
    int blue_time;
};

#endif // GHOSTS_H
