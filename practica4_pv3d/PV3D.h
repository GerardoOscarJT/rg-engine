
#ifndef PV3DH
#define PV3DH

#include <math.h>

class PV3D {

public:
        double x;
        double y;
        double z;
        int t;

        PV3D(double, double, double);
        PV3D(double, double, double, int);
        double len();
        void normalize();
        PV3D operator+(const PV3D &v);


/*        double cx;
        double cy;
        double cz;
        int tipo;

        double length();
        void normalize();
        PV3D* add(PuntoVector3D*&);
        PV3D* sub(PuntoVector3D*&);
        PV3D* scalarMult(double d);
        double dotProduct(PuntoVector3D*&);
        PV3D* crossProduct(PuntoVector3D*&);
        */

private:

};


#endif




