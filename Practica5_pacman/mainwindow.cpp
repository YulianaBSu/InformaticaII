#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Pac-man"));

    ui->graphicsView->setStyleSheet("QGraphicsView {border: none;}");
    ui->graphicsView->setBackgroundBrush(Qt::black);

    int map_height = 21, map_width = 19, x = 50, y = 50;

    ui->graphicsView->setGeometry(x, y, map_width * Objetos::Width, map_height * Objetos::Width);
    juego = new Juego(x, y, map_width, map_height, ":/pacman/board.txt");
    ui->graphicsView->setScene(juego);
    initLabels();
    juego->start();
}


void MainWindow::initLabels()
{
    score_title = new QLabel(this);
    score_title->setText("SCORE");
    score_title->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score_title->setGeometry(50, 12, 60, 26);

    score = new QLabel(this);
    score->setIndent(-80);
    score->setText("0");
    score->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score->setGeometry(110, 12, 150, 26);

    win_label = new QLabel(this);
    win_label->hide();
    win_label->setText("Has ganado!");
    win_label->setStyleSheet("QLabel {font-family: Fixedsys;color: green;font-size: 16px;}");
    win_label->setGeometry(310, 12, 150, 26);

    lose_label = new QLabel(this);
    lose_label->hide();
    lose_label->setText("Has perdido!");
    lose_label->setStyleSheet("QLabel {font-family: Fixedsys;color: red;font-size: 16px;}");
    lose_label->setGeometry(310, 12, 150, 26);

    score_timer = new QTimer(this);
    score_timer->start(25);
    connect(score_timer, SIGNAL(timeout()), this , SLOT(update_score()));
}


void MainWindow::update_score()
{
    score->setText(QString::number(juego->get_score()));
    if (juego->stat == Juego::Win) {
        win_label->show();
        score_timer->stop();
    } else if (juego->stat == Juego::Lose) {
        lose_label->show();
        score_timer->stop();
    }
}


void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_S:
        juego->pacman_next(Objetos::Up);
        break;
    case Qt::Key_A:
        juego->pacman_next(Objetos::Left);
        break;
    case Qt::Key_D:
        juego->pacman_next(Objetos::Right);
        break;
    case Qt::Key_Z:
        juego->pacman_next(Objetos::Down);
        break;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

