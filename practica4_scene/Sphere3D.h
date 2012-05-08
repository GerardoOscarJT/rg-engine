#ifndef Sphere3DH
#define Sphere3DH

#include "Revolution3D.h"

class Sphere3D : public Mesh3D {

public:
        double radius;
        int nParallels;
        int nMeridians;

        Sphere3D();
        Sphere3D(double, int, int);
        ~Sphere3D();

        list<PV3D*> *points;
        int n;

        void RecalculateMesh();

        AnsiString getName();

};

#endif
