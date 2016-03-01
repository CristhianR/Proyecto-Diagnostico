// Archivo de encabezado para la clase Bola.
#pragma once

#include <QImage>
#include <QRect>
//#include "Ladrillo2.h"

class Bola {

  public:
    Bola();
    ~Bola();

  public:
    void resetState();
    void autoMove();
    void setXDir(double);
    void setYDir(double);
    double getXDir();
    double getYDir();
    QRect getRect();
    QImage & getImage();

  private:
    // Estas dos variables guardan la posición de la pelota.
    double xdir;
    double ydir;
    double n;
    double m;
    QImage image;
    QRect rect;
    static const int INITIAL_X = 230;
    static const int INITIAL_Y = 355;
    static const int RIGHT_EDGE = 300;
};
