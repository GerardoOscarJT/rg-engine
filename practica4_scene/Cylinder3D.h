//---------------------------------------------------------------------------

#ifndef Cylinder3DH
#define Cylinder3DH
//---------------------------------------------------------------------------

#include <math.h>
#include "Mesh3D.h"

static const int NUM_LADOS = 20;

class Cylinder3D : public Mesh3D{

//YUJUUU, CILINDROS!!

public:
        double height;
        double rad_top;
        double rad_bottom;
        bool top;
        bool bottom;

        Cylinder3D();
        Cylinder3D(double _height, double _rad_top, double _rad_bottom, bool _top, bool _bottom);
        void RecalculateMesh();

        AnsiString getName();

private:

};

#endif
