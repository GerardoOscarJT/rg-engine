#ifndef Epitrochoid3DH
#define Epitrochoid3DH

#include "Mesh3D.h"
#include "FrenetFrameEpitrochoid.h"
#include <list.h>



class Epitrochoid3D : public Mesh3D {

public:
        Epitrochoid3D();

        double a; //radio de la circunferencia directriz
        double b; //radio de la circunferencia generatriz
        double h; //distancia del punto P al centro de la circunferencia generatriz
        double r;
        int nP; //número de lados del polígono
        int nQ; //número de pasos para construir la epitrocoide

        void RecalculateMesh();

        // Le cambio el nombre:
        String getName();


        FrenetFrameEpitrochoid _frenet_frame;
                        
private:




};

#endif
