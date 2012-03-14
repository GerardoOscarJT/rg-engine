#ifndef Camera3DH
#define Camera3DH

#include "PV3D.h"

class Camera3D {
public:
        Camera3D();
        ~Camera3D();

        PV3D* look;
        PV3D* eye;
        PV3D* up;


        bool perspective;
        AnsiString name;

private:


};


#endif
