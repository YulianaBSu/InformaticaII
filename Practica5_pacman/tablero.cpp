#include "tablero.h"
#include <QBrush>
#include <QPixmap>
#include <QRandomGenerator>

Tablero::Tablero(QGraphicsScene *scene) : scene(scene)

{

}

Tablero::~Tablero()
{

}

void Tablero::cargarMapa()
{
    // Definir el tamaño de cada celda
    //const int celdaSize = 20;

    // Definir el mapa del laberinto
    QString mapa =
        "1111111111111111111"
        "1000000001000000001"
        "1d110111010111011d1"
        "1000000000000000001"
        "1011010111110101101"
        "1000010001000100001"
        "1111011101011101111"
        "0001010000000101000"
        "000101011g110101000"
        "00010001ggg10001000"
        "0001010111110101000"
        "0001010000000101000"
        "1111010111110101111"
        "1000000001000000001"
        "1011011101011101101"
        "1d0100000p0000010d1"
        "1101010111110101011"
        "1000010001000100001"
        "1011111101011111101"
        "1000000000000000001"
        "1111111111111111111";




    // Crear elementos en la escena según el mapa
    for (int i = 0; i < mapa.length(); ++i) {
        int fila = i / 19;
        int columna = i % 19;

        if (mapa[i] != '0') {
            crearElemento(fila, columna, mapa.at(i));
        }
    }

}

void Tablero::crearElemento(int fila, int columna, QChar tipo)
{
    // Definir colores para los elementos del juego
    QColor colorPared(0, 0, 255);  // Azul claro

    // Crear elementos en la escena según el tipo
    QGraphicsRectItem *muro = nullptr;
    //QGraphicsPixmapItem *elemento = nullptr;
    QGraphicsPixmapItem *fantasma = nullptr;

    switch (tipo.toLatin1()) {
        case '1':
            muro = new QGraphicsRectItem(columna * celdaSize, fila * celdaSize, celdaSize, celdaSize);
            muro->setBrush(QBrush(colorPared));
            //addItem(muro);
            break;
        case 'g':
            fantasma = new QGraphicsPixmapItem(getFantasmaImagen(tipo));
            fantasma->setPos(columna * celdaSize, fila * celdaSize);
            scene->addItem(fantasma);
            break;

        case 'p':
            break;
    }

    if (muro) {
        scene->addItem(muro);
    }
}
QPixmap Tablero::getFantasmaImagen(QChar tipo)
{
    // Mapa para rastrear qué tipo de fantasmas ya se han utilizado
    static QMap<QChar, bool> tiposUtilizados;

    // Devuelve la imagen correspondiente al tipo de fantasma, asegurándose de que no se repita
    if (tipo == 'g') {
        if (!tiposUtilizados.contains('r')) {
            tiposUtilizados['r'] = true;
            return QPixmap(":/pacman/reddown1.png");
        } else if (!tiposUtilizados.contains('v')) {
            tiposUtilizados['v'] = true;
            return QPixmap(":/pacman/greenup1.png");
        } else if (!tiposUtilizados.contains('p')) {
            tiposUtilizados['p'] = true;
            return QPixmap(":/pacman/pinkup1.png");
        } else if (!tiposUtilizados.contains('a')) {
            tiposUtilizados['a'] = true;
            return QPixmap(":/pacman/yellowup1.png");
        }
    }

    return QPixmap(":/images/default.png");
}
