// Archivo de encabezado para el objeto Barra

#pragma once

#include <QImage>
#include <QRect>
#include <QObject>

class Barra2 {
        //Q_OBJECT
  public:
    // Cosntructor y Destructor
    Barra2 ();
    ~Barra2 ();

public slots:
    void Spawn();

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
    QImage image2;
    QRect rect;
    int dx;
    // Constantes que representan la posición original de la barra
    static const int INITIAL_X = 50;
    static const int INITIAL_Y = 360;
    static const int OUT_X = -200;
    static const int OUT_Y = -360;

};
