// Clase Ladrillo
#include "ladrilloI.h"
#include <iostream>
#include "bola.h"

using std::cout;

// El constructor carga la imagen del ladrillo e inicializa el flag de la variable bool.
LadrilloI::LadrilloI(int x,int y) {

  image.load(":image/bloqueI.png");
  destroyed = false;
  p = 0;
  rect = image.rect();
  rect.translate(x, y);
}

LadrilloI::~LadrilloI() {

  //std::cout << ("Ladrillo eliminado") << std::endl;
}

QRect LadrilloI::getRect() {

  return rect;
}

void LadrilloI::setRect(QRect rct) {

  rect = rct;
}

QImage & LadrilloI::getImage() {

  return image;
}

// Con la ayuda del flag se sabrá si el ladrillo se dibuja o no.
bool LadrilloI::isDestroyed() {
        return destroyed;
}

void LadrilloI::setDestroyed(bool destr) {
    if (p == 0)
        destroyed = destr;

}
