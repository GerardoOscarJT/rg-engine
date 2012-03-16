//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cylinder3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Cylinder3D::Cylinder3D(double _height, double _rad_top, double _rad_bottom) {
        height = _height;
        rad_top = _rad_top;
        rad_bottom = _rad_bottom;
}

void Cylinder3D::RecalculateMesh() {
        clearLists();

        double pi = 4*atan(1);
        double r = 20;
        double ang;
        //Para la prueba, que n = 5 (pentágono)

        double inc_ang = 2*pi/5;
        for(int i = 0; i < 5; i++) {
                ang = i*inc_ang;
                Vertex3D* v = new Vertex3D(r*cos(ang), r*sin(ang),0);
                Vertex3D* vsup = new Vertex3D(r*cos(ang), r*sin(ang),100); //altura (coord. z = 100)
                vertices->push_back(v);
                vertices->push_back(vsup);
        }

        list<Vertex3D*>::iterator it_v;
        Vertex3D* v3d;
        Vertex3D* vect[4];
        Vertex3D* aux[2]; // me guardo los 2 primeros para que sea más fácil
        bool guarda = true;
        int i = 0;
        for(it_v = vertices->begin(); it_v != vertices->end(); it_v++) {
                vect[i] = *it_v;

                if(guarda && (i < 2)) {
                        aux[i] = *it_v;
                }
                else guarda = false; //Que guarrada

                if(i == 3) {
                        Face3D * f = new Face3D();
                        faces->push_back(f);
                        f->vertices->push_back(vect[0]);
                        f->vertices->push_back(vect[2]);
                        f->vertices->push_back(vect[3]);
                        f->vertices->push_back(vect[1]);
                        RecalculateNormals(*f);
                        //f->normal->x;
                        //f->normal->x;
                        //f->normal->x;
                        vect[0] = vect[2];
                        vect[1] = vect[3];
                        i = 2;
                }
                else {
                        i++;
                }
        }
        Face3D *f = new Face3D();
        faces->push_back(f);
        it_v--;
        f->vertices->push_back(*it_v);
        it_v--;
        f->vertices->push_back(*it_v);
        f->vertices->push_back(aux[0]);
        f->vertices->push_back(aux[1]);
        
}


