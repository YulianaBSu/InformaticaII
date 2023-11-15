#ifndef OBJETOS_H
#define OBJETOS_H
#include <QGraphicsItem>

/* Predefine the game object */
class Juego;


/* Base class of ghosts, pacman */
class Objetos : public QGraphicsPixmapItem
{
public:
    enum ObjectType {Ball, Wall, Pacman, Ghost, Blank, PowerBall};
    enum Dir {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
    static const int Width = 20;

    Objetos(ObjectType, QPixmap);
    ~Objetos();
    ObjectType get_type();
    int get_x();
    int get_y();
    int get_score();
    void set_score(int);
    void set_dir(Dir);
    void set_next_dir(Dir);
    Dir get_dir();
    Dir get_next_dir();

    friend class Juego;
    friend class Ghost;

protected:
    int px, py;                 // coordinate in map
    Dir dir;                    // current moving direction
    Dir next_dir;               // next direction by w, a, s, d key
    ObjectType type;
    int score;
};

#endif // OBJETOS_H
