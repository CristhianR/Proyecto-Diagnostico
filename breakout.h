// Archivo de encabezado para la clase del juego (Breakout).
#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "bola.h"
#include "ladrillo.h"
#include "Ladrillo2.h"
#include "ladrillo3.h"
#include "ladrilloI.h"
#include "ladrilloP.h"
#include "barra.h"
#include "barra2.h"
#include "puntuacion.h"
#include <QObject>

class Breakout : public QWidget {

  Q_OBJECT

  public:

    Breakout(QWidget *parent = 0);
    ~Breakout();

    QGraphicsScene  * scene;


  protected:

    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

    // La barra es controlada por la flecha en la compu.
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *, QString, QString,QString);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();


  private:
    // Estas dos variables sirven para guardar la posición de la barra y saber cuando el juego esta pausado.
    int x;
    int timerId;
    double puntos;
    bool f;
    int ran;
    int np;
    bool profundidad;
    bool power;
    bool p2;
    bool p3;

    static const int N_DE_LADRILLOS1 = 30; // Esta constante guarda el numero de ladrillos.
    static const int N_DE_LADRILLOS2 = 30;
    static const int N_DE_LADRILLOS3 = 15;
    static const int N_DE_LADRILLOSI = 15;
    static const int N_DE_LADRILLOSP = 10 ;
    static const int DELAY = 10; // Esta constante controla la velocidad del juego.
    static const int BOTTOM_EDGE = 400; // Esta es para saber cuando la bola sale de la pantalla.

    // Basicamente el juego tiene: Una bola, una barra y unos arreglos de ladrillos.
    Bola *bola;
    Bola *bola1;
    Barra *barra;
    Barra2 *barra2;
    Ladrillo *ladrillos1[N_DE_LADRILLOS1];
    Ladrillo2 *ladrillos2[N_DE_LADRILLOS2];
    Ladrillo3 *ladrillos3[N_DE_LADRILLOS3];
    LadrilloI *ladrillosI[N_DE_LADRILLOSI];
    LadrilloP *ladrillosP[N_DE_LADRILLOSP];
    Puntaje *puntaje;
    QTimer * timer;
    //int n = ladrillos1 + ladrillos2;
    // Finalmente estos son para controlar el estado del juego.
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};
