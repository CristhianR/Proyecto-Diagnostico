// Clase del Juego (Breakout). Pos acá está la lógica del juego.

#include <QPainter>
#include <QTimer>
#include <QApplication>
#include <QGraphicsTextItem>
#include "breakout.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QObject>
#include <stdlib.h>


using std::cout;
using std::endl;

Breakout::Breakout(QWidget *parent)
    : QWidget(parent) {

  x = 0;
  f = false;
  np = 0;
  p2 = false;
  p3 = false;
  puntos = 0;
  power = false;
  profundidad = false;
  gameOver = false;
  gameWon = false;
  paused = false;
  gameStarted = false;
  bola = new Bola();
  barra = new Barra();
  barra2 = new Barra2();

  /*timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),barra2,SLOT(Spawn()));
  timer->start(5000);*/

  // Se inicializan 30 ladrillos en el juego.
  int k = 0;

  for (int i=0; i<2; i++) {
    for (int j=0; j<15; j++) {
      ladrillos1[k] = new Ladrillo(j*40+5, i*12+122);
      k++;
    }
  }
  int l = 0;

  for (int i=0; i<2; i++) {
    for (int j=0; j<15; j++) {
      ladrillos2[l] = new Ladrillo2(j*40+5, i*12+98);
      l++;
    }
  }
  int m = 0;

  for (int i=0; i<1; i++) {
    for (int j=0; j<15; j++) {
      ladrillos3[m] = new Ladrillo3(j*40+5, i*12+86);
      m++;
    }
  }

  int r = 0;

  for (int i=0; i<1; i++) {
    for (int j=0; j<15; j++) {
      ladrillosI[r] = new LadrilloI(j*40+5, i*12+74);
      r++;
    }
  }

  int q = 0;

  for (int i=0; i<2; i++) {
    for (int j=0; j<5; j++) {
        ran = ( 1 + rand() % 100 );
      ladrillosP[q] = new LadrilloP(10 + rand() % 500,150 + rand() % 20);
      q++;
    }
  }
}


Breakout::~Breakout() {

 delete bola;
 delete barra;
 delete barra2;

 for (int i=0; i<N_DE_LADRILLOS1; i++) {
   delete ladrillos1[i];
 }
 for (int i=0; i<N_DE_LADRILLOS2; i++) {
   delete ladrillos2[i];
 }
 for (int i=0; i<N_DE_LADRILLOS3; i++) {
   delete ladrillos3[i];
 }
 for (int i=0; i<N_DE_LADRILLOSI; i++) {
   delete ladrillosI[i];
 }
 for (int i=0; i<N_DE_LADRILLOSP; i++) {
   delete ladrillosP[i];
 }
}

/*
 * Este método sirve para imprimir el estado del juego.
 * Dependiendo de la variables booleanas declaradas en el archivo de esncabezado.
 */
void Breakout::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QPainter painter(this);

  if (gameOver) {

    finishGame(&painter, "Game lost");

  } else if(gameWon) {

    finishGame(&painter, "Victory");
  }
  else {

    drawObjects(&painter, "Puntaje: ", "Nivel Profundidad: ", "Poder: " );
  }
}

// Este el método para saber como termina el juego, si perdió o ganó.
void Breakout::finishGame(QPainter *painter, QString message) {

  QFont font("Courier", 15, QFont::DemiBold);
  QFontMetrics fm(font);
  int textWidth = fm.width(message);

  painter->setFont(font);
  int h = height();
  int w = width();

  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2, 0, message);
}

// Este método pinta los objetos en la pantalla y pasa las imagenes correspondientes.
void Breakout::drawObjects(QPainter *painter, QString puntuacion, QString nvProf, QString poder) {

    painter->drawImage(bola->getRect(), bola->getImage());
    /*if (power == true){
        bola1 = new Bola();
        timer->start(5000);
        painter->drawImage(bola1->getRect(), bola1->getImage());*/




  if (puntos < 20){
      painter->drawImage(barra->getRect(), barra->getImage());
      barra2->outState();
      f = true;
  }

  if (puntos == 20 && f == true){
      barra2->resetState();
      f = false;
  }

  QFont font("Courier", 15, QFont::DemiBold);
  QFontMetrics fm(font);
  if(puntos >= 20){
      painter->drawImage(barra2->getRect(), barra2->getImage());
      barra->outState();

  }
  QString s = QString::number(puntos);
  puntuacion += s;

  QString g = QString::number(np);
  nvProf += g;

  if(power == true){
      poder += "Activado";
  } else
      poder += "Desactivado";


  painter->drawText(20, 20, puntuacion);
  painter->drawText(200,20,nvProf);
  painter->drawText(400,20,poder);

  for (int i=0; i<N_DE_LADRILLOS1; i++) {
    if (!ladrillos1[i]->isDestroyed()) {
      painter->drawImage(ladrillos1[i]->getRect(), ladrillos1[i]->getImage());
    }
  }
  for (int i=0; i<N_DE_LADRILLOS2; i++) {
    if (!ladrillos2[i]->isDestroyed()) {
      painter->drawImage(ladrillos2[i]->getRect(), ladrillos2[i]->getImage());
    }
  }
  for (int i=0; i<N_DE_LADRILLOS3; i++) {
    if (!ladrillos3[i]->isDestroyed()) {
      painter->drawImage(ladrillos3[i]->getRect(), ladrillos3[i]->getImage());
    }
  }
  for (int i=0; i<N_DE_LADRILLOSI; i++) {
    if (!ladrillosI[i]->isDestroyed()) {
      painter->drawImage(ladrillosI[i]->getRect(), ladrillosI[i]->getImage());
    }
  }
  for (int i=0; i<N_DE_LADRILLOSP; i++) {
    if (gameOver == false) {
      painter->drawImage(ladrillosP[i]->getRect(), ladrillosP[i]->getImage());
    }
  }
}


// Acá movemos los objetos (repintando) y comprobamos los choques.
void Breakout::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);

  moveObjects();
  checkCollision();
  repaint();
}

// Este el método para mover los dos objetos.
void Breakout::moveObjects() {

  bola->autoMove();

  if (puntos >= 20){
    barra2->move();
} else
    barra->move();
}

// Si el usuario suelta la flecha, la barra para, esto se hace asignado 0 a la variable de control dx.
void Breakout::keyReleaseEvent(QKeyEvent *e) {

    int dx = 0;

    if (puntos < 20){
    switch (e->key()) {
        case Qt::Key_Left:
            dx = 0;
            barra->setDx(dx);
            break;

        case Qt::Key_Right:
            dx = 0;
            barra->setDx(dx);
            break;
    }
}
    if (puntos >= 20){
    switch (e->key()) {
        case Qt::Key_Left:
            dx = 0;
            barra2->setDx(dx);
            break;

        case Qt::Key_Right:
            dx = 0;
            barra2->setDx(dx);
            break;
    }
  }
}

/*
 * Este método es el encargado de saber los eventos del teclado; se enlistan aquí.
 * Si presiona las flechas se movera o hacia la izquierda o hacia la derecha.
 * Si pulsa P  pausara el juego, si lo vuelve a pulsar lo despausará.
 * Con la tecla SPACE el juego.
 * Finalmente con ESC saldrá del juego.
 */
void Breakout::keyPressEvent(QKeyEvent *e) {

    int dx = 0;

    if (puntos < 20){
        switch (e->key()) {
            case Qt::Key_Left:
                    dx = -2;
                    barra->setDx(dx);

                    break;

            case Qt::Key_Right:

                dx = 2;
                barra->setDx(dx);
                break;

            case Qt::Key_P:

                pauseGame();
                break;

            case Qt::Key_Space:

                startGame();
                break;

            case Qt::Key_T:
                    if (np > 0){
                       power = true;
                    }
                    break;
            case Qt::Key_D:
                np = 0;
                break;

            case Qt::Key_Escape:

                qApp->exit();
                break;

        default:
            QWidget::keyPressEvent(e);
    }
}
    if (puntos >= 20){
        switch (e->key()) {

            case Qt::Key_Left:
                    dx = -3;
                    barra2->setDx(dx);

                    break;

            case Qt::Key_Right:

                dx = 3;
                barra2->setDx(dx);
                break;

            case Qt::Key_P:

                pauseGame();
                break;

            case Qt::Key_Space:

                startGame();
                break;

            case Qt::Key_T:
                if (np > 0){
                   power = true;
                }

                break;

            case Qt::Key_D:
                np = 0;
                power = false;
                break;


            case Qt::Key_Escape:

                qApp->exit();
                break;

    default:
        QWidget::keyPressEvent(e);

    }
    }

  }


// Este método se encarga de empezar la partida.
void Breakout::startGame() {

  if (!gameStarted) {
    bola->resetState();
    barra->resetState();

    for (int i=0; i<N_DE_LADRILLOS1; i++) {
      ladrillos1[i]->setDestroyed(false);
    }
    for (int i=0; i<N_DE_LADRILLOS2; i++) {
      ladrillos2[i]->setDestroyed(false);
    }
    for (int i=0; i<N_DE_LADRILLOS3; i++) {
      ladrillos3[i]->setDestroyed(false);
    }
    for (int i=0; i<N_DE_LADRILLOSI; i++) {
      ladrillosI[i]->setDestroyed(false);
    }

    gameOver = false;
    gameWon = false;
    gameStarted = true;
    timerId = startTimer(DELAY);
  }
}

// Método para pausar el juego y guardar el tiempo.
void Breakout::pauseGame() {

  if (paused) {

    timerId = startTimer(DELAY);
    paused = false;
  } else {

    paused = true;
    killTimer(timerId);
  }
}

// Método para terminar el juego, colocando las respectivas banderas.
void Breakout::stopGame() {

  killTimer(timerId);
  gameOver = true;
  gameStarted = false;
}

void Breakout::victory() {

  killTimer(timerId);
  gameWon = true;
  gameStarted = false;
}

// Este método detecta las colisiones, si la bola cae el juego acaba.
void Breakout::checkCollision() {

    bool f1 = false;
    bool f2 = false;
    bool f3 = false;
    bool f4 = false;
  if (bola->getRect().bottom() > BOTTOM_EDGE) {
    stopGame();
  }

  // se revisa si todos los ladrillos fueron destruidos; si lo están se gana el juego.
  for (int i=0, j=0; i<N_DE_LADRILLOS1; i++) {


    if (ladrillos1[i]->isDestroyed()) {
      j++;
    }

    if (j == N_DE_LADRILLOS1) {
      //victory();
        f1 = true;
    }
  }

  for (int i=0, j=0; i<N_DE_LADRILLOS2; i++) {

    if (ladrillos2[i]->isDestroyed()) {
      j++;
    }

    if (j == N_DE_LADRILLOS2){
      //victory();
        f2 = true;
    }
  }

  for (int i=0, j=0; i<N_DE_LADRILLOS3; i++) {

    if (ladrillos3[i]->isDestroyed()) {
      j++;
    }

    if (j == N_DE_LADRILLOS3){
      //victory();
        f3 = true;
    }
  }

  for (int i=0, j=0; i<N_DE_LADRILLOSI; i++) {

    if (ladrillosI[i]->isDestroyed()) {
      j++;
    }

    if (j == N_DE_LADRILLOSI){
      //victory();
        f4 = true;
    }
  }

  if (f1 == true && f2 == true && f3 == true && f4 == true){
      victory();
  }



  if ((bola->getRect()).intersects(barra->getRect())) {

    int barraLPos = barra->getRect().left();
    int bolaLPos = bola->getRect().left();

    int first = barraLPos + 8;
    int second = barraLPos + 16;
    int third = barraLPos + 24;
    int fourth = barraLPos + 32;

    // dependiendo de donde pegue la bola, cambiara de dirección (noroeste) y la velocidad.
    if (bolaLPos < first) {
      bola->setXDir(-1);
      bola->setYDir(-1);
    }

    if (bolaLPos >= first && bolaLPos < second) {
      bola->setXDir(-1);
      bola->setYDir(-1*bola->getYDir());
    }

    if (bolaLPos >= second && bolaLPos < third) {
       bola->setXDir(0);
       bola->setYDir(-1);
    }

    if (bolaLPos >= third && bolaLPos < fourth) {
       bola->setXDir(1);
       bola->setYDir(-1*bola->getYDir());
    }

    if (bolaLPos > fourth) {
      bola->setXDir(1);
      bola->setYDir(-1);
    }
  }

  if ((bola->getRect()).intersects(barra2->getRect())) {

    int barraLPos2 = barra2->getRect().left();
    int bolaLPos = bola->getRect().left();

    int first = barraLPos2 + 8;
    int second = barraLPos2 + 16;
    int third = barraLPos2 + 24;
    int fourth = barraLPos2 + 32;

    // dependiendo de donde pegue la bola, cambiara de dirección (noroeste) y la velocidad.
    if (bolaLPos < first) {
      bola->setXDir(-1);
      bola->setYDir(-1);
    }

    if (bolaLPos >= first && bolaLPos < second) {
      bola->setXDir(-1);
      bola->setYDir(-1*bola->getYDir());
    }

    if (bolaLPos >= second && bolaLPos < third) {
       bola->setXDir(0);
       bola->setYDir(-1);
    }

    if (bolaLPos >= third && bolaLPos < fourth) {
       bola->setXDir(1);
       bola->setYDir(-1*bola->getYDir());
    }

    if (bolaLPos > fourth) {
      bola->setXDir(1);
      bola->setYDir(-1);
    }
  }


  for (int i=0; i<N_DE_LADRILLOS1; i++) {

    if ((bola->getRect()).intersects(ladrillos1[i]->getRect())) {

      int bolaLeft = bola->getRect().left();
      int bolaHeight = bola->getRect().height();
      int bolaWidth = bola->getRect().width();
      int bolaTop = bola->getRect().top();

      QPoint pointRight(bolaLeft + bolaWidth + 1, bolaTop);
      QPoint pointLeft(bolaLeft - 1, bolaTop);
      QPoint pointTop(bolaLeft, bolaTop -1);
      QPoint pointBottom(bolaLeft, bolaTop + bolaHeight + 1);

      if (!ladrillos1[i]->isDestroyed() && power == false) {
        // Si la pelota golpea los ladrillos se viene para abajo.
        if(ladrillos1[i]->getRect().contains(pointRight)) {
           bola->setXDir(-1);
        }

        else if(ladrillos1[i]->getRect().contains(pointLeft)) {
           bola->setXDir(1);
        }

        if(ladrillos1[i]->getRect().contains(pointTop)) {
           bola->setYDir(1);
        }

        else if(ladrillos1[i]->getRect().contains(pointBottom)) {
           bola->setYDir(-1);
        }

            ladrillos1[i]->setDestroyed(true);
            puntos += 10;


      } if (np == 0){
          power = false;
      }
    }
  }

  for (int i=0; i<N_DE_LADRILLOS2; i++) {

    if ((bola->getRect()).intersects(ladrillos2[i]->getRect())) {

      double bolaLeft = bola->getRect().left();
      double bolaHeight = bola->getRect().height();
      double bolaWidth = bola->getRect().width();
      double bolaTop = bola->getRect().top();


      QPoint pointRight(bolaLeft + bolaWidth + 2, bolaTop);
      QPoint pointLeft(bolaLeft - 2, bolaTop);
      QPoint pointTop(bolaLeft, bolaTop -2);
      QPoint pointBottom(bolaLeft, bolaTop + bolaHeight + 2);

      if (!ladrillos2[i]->isDestroyed() && p2 == false) {
        // Si la pelota golpea los ladrillos se viene para abajo.
        if(ladrillos2[i]->getRect().contains(pointRight)) {
           //toco;
           bola->setXDir(-2);
        }

        else if(ladrillos2[i]->getRect().contains(pointLeft)) {
            //toco;
           bola->setXDir(2);
        }

        if(ladrillos2[i]->getRect().contains(pointTop)) {
            //toco;
           bola->setYDir(2);
        }

        else if(ladrillos2[i]->getRect().contains(pointBottom)) {
            //toco;
           bola->setYDir(-2);
        }

            ladrillos2[i]->setDestroyed(true);
                if (power == true && np < 2){
                    np -= 1;
                    if (np <= 0){
                        np = 0;
                    }

                } if (power == true && np >=2){
                    p2 = true;
                }

            if (ladrillos2[i]->isDestroyed()){
                puntos += 15;

            }

      } if (np < 2){
          p2 = false;
      }
    }
   }

  for (int i=0; i<N_DE_LADRILLOS3; i++) {

    if ((bola->getRect()).intersects(ladrillos3[i]->getRect())) {

      double bolaLeft = bola->getRect().left();
      double bolaHeight = bola->getRect().height();
      double bolaWidth = bola->getRect().width();
      double bolaTop = bola->getRect().top();


      QPoint pointRight(bolaLeft + bolaWidth + 2, bolaTop);
      QPoint pointLeft(bolaLeft - 2, bolaTop);
      QPoint pointTop(bolaLeft, bolaTop -2);
      QPoint pointBottom(bolaLeft, bolaTop + bolaHeight + 2);

      if (!ladrillos3[i]->isDestroyed() && p3 == false) {
        // Si la pelota golpea los ladrillos se viene para abajo.
        if(ladrillos3[i]->getRect().contains(pointRight)) {
           //toco;
           bola->setXDir(-2);
        }

        else if(ladrillos3[i]->getRect().contains(pointLeft)) {
            //toco;
           bola->setXDir(2);
        }

        if(ladrillos3[i]->getRect().contains(pointTop)) {
            //toco;
           bola->setYDir(2);
        }

        else if(ladrillos3[i]->getRect().contains(pointBottom)) {
            //toco;
           bola->setYDir(-2);
        }

            ladrillos3[i]->setDestroyed(true);
            if (power == true && np > 1 && np < 3){
                np -= 1;
                if (np <= 0)
                    np = 0;

            } if (np >= 3 && power == true){
                p3 = true;

            }


            if (ladrillos3[i]->isDestroyed()){
                puntos += 12;
            }

      } if (np < 3){
          p3 = false;
      }
    }
  }

  for (int i=0; i<N_DE_LADRILLOSI; i++) {

    if ((bola->getRect()).intersects(ladrillosI[i]->getRect())) {

      double bolaLeft = bola->getRect().left();
      double bolaHeight = bola->getRect().height();
      double bolaWidth = bola->getRect().width();
      double bolaTop = bola->getRect().top();


      QPoint pointRight(bolaLeft + bolaWidth + 2, bolaTop);
      QPoint pointLeft(bolaLeft - 2, bolaTop);
      QPoint pointTop(bolaLeft, bolaTop -2);
      QPoint pointBottom(bolaLeft, bolaTop + bolaHeight + 2);

      if (!ladrillosI[i]->isDestroyed()) {
        // Si la pelota golpea los ladrillos se viene para abajo.
        if(ladrillosI[i]->getRect().contains(pointRight)) {
           //toco;
           bola->setXDir(-2);
        }

        else if(ladrillosI[i]->getRect().contains(pointLeft)) {
            //toco;
           bola->setXDir(2);
        }

        if(ladrillosI[i]->getRect().contains(pointTop)) {
            //toco;
           bola->setYDir(2);
        }

        else if(ladrillosI[i]->getRect().contains(pointBottom)) {
            //toco;
           bola->setYDir(-2);
        }
            if(np >= 3 && power == true){
                ladrillosI[i]->setDestroyed(true);
                np -= 1;
                profundidad = false;
            }


            if (ladrillosI[i]->isDestroyed()){
                puntos += 30;
            }
      }
    }
  }

  for (int i=0; i<N_DE_LADRILLOSP; i++) {

    if ((bola->getRect()).intersects(ladrillosP[i]->getRect())) {

      double bolaLeft = bola->getRect().left();
      double bolaHeight = bola->getRect().height();
      double bolaWidth = bola->getRect().width();
      double bolaTop = bola->getRect().top();


      QPoint pointRight(bolaLeft + bolaWidth + 1, bolaTop);
      QPoint pointLeft(bolaLeft - 1, bolaTop);
      QPoint pointTop(bolaLeft, bolaTop -1);
      QPoint pointBottom(bolaLeft, bolaTop + bolaHeight + 1);

      if (!ladrillosP[i]->isDestroyed() || power == false) {
        // Si la pelota golpea los ladrillos se viene para abajo.
        if(ladrillosP[i]->getRect().contains(pointRight)) {
           //toco;
           bola->setXDir(-1);
        }

        else if(ladrillosP[i]->getRect().contains(pointLeft)) {
            //toco;
           bola->setXDir(1);
        }

        if(ladrillosP[i]->getRect().contains(pointTop)) {
            //toco;
           bola->setYDir(1);
        }

        else if(ladrillosP[i]->getRect().contains(pointBottom)) {
            //toco;
           bola->setYDir(-1);
        }
                ladrillosP[i]->setDestroyed(true);
                profundidad = true;
                np += 1;

            }
      }
    }
  }

