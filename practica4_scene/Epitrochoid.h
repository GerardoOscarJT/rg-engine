#ifndef EpitrochoidH
#define EpitrochoidH

#include "FrenetFrameEpitrochoid.h"


class Epitrochoid {

public:
        double a; //radio de la circunferencia directriz
        double b; //radio de la circunferencia generatriz
        double h; //distancia del punto P al centro de la circunferencia generatriz
        int nP; //número de lados del polígono
        int nQ; //número de pasos para construir la epitrocoide


private:
        FrenetFrameEpitrochoid _frenet_frame;


};


#endif
