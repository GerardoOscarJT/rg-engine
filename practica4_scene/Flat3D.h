#ifndef Flat3DH
#define Flat3DH
#include "Mesh3D.h"


class Flat3D:public Mesh3D {
public:
        Flat3D();
        ~Flat3D();
        void RecalculateMesh();
        AnsiString getName();

        double x;
        double y;

private:


};







#endif
