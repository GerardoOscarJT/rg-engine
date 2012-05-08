#ifndef Disk3DH
#define Disk3DH

#include "Mesh3D.h"

class Disk3D : public Mesh3D {

public:
        double innerRadius;
        double outerRadius;
        int nSlices;
        int nRings;

        Disk3D(double, double, int, int);
        ~Disk3D();

        void RecalculateMesh();
        AnsiString getName();


};

#endif
