// Clase Ladrillo
#include "Ladrillo2.h"
#include <iostream>
#include "bola.h"

using std::cout;

// El constructor carga la imagen del ladrillo e inicializa el flag de la variable bool.
Ladrillo2::Ladrillo2(int x,int y) {

  image.load(":image/bloque2.png");
  destroyed = false;
  n = 0;
  rect = image.rect();
  rect.translate(x, y);
}

Ladrillo2::~Ladrillo2() {

  //std::cout << ("Ladrillo eliminado") << std::endl;
}

QRect Ladrillo2::getRect() {

  return rect;
}

void Ladrillo2::setRect(QRect rct) {

  rect = rct;
}

QImage & Ladrillo2::getImage() {

  return image;
}

// Con la ayuda del flag se sabrá si el ladrillo se dibuja o no.
bool Ladrillo2::isDestroyed() {
        return destroyed;
}

void Ladrillo2::setDestroyed(bool destr) {
    n += 1;
    //cout << n << "\n";
    if (n == 3)
        destroyed = destr;

}

