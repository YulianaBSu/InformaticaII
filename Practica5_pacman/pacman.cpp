#include "juego.h"
#define W (Objetos::Width)

Pacman::Pacman() : Objetos(
    Objetos::Pacman, QPixmap(":/pacman/a1.png"))
{
    dir = Stop;
    //next_dir = Stop;
    mov_index = 2;
    mov[Right].push_back(QPixmap(":/pacman/a1.png"));
    mov[Right].push_back(QPixmap(":/pacman/a2.png"));
    mov[Right].push_back(QPixmap(":/pacman/a3.png"));
    mov[Right].push_back(QPixmap(":/pacman/a4.png"));
    mov[Right].push_back(QPixmap(":/pacman/a5.png"));
    mov[Right].push_back(QPixmap(":/pacman/a6.png"));

    mov[Up].push_back(QPixmap(":/pacman/a1.png"));
    mov[Up].push_back(QPixmap(":/pacman/b2.png"));
    mov[Up].push_back(QPixmap(":/pacman/b3.png"));
    mov[Up].push_back(QPixmap(":/pacman/b4.png"));
    mov[Up].push_back(QPixmap(":/pacman/b5.png"));
    mov[Up].push_back(QPixmap(":/pacman/b6.png"));

    mov[Left].push_back(QPixmap(":/pacman/a1.png"));
    mov[Left].push_back(QPixmap(":/pacman/c2.png"));
    mov[Left].push_back(QPixmap(":/pacman/c3.png"));
    mov[Left].push_back(QPixmap(":/pacman/c4.png"));
    mov[Left].push_back(QPixmap(":/pacman/c5.png"));
    mov[Left].push_back(QPixmap(":/pacman/c6.png"));

    mov[Down].push_back(QPixmap(":/pacman/a1.png"));
    mov[Down].push_back(QPixmap(":/pacman/d2.png"));
    mov[Down].push_back(QPixmap(":/pacman/d3.png"));
    mov[Down].push_back(QPixmap(":/pacman/d4.png"));
    mov[Down].push_back(QPixmap(":/pacman/d5.png"));
    mov[Down].push_back(QPixmap(":/pacman/d6.png"));
}

void Pacman::moveup()
{
    mov_index++;
    if (mov_index == mov[Up].size()) {
        mov_index = 0;
    }
    setPixmap(mov[Up][mov_index]);
    setY(static_cast<int>(y()) - 1);
}


void Pacman::movedown()
{
    mov_index++;
    if (mov_index == mov[Down].size()) {
        mov_index = 0;
    }
    setPixmap(mov[Down][mov_index]);
    setY(static_cast<int>(y()) + 1);
}

void Pacman::moveleft()
{
    mov_index++;
    if (mov_index == mov[Left].size()) {
        mov_index = 0;
    }
    setPixmap(mov[Left][mov_index]);
    setX(static_cast<int>(x()) - 1);
}

void Pacman::moveright()
{
    mov_index++;
    if (mov_index == mov[Right].size()) {
        mov_index = 0;
    }
    setPixmap(mov[Right][mov_index]);
    setX(static_cast<int>(x()) + 1);
}


void Pacman::eat_ball(int psy, int psx)
{
    Objetos *obj = juego->map[psy][psx];
    switch (obj->get_type()) {
    case Ball:
        juego->score += obj->get_score();
        juego->ball_num--;
        break;
    case PowerBall:
        juego->score += obj->get_score();
        juego->ball_num--;
        juego->powerball.erase(std::remove(juego->powerball.begin(), juego->powerball.end(), obj), juego->powerball.end());
        for (int i = 0; i < Ghost::GhostNum; i++) {
            if (juego->ghost[i]->status != Ghost::Run) {
                juego->ghost[i]->status = Ghost::Blue;
                juego->ghost[i]->blue_time = blue_timer;
                juego->ghost_timer[i]->setInterval(interv_blue);
            }
        }
        break;
    default:
        return;
    }

    QPixmap blankpix;
    juego->map[py][px] = new Objetos(Objetos::Blank, blankpix);
    juego->map[psy][psx] = this;
    delete obj;
}


bool Pacman::movalid(int i, int j)
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


void Pacman::move()
{
    int pac_x = static_cast<int>(x());
    int pac_y = static_cast<int>(y());
    int psx = (pac_x - juego->geo_x) / W;
    int psy = (pac_y - juego->geo_y) / W;
    int x_tmp = (pac_x - juego->geo_x) % W;
    int y_tmp = (pac_y - juego->geo_y) % W;
    Dir next_dir = get_next_dir();
    if (x_tmp == 0) {
        if (y_tmp == 0) {
            eat_ball(psy, psx);
            px = psx;
            py = psy;

            if (juego->ball_num == 0) {
                juego->stat = Juego::Win;
                return;
            }
        }

        switch (next_dir) {
        case Stop:
            dir = next_dir;
            break;
        case Up:
            if (movalid(py - 1, px)) {
                dir = next_dir;
            }
            break;
        case Down:
            if (movalid(py + 1, px)) {
                dir = next_dir;
            }
            break;
        case Left:
            if (y_tmp == 0 && movalid(py, px - 1)) {
                dir = next_dir;
            }
            break;
        case Right:
            if (y_tmp == 0 && movalid(py, px + 1)) {
                dir = next_dir;
            }
            break;
        }
    } else if (y_tmp == 0) {
        switch (next_dir) {
        case Stop:
            dir = next_dir;
            break;
        case Left:
            if (movalid(py, px - 1)) {
                dir = next_dir;
            }
            break;
        case Right:
            if (movalid(py, px + 1)) {
                dir = next_dir;
            }
            break;
        default:
            break;
        }
    }

    switch (dir) {
    case Stop:
        break;
    case Up:
        if (y_tmp == 0 && !movalid(py - 1, px)) {
            dir = Stop;
        } else {
            moveup();
        }
        break;
    case Down:
        if (y_tmp == 0 && !movalid(py + 1, px)) {
            dir = Stop;
        } else {
            movedown();
        }
        break;
    case Left:
        if (x_tmp == 0 && !movalid(py, px - 1)) {
            dir = Stop;
        } else {
            moveleft();
        }
        break;
    case Right:
        if (x_tmp == 0 && !movalid(py, px + 1)) {
            dir = Stop;
        } else {
            moveright();
        }
        break;
    }
}
