#include "barra2.h"
#include <iostream>
#include "breakout.h"
#include "bola.h"

using std::cout;

// La barra puede  moverse para la derecha o izquierda.

Barra2::Barra2() {

    // Se inicializa la variable dx y se pasa la imagen de la barra.
    dx = 0;
    image2.load(":image/barra.png");
    rect = image2.rect();
    resetState();
}

Barra2::~Barra2() {

 //std::cout << ("Barra eliminada") << std::cout;
}

void Barra2::setDx(int x) {
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
void Barra2::move() {

    int x = rect.x() + dx;
    int y = rect.top();

    rect.moveTo(x, y);
}



// Este otro es para inicializar la barra en la posición inicial.
void Barra2::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Barra2::outState(){
    rect.moveTo(OUT_X, OUT_Y);
}

QRect Barra2::getRect() {

  return rect;
}

QImage & Barra2::getImage() {
  return image2;
}

/*void Barra2::Spawn(){
    Bola *bola = new Bola();
}*/

