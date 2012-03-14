#include <vcl.h>
#pragma hdrstop
#include "Face3D.h"
#pragma package(smart_init)



Face3D::Face3D() {
        normal = new PV3D();
        color = NULL;
        vertices = new list<Vertex3D*>();
}


Face3D::~Face3D() {
        delete normal;
        delete vertices;
        if (color != NULL)
                delete color;
}

