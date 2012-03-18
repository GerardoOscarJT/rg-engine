#include <vcl.h>
#pragma hdrstop
#include "Box3D.h"
#pragma package(smart_init)


/*
Box3D::Box3D() : Mesh3D() {

}
*/


void Box3D::RecalculateMesh() {
        clearLists();

        Vertex3D * v1 = new Vertex3D(x,0,z); vertices->push_back(v1);
        Vertex3D * v2 = new Vertex3D(x,y,z); vertices->push_back(v2);
        Vertex3D * v3 = new Vertex3D(0,y,z); vertices->push_back(v3);
        Vertex3D * v4 = new Vertex3D(0,0,z); vertices->push_back(v4);
        Vertex3D * v5 = new Vertex3D(x,0,0); vertices->push_back(v5);
        Vertex3D * v6 = new Vertex3D(x,y,0); vertices->push_back(v6);
        Vertex3D * v7 = new Vertex3D(0,y,0); vertices->push_back(v7);
        Vertex3D * v8 = new Vertex3D(0,0,0); vertices->push_back(v8);

        Face3D * f1 = new Face3D(); faces->push_back(f1);
                f1->normal->x = 1;
                f1->vertices->push_back(v5);
                f1->vertices->push_back(v6);
                f1->vertices->push_back(v2);
                f1->vertices->push_back(v1);
        Face3D * f2 = new Face3D(); faces->push_back(f2);
                f2->normal->y = 1;
                f2->vertices->push_back(v6);
                f2->vertices->push_back(v7);
                f2->vertices->push_back(v3);
                f2->vertices->push_back(v2);
        Face3D * f3 = new Face3D(); faces->push_back(f3);
                f3->normal->x = -1;
                f3->vertices->push_back(v3);
                f3->vertices->push_back(v7);
                f3->vertices->push_back(v8);
                f3->vertices->push_back(v4);
        Face3D * f4 = new Face3D(); faces->push_back(f4);
                f4->normal->y = -1;
                f4->vertices->push_back(v8);
                f4->vertices->push_back(v5);
                f4->vertices->push_back(v1);
                f4->vertices->push_back(v4);
        Face3D * f5 = new Face3D(); faces->push_back(f5);
                f5->normal->z = 1;
                f5->vertices->push_back(v1);
                f5->vertices->push_back(v2);
                f5->vertices->push_back(v3);
                f5->vertices->push_back(v4);
        Face3D * f6 = new Face3D(); faces->push_back(f6);
                f6->normal->z = -1;
                f6->vertices->push_back(v8);
                f6->vertices->push_back(v7);
                f6->vertices->push_back(v6);
                f6->vertices->push_back(v5);

}

AnsiString Box3D::getName() {
        return "Box";
}
