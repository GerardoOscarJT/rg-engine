//---------------------------------------------------------------------------

#ifndef Cylinder3DH
#define Cylinder3DH
//---------------------------------------------------------------------------

#include <math.h>
#include "Mesh3D.h"

class Cylinder3D : public Mesh3D{

public:
        double height;
        double rad_top;
        double rad_bottom;

        Cylinder3D();
        Cylinder3D(double, double, double);
        void RecalculateMesh();

private:

};

#endif
