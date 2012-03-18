#ifndef Box3DH
#define Box3DH
#include "Mesh3D.h"

class Box3D : public Mesh3D {
public:

/*
        Box3D();
        ~Box3D();
*/        



        double x;
        double y;
        double z;

        void RecalculateMesh();

        AnsiString getName();



        /** OPCIONAL
        int x_div;
        int y_div;
        int z_div;
         **/
private:



};

#endif
