#ifndef Vertex3DH
#define Vertex3DH
#include "PV3D.h"
#include "Color3D.h"

class Vertex3D : public PV3D {
public:
        Vertex3D();
        Vertex3D(double, double, double);
        ~Vertex3D();

        Color3D *color;
        int n;


private:



};




#endif
