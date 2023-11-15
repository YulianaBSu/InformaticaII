#include "juego.h"

Objetos::Objetos(ObjectType t, QPixmap pixmap)
    : QGraphicsPixmapItem(pixmap)
{
    type = t;
}

Objetos::ObjectType Objetos::get_type()
{
    return type;
}

int Objetos::get_x()
{
    return px;
}

int Objetos::get_y()
{
    return py;
}

int Objetos::get_score()
{
    return score;
}

void Objetos::set_score(int s)
{
    score = s;
}

void Objetos::set_dir(Dir d)
{
    dir = d;
}

Objetos::Dir Objetos::get_dir()
{
    return dir;
}

Objetos::Dir Objetos::get_next_dir()
{
    return next_dir;
}

void Objetos::set_next_dir(Dir d)
{
    next_dir = d;
}

Objetos::~Objetos()
{
}
