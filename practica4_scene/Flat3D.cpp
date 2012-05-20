#include <vcl.h>
#pragma hdrstop

#include "Flat3D.h"
#pragma package(smart_init)



Flat3D::Flat3D() {

}


Flat3D::~Flat3D() {

}


void Flat3D::RecalculateMesh() {
        clearLists();

        Vertex3D * v1 = new Vertex3D(0,0,0); vertices->push_back(v1);
        Vertex3D * v2 = new Vertex3D(x,0,0); vertices->push_back(v1);
        Vertex3D * v3 = new Vertex3D(x,y,0); vertices->push_back(v1);
        Vertex3D * v4 = new Vertex3D(0,y,0); vertices->push_back(v1);

        Face3D *f = new Face3D(); faces->push_back(f);
        f->normal->z = 0;
        f->normal->z = 0;
        f->normal->z = 1;
        f->normal->z = 0;
        f->vertices->push_back(v1);
        f->vertices->push_back(v2);
        f->vertices->push_back(v3);
        f->vertices->push_back(v4);

}


AnsiString Flat3D::getName() {
        return "Flat";
}

