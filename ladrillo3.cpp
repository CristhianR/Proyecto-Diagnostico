// Clase Ladrillo
#include "ladrillo3.h"
#include <iostream>
#include "bola.h"

using std::cout;

// El constructor carga la imagen del ladrillo e inicializa el flag de la variable bool.
Ladrillo3::Ladrillo3(int x,int y) {

  image.load(":image/bloque3.png");
  destroyed = false;
  p = 0;
  rect = image.rect();
  rect.translate(x, y);
}

Ladrillo3::~Ladrillo3() {

  //std::cout << ("Ladrillo eliminado") << std::endl;
}

QRect Ladrillo3::getRect() {

  return rect;
}

void Ladrillo3::setRect(QRect rct) {

  rect = rct;
}

QImage & Ladrillo3::getImage() {

  return image;
}

// Con la ayuda del flag se sabrá si el ladrillo se dibuja o no.
bool Ladrillo3::isDestroyed() {
        return destroyed;
}

void Ladrillo3::setDestroyed(bool destr) {
    p += 1;
    //cout << p << "\n";
    if (p == 4)
        destroyed = destr;

}
