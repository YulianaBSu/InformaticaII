#include "juego.h"
#include <QRandomGenerator>
#define W (Objetos::Width)

Ghost::Ghost(int clr) : Objetos(
    Objetos::Ghost, QPixmap())
{
    color = (Color)clr;
    mov_index = 0;
    is_released = true;
    dir = Dir(QRandomGenerator::global()->generate() % 4);
    status = Normal;

    switch (color) {
    case Red:
        mov[Right].push_back(QPixmap(":/pacman/redright1.png"));
        mov[Right].push_back(QPixmap(":/pacman/redright2.png"));
        mov[Up].push_back(QPixmap(":/pacman/redup1.png"));
        mov[Up].push_back(QPixmap(":/pacman/redup2.png"));
        mov[Left].push_back(QPixmap(":/pacman/redleft1.png"));
        mov[Left].push_back(QPixmap(":/pacman/redleft2.png"));
        mov[Down].push_back(QPixmap(":/pacman/reddown1.png"));
        mov[Down].push_back(QPixmap(":/pacman/reddown2.png"));
        break;
    case Orange:
        mov[Right].push_back(QPixmap(":/pacman/orangeright1.png"));
        mov[Right].push_back(QPixmap(":/pacman/orangeright2.png"));
        mov[Up].push_back(QPixmap(":/pacman/orangeup1.png"));
        mov[Up].push_back(QPixmap(":/pacman/orangeup2.png"));
        mov[Left].push_back(QPixmap(":/pacman/orangeleft1.png"));
        mov[Left].push_back(QPixmap(":/pacman/orangeleft2.png"));
        mov[Down].push_back(QPixmap(":/pacman/orangedown1.png"));
        mov[Down].push_back(QPixmap(":/pacman/orangedown2.png"));
        break;
    case Green:
        mov[Right].push_back(QPixmap(":/pacman/greenright1.png"));
        mov[Right].push_back(QPixmap(":/pacman/greenright2.png"));
        mov[Up].push_back(QPixmap(":/pacman/greenup1.png"));
        mov[Up].push_back(QPixmap(":/pacman/greenup2.png"));
        mov[Left].push_back(QPixmap(":/pacman/greenleft1.png"));
        mov[Left].push_back(QPixmap(":/pacman/greenleft2.png"));
        mov[Down].push_back(QPixmap(":/pacman/greendown1.png"));
        mov[Down].push_back(QPixmap(":/pacman/greendown2.png"));
        break;
    case Pink:
        mov[Right].push_back(QPixmap(":/pacman/pinkright1.png"));
        mov[Right].push_back(QPixmap(":/pacman/pinkright2.png"));
        mov[Up].push_back(QPixmap(":/pacman/pinkup1.png"));
        mov[Up].push_back(QPixmap(":/pacman/pinkup2.png"));
        mov[Left].push_back(QPixmap(":/pacman/pinkleft1.png"));
        mov[Left].push_back(QPixmap(":/pacman/pinkleft2.png"));
        mov[Down].push_back(QPixmap(":/pacman/pinkdown1.png"));
        mov[Down].push_back(QPixmap(":/pacman/pinkdown2.png"));
        break;
    }

    blue_mov.push_back(QPixmap(":/pacman/gblue1.png"));
    blue_mov.push_back(QPixmap(":/pacman/gblue2.png"));
    running_mov.push_back(QPixmap(":/pacman/run.png"));
    setPixmap(mov[Right][0]);
}


Ghost::Color Ghost::get_color()
{
    return color;
}

void Ghost::moveup()
{
    QVector<QPixmap> *ptr;
    switch (status) {
    case Normal:
        ptr = &mov[Up];
        break;
    case Blue:
        ptr = &blue_mov;
        break;
    case Run:
        ptr = &running_mov;
        break;
    }

    mov_index++;
    if (mov_index >= ptr->size()) {
        mov_index = 0;
    }
    setPixmap((*ptr)[mov_index]);
    setY(static_cast<int>(y()) - 1);
}

void Ghost::movedown()
{
    QVector<QPixmap> *ptr;
    switch (status) {
    case Normal:
        ptr = &mov[Down];
        break;
    case Blue:
        ptr = &blue_mov;
        break;
    case Run:
        ptr = &running_mov;
        break;
    }

    mov_index++;
    if (mov_index >= ptr->size()) {
        mov_index = 0;
    }
    setPixmap((*ptr)[mov_index]);
    setY(static_cast<int>(y()) + 1);
}
void Ghost::moveleft()
{
    QVector<QPixmap> *ptr;
    switch (status) {
    case Normal:
        ptr = &mov[Left];
        break;
    case Blue:
        ptr = &blue_mov;
        break;
    case Run:
        ptr = &running_mov;
        break;
    }

    mov_index++;
    if (mov_index >= ptr->size()) {
        mov_index = 0;
    }
    setPixmap((*ptr)[mov_index]);
    setX(static_cast<int>(x()) - 1);
}



void Ghost::moveright()
{
    QVector<QPixmap> *ptr;
    switch (status) {
    case Normal:
        ptr = &mov[Right];
        break;
    case Blue:
        ptr = &blue_mov;
        break;
    case Run:
        ptr = &running_mov;
        break;
    }

    mov_index++;
    if (mov_index >= ptr->size()) {
        mov_index = 0;
    }
    setPixmap((*ptr)[mov_index]);
    setX(static_cast<int>(x()) + 1);
}


bool Ghost::movalid(int i, int j)
{
    if (i < 0 || j < 0) {
        return false;
    }

    if (i >= juego->map_h || j >= juego->map_w) {
        return false;
    }

    switch (juego->map[i][j]->get_type()) {
    case Wall:
        return false;
    default:
        return true;
    }
}

void Ghost::randomdir()
{
    QVector<Dir> oklist;
    if (movalid(py, px + 1)) {
        oklist.push_back(Right);
    }
    if (movalid(py, px - 1)) {
        oklist.push_back(Left);
    }
    if (movalid(py + 1, px)) {
        oklist.push_back(Down);
    }
    if (movalid(py - 1, px)) {
        oklist.push_back(Up);
    }
    dir = oklist.at(QRandomGenerator::global()->generate() % oklist.size());
}



void Ghost::move()
{
    if (status == Blue) {
        blue_time--;
        if (blue_time <= 0) {
            status = Normal;
            juego->ghost_timer[color]->setInterval(interv_normal);
        }
    }

    int gh_x = static_cast<int>(x());
    int gh_y = static_cast<int>(y());
    int psx = (gh_x - juego->geo_x) / W;
    int psy = (gh_y - juego->geo_y) / W;
    int x_tmp = (gh_x - juego->geo_x) % W;
    int y_tmp = (gh_y - juego->geo_y) % W;
    if (x_tmp == 0 &&  y_tmp == 0) {
        px = psx;
        py = psy;

            if (is_released) {
                randomdir();
            }
    }

    switch (dir) {
    case Stop:
        break;
    case Up:
        moveup();
        break;
    case Down:
        movedown();
        break;
    case Left:
        moveleft();
        break;
    case Right:
        moveright();
        break;
    }

    if (collidesWithItem(juego->pacman, Qt::IntersectsItemShape)){
        if (status == Normal) {
            juego->stat = Juego::Lose;
        } else if (status == Blue) {
            juego->score += score;
            status = Run;
            juego->ghost_timer[color]->setInterval(interv_run);

        }
    }
}

