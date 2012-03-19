//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cylinder3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//Y AQUI UNA DE CILINDROS!

Cylinder3D::Cylinder3D(double _height, double _rad_top, double _rad_bottom, bool _top, bool _bottom) {
        height = _height;
        rad_top = _rad_top;
        rad_bottom = _rad_bottom;
        top = _top;
        bottom = _bottom;
}

void Cylinder3D::RecalculateMesh() {
        clearLists();

        double pi = 4*atan(1);
        double ang;

        double inc_ang = 2*pi/NUM_LADOS;
        for(int i = 0; i < NUM_LADOS; i++) {
                ang = i*inc_ang;
                Vertex3D* v = new Vertex3D(rad_bottom*cos(ang), rad_bottom*sin(ang),0);
                Vertex3D* vsup = new Vertex3D(rad_top*cos(ang), rad_top*sin(ang),height); //altura (coord. z = 100)
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
                else guarda = false; //Que guarrada, pero bueno, me guardo los 2 primeros

                if(i == 3) {
                        Face3D * f = new Face3D();
                        faces->push_back(f);
                        f->vertices->push_back(vect[0]);
                        f->vertices->push_back(vect[2]);
                        f->vertices->push_back(vect[3]);
                        f->vertices->push_back(vect[1]);
                        //RecalculateNormals();
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
        it_v--;
        f->vertices->push_back(*it_v);
        f->vertices->push_back(aux[0]);
        f->vertices->push_back(aux[1]);
        it_v++;
        f->vertices->push_back(*it_v);
        //RecalculateNormals();


        //Tengo mis reservas. Si no funciona, cambiar

        if(bottom) {
                Face3D* top_face = new Face3D();
                faces->push_back(top_face);
                list<Vertex3D*>::reverse_iterator rit_tf;
                Vertex3D* v3d;
                rit_tf = vertices->rbegin();
                rit_tf++;
                int i=0;
                for(; rit_tf != vertices->rend(); rit_tf++) {
                        v3d = *rit_tf;
                        if(i%2 == 0) {
                                top_face->vertices->push_back(v3d);
                        }
                        i++;
                }
                //RecalculateNormals();
        }



        if(top) {
                Face3D* top_face = new Face3D();
                faces->push_back(top_face);
                list<Vertex3D*>::iterator it_tf;
                Vertex3D* v3d;
                it_tf = vertices->begin();
                it_tf++;
                int i=0;
                for(; it_tf != vertices->end(); it_tf++) {
                        v3d = *it_tf;
                        if(i%2 == 0) {
                                top_face->vertices->push_back(v3d);
                        }
                        i++;
                }
                //RecalculateNormals();
        }

        RecalculateNormals();




        
}

AnsiString Cylinder3D::getName() {
        return "Cylinder";
}
