#ifndef PACMAN_H
#define PACMAN_H

#include "objetos.h"
class Juego;
/* Pacman */
class Pacman : public Objetos
{
public:
    Pacman();
    void move();
    Juego *juego;

    friend class Juego;

private:
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    void eat_ball(int, int);
    bool movalid(int, int);

    QVector<QPixmap> mov[4];
    int mov_index;
};
#endif // PACMAN_H
