
// Clase Barra
#include "barra.h"
#include <iostream>
#include "breakout.h"

using std::cout;

// La barra puede  moverse para la derecha o izquierda.

Barra::Barra() {

    // Se inicializa la variable dx y se pasa la imagen de la barra.
    dx = 0;
    image.load(":image/paddle.png");
    rect = image.rect();
    resetState();
}

Barra::~Barra() {

 //std::cout << ("Barra eliminada") << std::cout;
}

void Barra::setDx(int x) {
    if (rect.right() < 610 && rect.left() > 0 ){
        dx = x;
    }
    else
        {
            if(rect.right() >= 610){
                dx = -1;
                }
            else
                dx = 1;
        }
}

// Este método permite a la barra moverse y es controlado por la variable dx.
void Barra::move() {

    int x = rect.x() + dx;
    int y = rect.top();

    rect.moveTo(x, y);
}



// Este otro es para inicializar la barra en la posición inicial.
void Barra::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Barra::outState(){
    rect.moveTo(OUT_X, OUT_Y);
}

QRect Barra::getRect() {

  return rect;
}

QImage & Barra::getImage() {
  return image;
}
