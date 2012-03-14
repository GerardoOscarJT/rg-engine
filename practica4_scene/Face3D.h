#ifndef Face3DH
#define Face3DH
#include "Vertex3D.h"
#include <list.h>

class Face3D {
public:
        Face3D();
        ~Face3D();

        PV3D *normal;
        Color3D *color;
        list<Vertex3D*>* vertices;




private:


};





#endif
