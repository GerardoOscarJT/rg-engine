#include <vcl.h>
#pragma hdrstop
#include "Camera3D.h"
#pragma package(smart_init)


Camera3D::Camera3D() {
        look = new PV3D(0,0,-1);
        eye = new PV3D(0,0,0);
        up = new PV3D(0,0,1,0); // vector

        perspective = false;
}

Camera3D::~Camera3D() {
        delete look;
        delete eye;
        delete up;
}


