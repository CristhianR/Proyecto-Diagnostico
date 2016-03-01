
// Calse Ladrillo
#include "ladrillo.h"
#include <iostream>

// El constructor carga la imagen del ladrillo e inicializa el flag de la variable bool.
Ladrillo::Ladrillo(int x, int y) {

  image.load(":image/bloque1.png");
  destroyed = false;
  rect = image.rect();
  rect.translate(x, y);
}

Ladrillo::~Ladrillo() {

  //std::cout << ("Ladrillo eliminado") << std::endl;
}

QRect Ladrillo::getRect() {

  return rect;
}

void Ladrillo::setRect(QRect rct) {

  rect = rct;
}

QImage & Ladrillo::getImage() {

  return image;
}

// Con la ayuda del flag se sabrá si el ladrillo se dibuja o no.
bool Ladrillo::isDestroyed() {

  return destroyed;
}

void Ladrillo::setDestroyed(bool destr) {

  destroyed = destr;
}
