// Archivo de encabezado para la clase Ladrillo.

#pragma once

#include <QImage>
#include <QRect>

class Ladrillo {

  public:
    Ladrillo(int, int);
    ~Ladrillo();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    // Esta variable es para saber si un ladrillo fue destruido.
    bool destroyed;
};
