// Clase Bola
#include "bola.h"
#include <iostream>
#include <QTimer>

using std::cout;


Bola::Bola() {
    // Al inicio la bola se mueve al noreste
  xdir = 1;
  ydir = -1;
  n = 0;
  m = 0;

  image.load(":image/ball.png");

  rect = image.rect();
  resetState();
}

Bola::~Bola() {

  //std::cout << ("Bola eliminada") << std::endl;
}

/*
 * Este método comprueba si la bola pega con la paredes.
 * Si lo hace, cambia de dirección.
 * Además si se va abajo, pierde el juego.
 */
void Bola::autoMove() {

  rect.translate(xdir, ydir);
    //cout << n << " + " << m << "\n";
    if (n == 0 && m == 0){
        if (rect.left() <= 0) {
            xdir = 1;
      }
        if (rect.right() >= 610) {
            xdir = -1;
      }
        if (rect.top() == 0) {
            ydir = 1;
      }
    }
    else
    {
        if (rect.left() <= 0) {
          xdir = 2;
        }

        if (rect.right() >= 610) {
          xdir = -2;
        }

        if (rect.top() <= 0) {
          ydir = 2;
        }
   }



}

void Bola::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Bola::setXDir(double x) {
    //cout << x << "\n";
    if (x > 1 || x < -1){
        n = 1;
        xdir = x;
    } else
    n =0;
    xdir = x;
}

void Bola::setYDir(double y) {

    if (y > 1 || y < -1){
       m = 1;
       ydir = y;
    } else
        m = 0;
        ydir = y;
}

double Bola::getXDir() {
  return xdir;
}

double Bola::getYDir() {

  return ydir;
}

QRect Bola::getRect() {

  return rect;
}

QImage & Bola::getImage() {

  return image;
}
