#include "juego.h"
#include <QString>
#include <QFile>
#include <QRandomGenerator>
#define W (Objetos::Width)

Juego::Juego(int x, int y, int mw, int mh, QString map_src)
    : QGraphicsScene(x, y, W * mw, W * mh)
{
    geo_x = x;
    geo_y = y;
    stat = Playing;

    map_s = mw * mh;
    map_w = mw;
    map_h = mh;
    map = new Objetos**[map_h];
    for (int i = 0; i < map_h; i++) {
        map[i] = new Objetos*[map_w];
        for (int j = 0; j < map_w; j++)
            map[i][j] = nullptr;
    }

    ball_num = eat_num = score = 0;
    int ghost_i = 0;
    QPixmap wallpix(":/pacman/wall.png");
    QPixmap ballpix(":/pacman/dot.png");
    QPixmap powerballpix(":/pacman/power_ball.png");
    QPixmap blankpix;
    QFile mapfile(map_src);
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);

    pacman = new Pacman();

    for (int i = 0; i < map_h; i++) {
        QByteArray line = mapfile.readLine();
        for (int j = 0; j < map_w; j++) {
            int tmp_x = x + (j * W);
            int tmp_y = y + (i * W);
            switch (line[j]) {
            case '1':
                map[i][j] = new Objetos(Objetos::Wall, wallpix);
                map[i][j]->setPos(tmp_x, tmp_y);
                addItem(map[i][j]);
                break;
            case '0':
                map[i][j] = new Objetos(Objetos::Ball, ballpix);
                map[i][j]->set_score(punt_ball);
                map[i][j]->setPos(tmp_x, tmp_y);
                addItem(map[i][j]);
                ball_num++;
                break;
            case '3':
                map[i][j] = new Objetos(Objetos::Blank, blankpix);
                break;
            case '4':
                map[i][j] = new Objetos(Objetos::PowerBall, powerballpix);
                map[i][j]->set_score(punt_powerball);
                map[i][j]->setPos(tmp_x, tmp_y);
                addItem(map[i][j]);
                powerball.push_back(map[i][j]);
                ball_num++;
                break;
            case 'p':
                pacman = new Pacman();
                pacman->juego = this;
                pacman->setZValue(2);
                pacman->setPos(tmp_x, tmp_y);
                addItem(pacman);
                map[i][j] = pacman;
                break;
            case 'g':
                map[i][j] = new Objetos(Objetos::Blank, blankpix);
                ghost[ghost_i] = new Ghost(ghost_i);
                ghost[ghost_i]->juego = this;
                ghost[ghost_i]->setZValue(2);
                ghost[ghost_i]->px = j;
                ghost[ghost_i]->py = i;
                ghost[ghost_i]->set_score(punt_ghost);
                ghost[ghost_i]->setPos(tmp_x, tmp_y);
                addItem(ghost[ghost_i]);
                ghost_i++;
                break;
            }
            if (map[i][j]) {
                map[i][j]->px = j;
                map[i][j]->py = i;
            }
        }
    }

}


void Juego::start()
{
    powerball_flash_timer = new QTimer(this);
    connect(powerball_flash_timer, SIGNAL(timeout()), this , SLOT(powerball_flash()));
    powerball_flash_timer->start(interv_flash);

    pacman_timer = new QTimer(this);
    connect(pacman_timer, SIGNAL(timeout()), this , SLOT(pacman_mv()));
    pacman_timer->start(interv);

    for (int i = 0; i < Ghost::GhostNum; i++) {
        ghost_timer[i] = new QTimer(this);
        connect(ghost_timer[i], &QTimer::timeout, [=](){ghost_mv(i);} );
        ghost_timer[i]->start(interv_normal);
    }
}


void Juego::stop()
{
    pacman_timer->stop();
    powerball_flash_timer->stop();
    for (int i = 0; i < Ghost::GhostNum; i++) {
        ghost_timer[i]->stop();
    }
}


void Juego::powerball_flash()
{
    if (powerball.empty()) {
        powerball_flash_timer->stop();
        return;
    }

    if (flash) {
        for (int i = 0; i < powerball.size(); i++) {
            powerball.at(i)->hide();
        }
        flash = 0;
    } else {
        for (int i = 0; i < powerball.size(); i++) {
            powerball.at(i)->show();
        }
        flash = 1;
    }
}

void Juego::pacman_mv()
{
    pacman->move();
    if (stat == Win) {
        stop();
    }
}


void Juego::ghost_mv(int ghost_id)
{
    ghost[ghost_id]->move();
    if (stat == Lose) {
        stop();
    }
}


void Juego::pacman_next(Objetos::Dir d)
{
    pacman->set_next_dir(d);
}

int Juego::get_score()
{
    return score;
}

Juego::~Juego()
{
    for (int i = 0; i < map_h; i++) {
        for (int j = 0; j < map_w; j++) {
            if (map[i][j] != nullptr)
                delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
    delete pacman_timer;
    delete powerball_flash_timer;
    for (int i = 0; i < Ghost::GhostNum; i++) {
        delete ghost_timer[i];
    }
}
