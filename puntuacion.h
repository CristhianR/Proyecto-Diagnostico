#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <QGraphicsTextItem>

class Puntaje: public QGraphicsTextItem{
public:

    Puntaje(QGraphicsItem * parent = 0);

    void aumentar();
    int getPuntaje();
private:

    int puntaje;
};

#endif // PUNTUACION_H
