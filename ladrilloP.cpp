// Clase Ladrillo
#include "ladrilloP.h"
#include <iostream>
#include "bola.h"

using std::cout;

// El constructor carga la imagen del ladrillo e inicializa el flag de la variable bool.
LadrilloP::LadrilloP(int x,int y) {

  image.load(":image/brickieP.png");
  destroyed = false;
  flag = false;
  rect = image.rect();
  rect.translate(x, y);
}

LadrilloP::~LadrilloP() {

  //std::cout << ("Ladrillo eliminado") << std::endl;
}

QRect LadrilloP::getRect() {

  return rect;
}

void LadrilloP::setRect(QRect rct) {

  rect = rct;
}

QImage & LadrilloP::getImage() {

  return image;
}

// Con la ayuda del flag se sabrá si el ladrillo se dibuja o no.
bool LadrilloP::isDestroyed() {
        return destroyed;
}

void LadrilloP::setDestroyed(bool destr) {
    //if (flag == true)
        destroyed = destr;

}
