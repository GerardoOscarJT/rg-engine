#ifndef Figure3DH
#define Figure3DH
#include "PV3D.h"

class Figure3D {
public:
        Figure3D();
        ~Figure3D();

        virtual void Repaint() = 0;
        virtual String getName() = 0;

        PV3D *translation;
        PV3D *rotation;


private:


};



#endif
