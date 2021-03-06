// Archivo de encabezado para la clase Ladrillo.

#pragma once

#include <QImage>
#include <QRect>
#include "bola.h"

class Ladrillo2 {

  public:
    Ladrillo2(int, int);
    ~Ladrillo2();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();


  private:
    QImage image;
    QRect rect;
    int n;
    // Esta variable es para saber si un ladrillo fue destruido.
    bool destroyed;
};
