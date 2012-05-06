#include <vcl.h>
#pragma hdrstop
#include "Vertex3D.h"
#pragma package(smart_init)



Vertex3D::Vertex3D() {
        color = NULL;
}

Vertex3D::Vertex3D(double X, double Y, double Z) : PV3D(X,Y,Z) {
        color = NULL;
}


Vertex3D::~Vertex3D() {
        if (color != NULL)
                delete color;
}
