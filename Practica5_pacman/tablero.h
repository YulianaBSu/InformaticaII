#ifndef TABLERO_H
#define TABLERO_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "pacman.h"

class Tablero
{

public:
    Tablero(QGraphicsScene *scene);
    ~Tablero();

    void cargarMapa();
    void crearElemento(int fila, int columna, QChar tipo);


private:

    const int celdaSize = 20;

    QGraphicsScene *scene;

    QPixmap getFantasmaImagen(QChar tipo);
    Pacman *pacman;

};

#endif // TABLERO_H
