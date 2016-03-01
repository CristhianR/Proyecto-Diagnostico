#include "puntuacion.h"
#include <QFont>


Puntaje::Puntaje(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Se inicializa el puntaje en cero.
    puntaje = 0;

    // dibuja el texto
    setPlainText(QString("Puntaje: ") + QString::number(puntaje)); // Puntaje = 0;
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

void Puntaje::aumentar(){
    puntaje++;
}

int Puntaje::getPuntaje(){
    return puntaje;
}
