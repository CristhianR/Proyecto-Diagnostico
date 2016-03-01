// Archivo de encabezado para la clase Ladrillo.

#pragma once

#include <QImage>
#include <QRect>
#include "bola.h"

class LadrilloI {

  public:
    LadrilloI(int, int);
    ~LadrilloI();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();


  private:
    QImage image;
    QRect rect;
    int p;
    // Esta variable es para saber si un ladrillo fue destruido.
    bool destroyed;
};
