
// Archivo de encabezado para el objeto Barra

#pragma once

#include <QImage>
#include <QRect>

class Barra {

  public:
    // Cosntructor y Destructor
    Barra ();
    ~Barra ();

  public:
    // Métodos públicos
    void resetState();
    void outState();
    void move();
    void stop();
    void setDx(int);
    QRect getRect();
    QImage & getImage();

  private:
    // Atributos privados
    QImage image;
    QImage image2;
    int t;

    QRect rect;
    int dx;
    // Constantes que representan la posición original de la barra
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 360;
    static const int OUT_X = -200;
    static const int OUT_Y = -360;

};
